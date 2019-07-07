#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <errno.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/epoll.h>
#include <fcntl.h>
#include <sys/resource.h>
#include <iostream>

using namespace std;

#define MAXEPOLL 10000
#define MAXLINE 1024
#define PORT 6000
#define MAXBACK 1000

//设置非阻塞
int setnonblocking(int fd)
{
    if (fcntl(fd, F_SETFL, fcntl(fd, F_GETFD, 0) | O_NONBLOCK) == -1)
    {
        printf("Set blocking error : %d\n", errno);
        return -1;
    }
    return 0;
}

int main(int argc, char **argv)
{
    int listen_fd;
    int conn_fd;
    int epoll_fd;
    int nread;
    int cur_fds;  //!> 当前已经存在的数量
    int wait_fds; //!> epoll_wait 的返回值
    int i;
    struct sockaddr_in servaddr;
    struct sockaddr_in cliaddr;
    struct epoll_event ev;
    struct epoll_event evs[MAXEPOLL];
    struct rlimit rlt; //!> 设置连接数所需
    char buf[MAXLINE];
    socklen_t len = sizeof(struct sockaddr_in);

    //设置每个进程允许打开的最大文件数
    //每个主机是不一样的哦，一般服务器应该很大吧！
    rlt.rlim_max = rlt.rlim_cur = MAXEPOLL;
    if (setrlimit(RLIMIT_NOFILE, &rlt) == -1)
    {
        printf("Setrlimit Error : %d\n", errno);
        exit(EXIT_FAILURE);
    }

    //!> server 套接口
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(PORT);

    //建立套接字
    if ((listen_fd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
    {
        printf("Socket Error...%d\n", errno);
        exit(EXIT_FAILURE);
    }

    //设置非阻塞模式
    if (setnonblocking(listen_fd) == -1)
    {
        printf("Setnonblocking Error : %d\n", errno);
        exit(EXIT_FAILURE);
    }

    //绑定
    if (bind(listen_fd, (struct sockaddr *)&servaddr, sizeof(struct sockaddr)) == -1)
    {
        printf("Bind Error : %d\n", errno);
        exit(EXIT_FAILURE);
    }

    //监听
    if (listen(listen_fd, MAXBACK) == -1)
    {
        printf("Listen Error : %d\n", errno);
        exit(EXIT_FAILURE);
    }

    //创建epoll
    epoll_fd = epoll_create(MAXEPOLL); //!> create
    ev.events = EPOLLIN | EPOLLET;     //!> accept Read!
    ev.data.fd = listen_fd;            //!> 将listen_fd 加入
    if (epoll_ctl(epoll_fd, EPOLL_CTL_ADD, listen_fd, &ev) < 0)
    {
        printf("Epoll Error : %d\n", errno);
        exit(EXIT_FAILURE);
    }
    cur_fds = 1;

    while (1)
    {
        if ((wait_fds = epoll_wait(epoll_fd, evs, cur_fds, -1)) == -1)
        {
            printf("Epoll Wait Error : %d\n", errno);
            exit(EXIT_FAILURE);
        }

        for (i = 0; i < wait_fds; i++)
        {
            // 处理新接入的accept
            if (evs[i].data.fd == listen_fd && cur_fds < MAXEPOLL)
            {
                cout << "debug, evs[" << i << "] events " << ev.events << " EPOLLIN : " << EPOLLIN << endl;

                if ((conn_fd = accept(listen_fd, (struct sockaddr *)&cliaddr, &len)) == -1)
                {
                    printf("Accept Error : %d\n", errno);
                    exit(EXIT_FAILURE);
                }
                printf("Server get from client !\n" /*,  inet_ntoa(cliaddr.sin_addr), cliaddr.sin_port */);
                ev.events = EPOLLIN | EPOLLET; //!> accept Read!
                ev.data.fd = conn_fd;          //!> 将conn_fd 加入
                if (epoll_ctl(epoll_fd, EPOLL_CTL_ADD, conn_fd, &ev) < 0)
                {
                    printf("Epoll Error : %d\n", errno);
                    exit(EXIT_FAILURE);
                }
                ++cur_fds;
                continue;
            }
            //!> 下面处理数据

            cout << "deug read, evs[" << i << "] events " << ev.events << " EPOLLIN : " << EPOLLIN << endl;
            nread = read(evs[i].data.fd, buf, sizeof(buf));
            if (nread <= 0) //!> 结束后者出错
            {
                close(evs[i].data.fd);
                epoll_ctl(epoll_fd, EPOLL_CTL_DEL, evs[i].data.fd, &ev); //!> 删除计入的fd
                --cur_fds;                                               //!> 减少一个呗！
                continue;
            }
            write(evs[i].data.fd, buf, nread); //!> 回写
        }
    }

    close(listen_fd);
    return 0;
}
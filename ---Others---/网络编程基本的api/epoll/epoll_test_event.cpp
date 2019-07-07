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
#include <arpa/inet.h>

using namespace std;

#define IPADDRESS "127.0.0.1"
#define PORT 6000
#define MAXSIZE 1024
#define LISTENQ 5
#define FDSIZE 1000
#define EPOLLEVENTS 100

#define MAXLINE 1024
char buf[MAXLINE];

static void handle_accpet(int epollfd, int listenfd);
static void do_read(int epollfd, int fd, char *buf);
static void do_write(int epollfd, int fd, char *buf);
static void delete_event(int epollfd, int fd, int state);
static void modify_event(int epollfd, int fd, int state);

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

//事件处理函数
static void handle_events(int epollfd, struct epoll_event *events, int num, int listenfd, char *buf)
{
    int i;
    int fd;
    //进行遍历;这里只要遍历已经准备好的io事件。num并不是当初epoll_create时的FDSIZE。

    cout << "[debug] num : " << num << "  beign for" << endl;
    for (i = 0; i < num; i++)
    {
        fd = events[i].data.fd;
        //根据描述符的类型和事件类型进行处理
        if ((fd == listenfd) && (events[i].events & EPOLLIN))
        {
            handle_accpet(epollfd, listenfd);
        }
        else if (events[i].events & EPOLLIN)
        {
            // 找do_read函数中，读到的数据写到buff上面
            do_read(epollfd, fd, buf);
        }
        else if (events[i].events & EPOLLOUT)
        {
            cout << "[debug] write" << endl;
            do_write(epollfd, fd, buf);
        }
    }
    cout << "[debug] end for" << endl;
    cout << endl;
}

//添加事件
static void add_event(int epollfd, int fd, int state)
{
    struct epoll_event ev;
    ev.events = state;
    ev.data.fd = fd;
    epoll_ctl(epollfd, EPOLL_CTL_ADD, fd, &ev);
}

//处理接收到的连接
static void handle_accpet(int epollfd, int listenfd)
{
    int clifd;
    struct sockaddr_in cliaddr;
    socklen_t cliaddrlen;
    clifd = accept(listenfd, (struct sockaddr *)&cliaddr, &cliaddrlen);
    if (clifd == -1)
        perror("accpet error:");
    else
    {
        printf("accept a new client: %s:%d\n", inet_ntoa(cliaddr.sin_addr), cliaddr.sin_port); //添加一个客户描述符和事件
        add_event(epollfd, clifd, EPOLLIN);
    }
}

//读处理
static void do_read(int epollfd, int fd, char *buf)
{
    int nread;
    // read数据到buf上面
    nread = read(fd, buf, MAXSIZE);
    if (nread == -1)
    {
        perror("read error:");
        close(fd);                          //记住close fd
        delete_event(epollfd, fd, EPOLLIN); //删除监听
    }
    else if (nread == 0)
    {
        fprintf(stderr, "client close.\n");
        close(fd);                          //记住close fd
        delete_event(epollfd, fd, EPOLLIN); //删除监听
    }
    else
    {
        printf("[fd %d] read message is : %s", fd, buf);
        //修改描述符对应的事件，由读改为写
        modify_event(epollfd, fd, EPOLLOUT);
    }
}

//写处理
static void do_write(int epollfd, int fd, char *buf)
{
    int nwrite;
    nwrite = write(fd, buf, strlen(buf));
    if (nwrite == -1)
    {
        perror("write error:");
        close(fd);                           //记住close fd
        delete_event(epollfd, fd, EPOLLOUT); //删除监听
    }
    else
    {
        //修改描述符对应的事件，由写改为读
        modify_event(epollfd, fd, EPOLLIN);
    }
    memset(buf, 0, MAXSIZE);
}

//删除事件
static void delete_event(int epollfd, int fd, int state)
{
    struct epoll_event ev;
    ev.events = state;
    ev.data.fd = fd;
    epoll_ctl(epollfd, EPOLL_CTL_DEL, fd, &ev);
}

//修改事件
static void modify_event(int epollfd, int fd, int state)
{
    struct epoll_event ev;
    ev.events = state;
    ev.data.fd = fd;
    epoll_ctl(epollfd, EPOLL_CTL_MOD, fd, &ev);
}

int socket_bind(int port)
{
    int listen_fd;

    struct sockaddr_in servaddr;
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(port);

    //建立套接字
    if ((listen_fd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
    {
        printf("Socket Error...%d\n", errno);
        exit(EXIT_FAILURE);
    }

    //设置非阻塞模式
    // if (setnonblocking(listen_fd) == -1)
    // {
    //     printf("Setnonblocking Error : %d\n", errno);
    //     exit(EXIT_FAILURE);
    // }

    //绑定
    if (bind(listen_fd, (struct sockaddr *)&servaddr, sizeof(struct sockaddr)) == -1)
    {
        printf("Bind Error : %d\n", errno);
        exit(EXIT_FAILURE);
    }

    //监听
    if (listen(listen_fd, LISTENQ) == -1)
    {
        printf("Listen Error : %d\n", errno);
        exit(EXIT_FAILURE);
    }
    cout << "listen init" << endl;
    return listen_fd;
}

int main()
{
    cout << "run.." << endl;

    int listenfd = socket_bind(PORT);

    struct epoll_event events[EPOLLEVENTS];

    //创建一个描述符
    int epollfd = epoll_create(FDSIZE);

    //添加监听描述符事件
    add_event(epollfd, listenfd, EPOLLIN);

    //循环等待
    for (;;)
    {
        //该函数返回已经准备好的描述符事件数目
        int ret = epoll_wait(epollfd, events, EPOLLEVENTS, -1);
        //处理接收到的连接
        handle_events(epollfd, events, ret, listenfd, buf);
    }
}

// from https://segmentfault.com/a/1190000003063859
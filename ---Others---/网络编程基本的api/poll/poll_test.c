#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <poll.h>
 
#define MAX_FD_NUM 20
#define MAXLEN 1024
 
int main(int argc,char* argv[])
{
    printf("server start up\n");
 
    if(argc <= 2)
    {
        printf("usage:%s ip port\n",basename(argv[0]));
        return 1;
    }
 
    //IP地址
    const char* ip = argv[1];
    //端口号
    int port = atoi(argv[2]);
    //内核监听队列的最大长度（完全连接的socket）
    //int backlog = atoi(argv[3]);
 
    //创建socket	(TIP/IP协议族，流式socket)
    int server_sockfd = socket(PF_INET,SOCK_STREAM,0);
 
    //TCP/IP协议族的socket地址结构体
    struct sockaddr_in server_addr;
    bzero(&server_addr,sizeof(server_addr));
    server_addr.sin_family = AF_INET;			//TCP/IPv4的地址族
    inet_pton(AF_INET,ip,&server_addr.sin_addr);		//将IP地址字符串转换为二进制的整数并赋给addr.sin_server_addr
    server_addr.sin_port = htons(port);			//端口，host to net，将主机字节序（小端）转换为网络字节序（大端）
 
    //将文件描述符sock和socket地址关联，仅服务端需要，客户端自动绑定地址
    //注意需要强制转换为 struct sockaddr*
    int ret = bind(server_sockfd,(struct sockaddr*)&server_addr,sizeof(server_addr));
    assert(ret != -1);
 
    //监听
    ret = listen(server_sockfd,MAX_FD_NUM-1);
    assert(ret != -1);
 
    //等待客户端做些连接等相关工作
    sleep(3);
 
    //客户端地址信息
    struct sockaddr_in client_addr;
    socklen_t client_addr_len = sizeof(struct sockaddr_in);
 
    //poll fds
    struct pollfd pollfdArry[MAX_FD_NUM];
    for(int i=0;i<MAX_FD_NUM;++i)
    {
        pollfdArry[i].fd = -1;
    }
 
    //insert the server socket fd
    pollfdArry[0].fd = server_sockfd;
    pollfdArry[0].events = POLLIN;
 
    int cur_fd_num = 1;
    char buf[MAXLEN]={0};
 
    //
    while (1)
    {
        int nready = poll(pollfdArry,cur_fd_num,-1);
        // server socket fd
        // 接收到新的连接
        if(pollfdArry[0].revents & POLLIN)
        {
            if(cur_fd_num > MAX_FD_NUM)
            {
                printf("socket num to much\n");
            }
            else
            {
                //接受连接,并将被接受的远端sock地址信息保存在第二个参数中
                //只是从监听队列中取出连接，即使客户端已经断开网络连接也会accept成功
                int client_sockfd = accept(server_sockfd,(struct sockaddr*)&client_addr,&client_addr_len);
                if(client_sockfd < 0)
                {
                   perror("accept");
                }
                else
                {
                    //inet_ntoa(struct addr_in) 将IP地址转换为字符串并返回
                    printf("accept client_addr %s\n",inet_ntoa(client_addr.sin_addr));
                    for(int i=0;i<MAX_FD_NUM;++i)
                    {
                        if(pollfdArry[i].fd == -1)
                        {
                            pollfdArry[i].fd = client_sockfd;
                            pollfdArry[i].events = POLLIN;
                            cur_fd_num++;
                            break;
                        }
 
                    }
                }
            }
            if(--nready <= 0)
            {
                continue;
            }
        }
 
        // 判断socket上面有没有可读的事件 
        // 从pollfdArry里面去遍历一次去查找
        for(int i=0;i<MAX_FD_NUM;++i)
        {
            if(pollfdArry[i].fd < 0)
            {
                continue;
            }
 
            if(pollfdArry[i].revents & (POLLIN |POLLERR))
            {
                int n = recv(pollfdArry[i].fd,buf,MAXLEN,0);
                if(n < 0)
                {
                    if(ECONNRESET == errno)
                    {
                        close(pollfdArry[i].fd);
                        pollfdArry[i].fd = -1;
                        cur_fd_num--;
                    }
                    else
                    {
                        perror("recv");
                    }
                }
                else if(n == 0)
                {
                    close(pollfdArry[i].fd);
                    pollfdArry[i].fd = -1;
                    cur_fd_num--;
                }
                else
                {
                    printf("recived:%s\n",buf);
                }
 
            }
            if(--nready)
            {
                break;
            }
        }
    }
 
 
    //关闭连接，实际只是socket的引用-1,必须引用为0才会真正关闭
    for(int i=0;i<MAX_FD_NUM;++i)
    {
        if(pollfdArry[i].fd != -1)
        {
            close(pollfdArry[i].fd);
        }
    }
    return 0;
}
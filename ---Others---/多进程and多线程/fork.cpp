/*
熟悉多进程变成的api

如果父进程先执行完毕退出的话，那么子进程就是孤儿进程；
如果子进程先执行完毕推出的话，那么子进程就是僵尸进程；

可以更改父子进程里面的sleep时间，来调整他们执行完的先后顺序。
通过：
ps -aux | grep 进程号 #来查看他们的状态

比如查看一个僵尸进程
ps -aux | grep 'Z'
ps -aux | grep defunct
*/
#include <iostream>
#include <unistd.h>
#include <stdio.h>
using namespace std;

int main(){
    pid_t fpid;

    int count=0;

    fpid = fork();
    if(fpid==0){
        //child
        count=10;
        cout<<"child : "<<getpid()<<endl;
        sleep(1);
    }
    else if(fpid>0){
        //father
        sleep(3);
        count=200;
        cout<<"father: "<<getpid()<<endl;
    }
    else{
        //error
    }
    //父子进程都会执行下面的代码,
    //但是，如何父进程先执行完就推出了，子进程就执行不了了
    cout<<getpid()<< "  "<<count<<endl;
   
    return 0;
}
/*
熟悉wait函数

为了避免子进程成为僵尸进程，需要父进程wait回收子进程。
父进程执行wait的时候，就会卡在这里，等待子进程。

*/
#include <iostream>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h> //wait()
using namespace std;

int main(){
    pid_t fpid;

    int count=0;

    fpid = fork();
    if(fpid==0){
        //child
        count=10;
        cout<<"child : "<<getpid()<<endl;
        sleep(3);
    }
    else if(fpid>0){
        //father
        //sleep(3);
        count=200;
        cout<<"father: "<<getpid()<<endl;
        pid_t ret_pid = wait(NULL);  //父进程执行wait的时候，就会卡在这里，等待子进程。
        cout<<"回收的pid是"<<ret_pid<<endl;
    }
    else{
        //error
    }

    cout<<getpid()<< "  "<<count<<endl;
   
    return 0;
}
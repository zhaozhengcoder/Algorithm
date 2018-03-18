/*
熟悉多进程的api
这样有人问到的时候，更加从容 
*/

#include <iostream>
#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
using namespace std;

typedef struct{
    int val1;
    int val2;
} Stu;


//线程1执行的函数
void* th1(void * arg){
    sleep(1);
    cout<<"thread 1 : do somethind"<<endl;
}


//线程2执行的函数
void* th2(void * arg){
    sleep(1);
    Stu * s =(Stu * ) arg;
    cout<<"val1 : "<<s->val1<<" val2: "<<s->val2<<endl;
    cout<<"thread 2 : do somethind"<<endl;
}

int main(){
    pthread_t p1,p2; //创建线程id

    Stu s1={100,200};
    Stu * ps =&s1;
    cout<<ps->val1<<" "<<ps->val2<<endl;

    //创建线程p1 去执行 th1函数 (不带参数)
    if(pthread_create(&p1,NULL,th1,NULL)!=0){
        cout<<"thread create error"<<endl;
    }

    //创建线程p2 去执行 th2函数 (带参数)
    if(pthread_create(&p2,NULL,th2,(void *) ps)!=0){
         cout<<"thread create error"<<endl;
    }

    //调用pthread_join 函数的时候，主线程会阻塞在这个地方
    //等待对应的子线程结束，并且回收资源。
    pthread_join(p1,NULL); 
    pthread_join(p2,NULL);

    return 0;
}

//g++ thread.cpp -lpthread
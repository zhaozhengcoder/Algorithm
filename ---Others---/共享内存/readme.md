## 共享内存


这是共享内存的一个简单的例子，分别有两个文件，一个负责往共享内存里面写，一个负责读。

编译
```
gcc -o shm_wirte shm_write.c
gcc -o shm_read shm_read.c
```


查看(在linux下 可以通过ipcs 这个命令查看)
```
ipcs
```

***
关于共享内存的api

* shmget( key_t key , size_t size, int shmflg ) ;

    创建共享内存

    参数:

        key : 用户指定的共享内存的key （共享内存的读者就是通过这个key来找到写的人的）

        size ：共享内存的大小

        shmflg ：ＩＰＣ——ＣＲＥＡＴ，ＩＰＣ——ＥＸＣＬ 等权限组合
    
    返回值：

        如果成功，返回内核中共享内存的标识ID。如果失败，返回-1

* shmat ( int shmid , char * shmaddr , int shmflg)

    参数：

        shmid ： 共享内存的id

        shmaddr ： 映射到进程虚拟内存空间的地址，（一般为0，表示有操作系统来分配）

        shmflg : 如果shmaddr设置为0，那么shmflg也要设置为0

    返回值：

        如果成功，返回共享内存的映射到内存空间的地址；如果失败，则返回-1

    如果一块共享内存被多个程序共享，在每个程序内共享内存映射到的进程空间是不一样的。

* shmdt

    解除共享内存的映射

* shmctl

    删除共享内存


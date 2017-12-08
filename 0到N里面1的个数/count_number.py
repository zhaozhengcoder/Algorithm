# 暴力大法

#将数字转换成str，然后遍历一次
def count(str):
    count=0
    for i in str:
        if i=='1':
            count+=1
    return count

#每次取余数10，判断余数是不是1
def count2(num):
    count=0
    while(num>0):
        yushu=num%10
        shang=int(num/10)
        if(yushu==1):
            count+=1
        num=shang
    return count


def count_number(num):
    count_number=0
    #遍历1到N所有的数字
    for i in range(1,num+1):
        #对于每一个数字，判断里面1的个数
        count_number+=count(str(i))
    return count_number

if __name__=="__main__":
    #print (count_number(12))
    print (count2(212113))
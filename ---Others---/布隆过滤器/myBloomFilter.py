import mmh3
import bitarray
import string
from random import Random

class BloomFilter:
    def __init__(self):
        self.bit_size=10000
        self.bit_array=bitarray.bitarray(self.bit_size)
        self.bit_array.setall(0)

    #使用多个hash函数计算分别的hash值
    def bloom_hash(self,uid):
        #定义几个随机数作为种子
        seed=[10,20,30,40,50]
        index=[]
        for item in seed:
            #注意　使用mmh3计算哈希的时候，计算得到的结果是一个数值，我们用这个数值表示对用的下标
            index.append( mmh3.hash(uid,item) %self.bit_size )
        return index

    def add(self,uid):
        index=self.bloom_hash(uid)
        for item in index:
            self.bit_array[item]=1
    
    def isInBitarray(self,uid):
        index=self.bloom_hash(uid)
        result=1
        for item in index:
            result = result and self.bit_array[item]
        return result


class Test:
    def __init__(self):
        self.uid_list=[]
        length=20
        for item in range(0,length):
            strlen=Random().randint(10,20)
            self.uid_list.append(self.random_str(strlen))
        
    def random_str(self,randomlength=10):
        str=''
        chars = 'AaBbCcDdEeFfGgHhIiJjKkLlMmNnOoPpQqRrSsTtUuVvWwXxYyZz0123456789'
        length = len(chars) - 1
        random = Random()
        for i in range(randomlength):
            str+=chars[random.randint(0, length)]
        return str

    def split(self):
        trainlen=int(len(self.uid_list)*0.7)
        train_list=self.uid_list[0:trainlen]
        test_list=self.uid_list[trainlen:len(self.uid_list)]
        return train_list,test_list

    def test(self,train_list,test_list):
        bloom=BloomFilter()
        for item in train_list:
            bloom.add(item)
        
        result1=[]
        for item in train_list:
            result1.append(bloom.isInBitarray(item))
        
        result2=[]
        for item in test_list:
            result2.append(bloom.isInBitarray(item))

        print (result1)
        print (result2)
        #print (bloom.bit_array)
        
if __name__=="__main__":
    """
    b=BloomFilter()
    #print (b.bit_array)
    b.add("udfadsf12312")
    #print (b.bit_array)
    """
    t=Test()
    train_list,test_list=t.split()
    t.test(train_list,test_list)




        


        



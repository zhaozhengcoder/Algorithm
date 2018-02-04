from random import Random

def base_10to62(val):
    res=[]
    base =62
    while (val!=0):
        yushu =val%base
        shang =val//base 
        val = shang 
        res.append(yushu)
    return res

def make_char_list():
    charlist = []
    for i in range(0,26):
        charlist.append(chr(ord('a')+i))
    for i in range(0,26):
        charlist.append(chr(ord('A')+i))
    for i in range(0,10):
        charlist.append(chr(ord('0')+i))
    return charlist

def parse_base64(res,charlist):
    str =''
    parse_res=[]
    for item in res:
        parse_res.append(charlist[item])
    return str.join(parse_res)

def random_str(randomlength=10):
    str=''
    chars = 'AaBbCcDdEeFfGgHhIiJjKkLlMmNnOoPpQqRrSsTtUuVvWwXxYyZz0123456789'
    length = len(chars) - 1
    random = Random()
    for i in range(randomlength):
        str+=chars[random.randint(0, length)]
    return str

def generate_test_url(num=1000):
    test_long_urls=[]
    for i in range(num):
        test_long_urls.append(baseurl+random_str())
    return test_long_urls


def build_long_to_short_dict(test_long_urls):
    test_long_urls = list(set(test_long_urls))  # 去重，因为url可能是重复的
    long_to_short_dict={}
    for index, ele in zip(range(len(test_long_urls)),test_long_urls):
        res = base_10to62(index)
        parse_res = parse_base64(res,charlist)
        long_to_short_dict[ele]=baseurl + parse_res
    return long_to_short_dict

charlist = make_char_list()
baseurl='www.tongji.edu.com/'

if __name__=="__main__":
    #生成1000条随机的长链接url 最为测试
    test_long_urls = generate_test_url()

    #建立映射字典
    long_to_short_dict = build_long_to_short_dict(test_long_urls)

    # test
    for item in test_long_urls:
        print (item," --> ",long_to_short_dict[item])
    

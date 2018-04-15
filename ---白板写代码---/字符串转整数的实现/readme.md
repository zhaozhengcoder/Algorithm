## 字符串转整数

1. 使用库函数来搞定
    ```
    //string to int 
    string str = "123";  //注意：stringstream 是支持负号的
    stringstream ss;
    int num;
    ss << str;
    ss >> num;
    cout << num << endl;
    ss.clear();
    
    //int to string 
    int n = 100;
    string str;
    stringstream ss;
    ss << n;
    ss >> str;
    cout << str << endl;
    ss.clear();
    ```

2. 不使用库函数的话
    ```
    int my_atoi(char * c) {
	    assert(*c >= '0' && *c <= '9');
	    int diff = (*c) - '0';
	    return diff + 0;
    }

    int string_to_int(string str) {
        int count = 0;
        int base = 10;
        int sum = 0;
        for (int i = str.size() - 1; i >= 0; i--) {
            char temp = str[i];
            int ret = my_atoi(&temp);
            sum += ret * pow(base, count);
            count++;
        }
        return sum;
    }

    string str = "123";
	cout<<string_to_int(str);
    ```


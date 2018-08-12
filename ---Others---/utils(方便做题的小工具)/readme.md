## 更好的做题的一些小工具代码

* c++ 里面没有split函数，写过python的时候用过split感觉无比的爽。但是c++里面居然没有。

    尤其是要处理这样的输入的时候，比如 1，2，3，4，5 。要把他们变成一个vector。好痛苦。于是自己写了一个split。
    ```
    #include <iostream>
    #include <algorithm>
    #include <vector>
    #include <string>
    using namespace std;


    vector<string> split(const string& src, const string& delim)
    {
        vector<string> dest;
        
        string str = src;
        string::size_type start = 0, index;
        string substr;

        index = str.find_first_of(delim, start);	//在str中查找(起始：start) delim的任意字符的第一次出现的位置
        while (index != string::npos)
        {
            substr = str.substr(start, index - start);
            dest.push_back(substr);
            start = str.find_first_not_of(delim, index);	//在str中查找(起始：index) 第一个不属于delim的字符出现的位置
            if (start == string::npos)
            {
                return dest;
            }
            index = str.find_first_of(delim, start);
        }

        substr = str.substr(start, str.size() - start);
        dest.push_back(substr);

        return dest;
    }


    //split 并且转换成 int 
    vector<int> split_and_to_int(const string& src, const string& delim)
    {
        vector<int> dest;

        string str = src;
        string::size_type start = 0, index;
        string substr;

        index = str.find_first_of(delim, start);	//在str中查找(起始：start) delim的任意字符的第一次出现的位置
        while (index != string::npos)
        {
            substr = str.substr(start, index - start);
            dest.push_back(stoi(substr));
            start = str.find_first_not_of(delim, index);	//在str中查找(起始：index) 第一个不属于delim的字符出现的位置
            if (start == string::npos)
            {
                return dest;
            }
            index = str.find_first_of(delim, start);
        }

        substr = str.substr(start, str.size() - start);
        dest.push_back(stoi(substr));

        return dest;
    }

    int main()
    {
        //demo1
        string str = "12 2 3 24";
        vector<string> dest1 = split(str, ",");

        //demo2 从输入里面分割逗号
        string str2;
        cin >> str2;
        vector<string> dest2 = split(str2, ",");


        //demo3 从输入里面分割空格（空格的分割需要cin.getline 来获取一行）
        string str3;
        cin.get();
        getline(cin, str3);   //当 getline(cin, str);前面的输入是cin>>ss;的话，那么此处str的值时空的，因为他会读取上一行的结束符。
        vector<string> dest3 = split(str3, " ");
        
        //demo4 
        string str4 = "12 3 4 5";
        vector<int> res = split_and_to_int(str4, " ");


        return 0;
    }
    ```

* 用vector生成一个链表,这个在测试自己代码的时候，可以方便的生成一个链表。
    ```
    struct ListNode 
    {
        int val;
        struct ListNode *next;
        ListNode(int x) :val(x), next(NULL) {}
    };

    //根据vector去创建一个链表
    ListNode * create_list_by_vector(vector<int> vi)
    {
        ListNode * head = new ListNode(vi[0]);
        ListNode * p = head;
        for (int i = 1; i < vi.size(); i++)
        {
            ListNode * node = new ListNode(vi[i]);
            p->next = node;
            p = p->next;
        }
        return head;
    }

    int main(void)
    {
        vector<int> vi = { 1,2,3,4,5 };
        ListNode * head = create_list_by_vector(vi);

        return 0;
    }
    ```
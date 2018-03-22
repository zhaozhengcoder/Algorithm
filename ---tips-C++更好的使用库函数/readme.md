## C++ 

* 处理输入

    1. 给出一个点的横纵坐标 x,y的输入，将它们变成结构体point里面的变量。
        ```
        struct point{
            int x;
            int y;
        };
        int main(int argc, char const *argv[])
        {
            int num;
            cin>>num;
            vector<point> vp;
            for(int i=0;i<num;i++){
                point p1;
                cin>>p1.x>>p1.y;
                vp.push_back(p1);
            }
            system("pause");
            return 0;
        }
        ```

* 重载comp函数，比较结构体的大小 
(比如：按照point结构体的x值的大小从小到大排列point对象)
    ```
    #include <algorithm>

    struct point{
        int x;
        int y;
    };

    //从小到大排序
    bool compare(point p1,point p2){
        return p1.x <p2.x;
    }

    int main(int argc, char const *argv[])
    {
        vector<point> vp;  //vp 里面存放这个3个point对象
        point p1;p1.x=200;p1.y=100;
        point p2;p2.x=100;p2.y=100;
        point p3;p3.x=300;p3.y=100;

        vp.push_back(p1);
            vp.push_back(p2);
            vp.push_back(p3);
            //给vp里面的point对象按照x的大小，从小到大排序
        sort(vp.begin(),vp.end(),compare);

    }
    ```


* String 处理
    
    反转
    ```
    #include <string>
    #include <algorithm>

    string str="abcd";
	//cout<<str<<endl;
	reverse(str.begin(),str.end());
	//cout<<str<<endl;     //reverse string
    ```

    提取子串
    ```
    string str="abcd";
	string substr = str.substr(1,3);
    ```

* list
    ```
    //遍历0~n
    for (auto iter = li.begin(); iter != li.end(); iter++) {
		cout << *iter << " ";
	}

    //遍历0~n-1
    auto iter2 = li.end();
	iter2--;
	for (auto iter = li.begin(); iter != iter2; iter++) {
		cout << *iter << " ";
	}

    //反向遍历n~0
    for (auto iter = li.rbegin(); iter != li.rend(); iter++) {
		cout << *iter << " ";
	}


    //反向遍历n~1
    auto iter3 = li.rend();
	iter3--;
	for (auto iter = li.rbegin(); iter != iter3; iter++) {
		cout << *iter << " ";
	}
    ```
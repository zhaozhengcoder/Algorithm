
C++11 类似于python的遍历容器的方式
```
string str = "abcd";
for (char c : str) {
    cout << c << endl;
}
```

初始化一个二维的vector
```
//初始化一个5*5，里面元素都是-1的数组
vector<int> vi(5, -1);
vector<vector<int>> dp(5, vi);
```
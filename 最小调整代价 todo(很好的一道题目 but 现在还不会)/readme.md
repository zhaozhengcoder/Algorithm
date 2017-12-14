## 最小调整代价
http://www.lintcode.com/zh-cn/problem/minimum-adjustment-cost/#


给一个整数数组，调整每个数的大小，使得相邻的两个数的差不大于一个给定的整数target，调整每个数的代价为调整前后的差的绝对值，求调整代价之和最小是多少。


样例 
对于数组[1, 4, 2, 3]和target=1，最小的调整方案是调整为[2, 3, 2, 3]，调整代价之和是2。返回2。


leetcode ：Minimum Adjustment Cost


一道动归的题目：
可以用动归来做，也可以使用带缓存的递归来做。

but递归写出来超时，呜呜呜~~


### 教程
http://skills.frankge.me/getting-start-to-dynamic-programming-part-3-find-the-optimal-solution/

http://skills.frankge.me/getting-start-to-dynamic-programming-part-4-using-recursion-in-a-smart-way/

http://blog.csdn.net/wangyuquanliuli/article/details/45899311
## 带最小值操作的队列

假设有这样的一个有3个操作的队列：
1. enqueue(v) ： 将v加入队列里面
2. dequeue()  :  从队列的首部删除一个元素并返回此元素
3. maxelement() : 返回队列里面最大的元素

来自《编程之美》 第3.7章节


方法1：
调用maxelement 函数的时候，遍历一次当前队列的所有元素，返回一个最小的元素。

方法2：
如果要在线性时间的复杂度搞定，那么需要用两个栈来实现队列，然后栈的最小值会比较容易的求解出来，so，这个问题就有解了。

参考：http://chestnutheng.cn/2015/10/26/max-stack-and-max-queue/

### 两个栈实现队列
参考： 
http://www.lintcode.com/en/problem/implement-queue-by-two-stacks/

实现功能：
用两个栈模拟实现一个队列的push(element)，pop()和top()操作；

解题思路

假设有两个栈stack1, stack2

队列push(element)实现：始终用stack1入栈实现

队列pop()和top()实现：
1. 由于stack1依次出栈并压入stack2中，恰好保证stack2中顺序与模拟队列顺序一致，始终保证stack2栈顶元素为模拟队列队首

2. 当stack2为空时，stack1中全部元素依次出栈并入栈stack2，最后直接弹出栈顶或者只返回栈顶数据；
3. 当stack2不空时，直接弹出栈顶或者只返回栈顶数据；

### 对于维护一个最小值or最大值的栈 
这个问题会比较简单一点

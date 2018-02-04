#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <time.h>    
#include <stdio.h>  
#include <string>
#include <vector>
#include <set>
#include <sstream>
#include <stack>

using namespace std;

//这个lintcode 里面minstack的代码
class MinStack {
    stack<int> num;  
    stack<int> minnum;
public:
    MinStack() {
        // do initialization if necessary
    }

    void push(int number) {
        // write your code here
        num.push(number);
		//如果min栈为空或者是 min栈的栈顶元素大于 即将入栈的元素，然后将这个元素加入min栈
        if (minnum.size() == 0 || minnum.top() >= number) {  
            minnum.push(number);  
        } 
		//否则 将min栈顶元素 再次加入min栈
		//这样min栈和num栈的大小是一样的
        else {  
            minnum.push(minnum.top());  
        } 
    }

    int pop() {
        // write your code here
        if (minnum.size() > 0 && num.size() > 0) {  
            int k = num.top();  
            num.pop();  
            minnum.pop();  
            return k;  
        }  
    }

    int stackmin() {
        // write your code here
        return minnum.top();  
    }

	int top(){
		return num.top();
	}

	//如果为空的话，返回true
	bool empty(){
		return num.empty();
	}
};

//这是lintcode里面 用两个栈模拟队列的代码
class Queue {
public:
	MinStack stack1;
	MinStack stack2;

	Queue() {
		// do intialization if necessary
	}

	void push(int element) {
		// write your code here
		stack1.push(element);
	}

	int pop() {
		// write your code here
		//如果栈2不为空的话，那么
		if (stack2.empty() == 0) {
			int temp = stack2.top();
			stack2.pop();
			return temp;
		}

		//如果栈2为空，但是栈1不为空的话，那么
		if (stack2.empty() == 1 && stack1.empty() == 0) {
			while (stack1.empty() == 0) {
				stack2.push(stack1.top());
				stack1.pop();
			}
			int temp = stack2.top();
			stack2.pop();
			return temp;
		}

	}

	int top() {
		// write your code here
		if (stack2.empty() == 0) {
			return stack2.top();
		}


		if (stack2.empty() == 1 && stack1.empty() == 0) {
			while (stack1.empty() == 0) {
				stack2.push(stack1.top());
				stack1.pop();
			}

			return stack2.top();
		}
	}

	int queuemin(){
		//从minstack里面找到最大值
		int min1=INT_MAX;
		if(stack1.empty()==0){
			min1=stack1.stackmin();
		}
		
		int min2=INT_MAX;
		if(stack2.empty()==0){
			min2=stack2.stackmin();
		}

		return min(min1,min2);

	}
};



int main(int argc, char const *argv[])
{
	Queue queue;


	queue.push(3);
	queue.push(2);
	queue.push(1);
	cout<<" min "<<queue.queuemin()<<endl;
	cout<<queue.pop()<<endl;
	queue.push(5);
	cout<<queue.pop()<<endl;
	cout<<" min "<<queue.queuemin()<<endl;

	cout<<queue.pop()<<endl;
	queue.push(2);
	cout<<" min "<<queue.queuemin()<<endl;
	cout<<queue.pop()<<endl;
	cout<<queue.pop()<<endl;



	return 0;
}
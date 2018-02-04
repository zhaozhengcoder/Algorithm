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

    int min() {
        // write your code here
        return minnum.top();  
    }
};



int main(){ 
	MinStack s;
	s.push(1);
	cout<<s.pop()<<endl;
	s.push(2);
	s.push(3);
	cout<<s.min()<<endl;
	s.push(1);
	cout<<s.min()<<endl;



	system("pause");
	return 0;
}
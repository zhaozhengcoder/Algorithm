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


class Solution {
public:
    /*
     * @param A: A list of integers
     * @return: A boolean
     */

	/*
	思路：
	从后向前遍历数组，对于当前的index，有两种可能:
		1. 如果这个点可以直接跳到最后一个位置，那么dp[index]=1
		2. 如果这个点不可以直接跳到最后一个位置：
			那么判断这个点是否可以跳到[index+1,最后]的dp为1的点，如果可以跳到，那么这个点的dp[index]=1
	*/
    bool canJump(vector<int> &A) {
        // write your code here
		vector<int> dp(A.size(),-1);
		if(A.size()==1){
			return true;
		}

		for(int i=A.size()-2;i>=0;i--){
			//如果当前的结点可以直接到达最后面的结点，那么dp[i]=1
			if(A[i]+i>=A.size()-1){
				dp[i]=1;
				continue;
			}
			//对于i点，遍历它能跳到的所有的点，k表示能跳跃的范围
			for(int k=1;k<=A[i];k++){
				//如果调到了这里，判断能否通过这个点，调到终点，如果这个点的dp==1，那么表示可以从从这个点调到终点
				int tmp=dp[i+k];
				if(tmp==1){
					dp[i]=1;
					break;
				}
			}
		}
		if(dp[0]==1){
			return true;
		}
		return false;
    
	}
};

int main(int argc, char const *argv[])
{
	//int arr[]= {2,3,1,1,4};
	//int arr[]= {0,8,2,0,9};
	//int arr[]={4,3,4,10,0, 7,5,5,1,0, 5,7,7,9,6, 7,3,10,8,2};  //daan : true
	int arr[]={1,0};  //true
	Solution s;
	const int len=2;
	vector<int> vi(arr,arr+len);
	s.canJump(vi);
	//
	return 0;
}
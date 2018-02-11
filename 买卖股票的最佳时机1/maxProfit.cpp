#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <time.h>    
#include <stdio.h>  
#include <string>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    /**
     * @param prices: Given an integer array
     * @return: Maximum profit
     */
	//贪心算法
	//维护两个数据结构
	//一个记录目前为止的最小值，一个记录目前的最大profit
    int maxProfit(vector<int> &prices) {
        // write your code here
		if(prices.size()<2)
			return 0;
		//如果不买也不买，利润是0，所以，利润不可能为负数，最小为0
		int maxprofit=0;
		int minprices=prices[0];
		for(int i=1;i<prices.size();i++){
			//最大利润 等于 当前的记录的最大利润 和 当前价格减去目前已知的最低值
			maxprofit=max(maxprofit,prices[i]-minprices);
			minprices=min(minprices,prices[i]);
		}
		return maxprofit;
    }
};



int main(){ 
	Solution s;

	int arr[]={1,2};
	const int len=2;
	vector<int> vi(arr,arr+len);

	s.maxProfit(vi);

	system("pause");
	return 0;
}
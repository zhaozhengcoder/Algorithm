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
#include <unordered_set>

using namespace std;

class Solution {
public:
    /*
     * @param nums: An array of integers
     * @return: An integer
     */
    int maxProduct(vector<int> &nums) {
        // write your code here
		if(nums.size()==1){
			return nums[0];
		}
		int max_res=nums[0];
		int cur_max=nums[0];
		int cur_min=nums[0];  //因为乘法和加法的区别是，乘法可能会出现负负得正的情况，不仅要记录最大的，还需要记录最小的
		for(int i=1;i<nums.size();i++){
			int temp_max=cur_max;
			cur_max=max(max(nums[i],nums[i]*temp_max),cur_min*nums[i]);
			cur_min=min(min(nums[i],nums[i]*temp_max),cur_min*nums[i]);
			max_res=max(max_res,cur_max);
		}
		return max_res;
    }
};
int main(int argc, char const *argv[])
{
	vector<int> nums;
	nums.push_back(-4);
	nums.push_back(-3);
	nums.push_back(-2);

	Solution s;
	cout<<s.maxProduct(nums);
	

	return 0;
}
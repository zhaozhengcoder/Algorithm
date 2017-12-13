#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

class Solution {
public:
	/**
	* @param nums: A list of integers
	* @return: A integer indicate the sum of max subarray
	*/

	// 注意这种情况是，数组中至少存在一个正数的情况
	int maxSubArray(vector<int> nums) {
		int cur_max=nums[0];
		int max_res=nums[0];

		for(int i=1;i<nums.size();i++){
			//对于当前的元素，有两种情况，要比就是把它加在cur_max里面，要不就是他比cur_max更大
			//如果当前元素更大， 那么就意味着，cur_max 忘掉以前的数据，然后记录当前的值为cur_max
			cur_max=max(cur_max+nums[i],nums[i]);
			max_res=max(max_res,cur_max);
		}

		return max_res;
	}
};


int main(){
	int arr[10]={-2,2,-3,4,-1,2,1,-5,3};
	vector<int> vi(arr,arr+9);
	Solution s;
	cout<<s.maxSubArray(vi);

	system("pause");
	return 0;
}
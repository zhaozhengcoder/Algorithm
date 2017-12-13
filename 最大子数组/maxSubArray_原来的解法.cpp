
//这个是自己最早的解法，太复杂了，因为在遍历的同时，记录了最大子数组出现的begin和end位置，但是题目并没有要求求出来这个数值。
class Solution {
public:
	/**
	* @param nums: A list of integers
	* @return: A integer indicate the sum of max subarray
	*/

	// 注意这种情况是，数组中至少存在一个正数的情况
	int maxSubArray(vector<int> nums) {
		// write your code here
		int sum = 0;
		int max_sum = 0;
		int max_pos_begin = 0;
		int max_pos_end = 0;

		int begin = 0;
		int end = 0;
		int flag = 0;

		//考虑到全部都是负数的情况
		int neg_flag = 0;
		int max_neg = nums[0];
		int max_neg_index = 0;

		for (int i = 0; i < nums.size(); i++) {
			//flag 是一个标志，用来判断begin是否已经设置
			if (nums[i] > 0&&flag==0) {
				begin = i;
				flag = 1;
			}

			sum = sum + nums[i];

			if (sum < 0) {
				sum = 0;
				flag = 0;
			}

			if (sum > max_sum) {
				end = i;
				max_sum = sum;
				max_pos_begin = begin;
				max_pos_end = end;
			}

			if (nums[i] > 0) {
				//如果存在一个正数，neg_flag就设置为1
				neg_flag = 1;
			}
			else {
				if (nums[i] > max_neg) {
					max_neg = nums[i];
					max_neg_index = i;
				}
			}
		}

		if (neg_flag == 1) {
			return max_sum;
		}
		else {
			return max_neg;
		}
	
	}
};
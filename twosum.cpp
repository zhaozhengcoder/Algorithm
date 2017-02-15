/*
问题描述：
给一个整数数组，找到两个数使得他们的和等于一个给定的数 target。
你需要实现的函数twoSum需要返回这两个数的下标, 并且第一个下标小于第二个下标。注意这里下标的范围是 1 到 n，不是以 0 开头。

样例 
给出 numbers = [2, 7, 11, 15], target = 9, 返回 [1, 2].
连接： http://www.lintcode.com/zh-cn/problem/two-sum/
*/

/*
class Solution {
public:
    /*
     * @param numbers : An array of Integer
     * @param target : target = numbers[index1] + numbers[index2]
     * @return : [index1+1, index2+1] (index1 < index2)
     * 时间 复杂度 O(N^2)
     */
     /*
    vector<int> twoSum(vector<int> &nums, int target) {
        // write your code here
		vector<int> res;
		for(int i=0;i<nums.size();i++){
			for(int j=i+1;j<nums.size();j++){
				if(nums[i]+nums[j]==target){
					res.push_back(i+1);
					res.push_back(j+1);
					return res;
				}
			}
		}
		return res;
    }
};
*/

class Solution {
public:
	/*
	* @param numbers : An array of Integer
	* @param target : target = numbers[index1] + numbers[index2]
	* @return : [index1+1, index2+1] (index1 < index2)
	* 时间复杂度 O(N)
	* 空间复杂度 O(N)
  * 为了给女朋友示范一下map的用法，结果强行写了一波，结果submit的时候，被很多边缘条件卡着，效果也并不是很好
  */
	vector<int> twoSum(vector<int> &nums, int target) {
		// write your code here
		set<int> res;
		
		//构建一个map，实现O(1)的元素查找
		map<int, int > m;
		for (int i = 0; i < nums.size(); i++) {
			int key = nums[i];
			int val = i;
			m[key] = val;
		}

		for (int i = 0; i < nums.size(); i++) {
			int left = target - nums[i];
			auto it=m.find(left);

			if (it != m.end()) {
				int index = i + 1;
				int left_index = m[left] + 1;
				// 排除自身等于自身的情况，比如 这样 [1,0,-1], 0 
				if (index != left_index) {
					res.insert(index);
					res.insert(left_index);
				}
			}
		}

		vector<int> ret(res.begin(), res.end());
		return ret;
	}
};

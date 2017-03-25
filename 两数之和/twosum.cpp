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


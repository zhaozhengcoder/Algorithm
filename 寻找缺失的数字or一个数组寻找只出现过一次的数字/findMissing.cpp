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
#include <map>
#include <bitset>

using namespace std;

class Solution {
public:
    /*
     * @param nums: An array of integers
     * @return: An integer
     */
    int findMissing(vector<int> nums) {
        // write your code here
		int len=nums.size();
		string str(len+1,'0');

		for(int i=0;i<nums.size();i++){
			int index=nums[i];
			str[index]='1';
		}

		for(int i=0;i<str.size();i++){
			if(str[i]=='0'){
				return i;
			}
		}
    }

	int findMissing2(vector<int> nums) {
        // write your code here
		set<int> si;
		int len=nums.size()+1;
		for(int i=0;i<len;i++){
			si.insert(i);
		}

		for(int i=0;i<nums.size();i++){
			si.erase(nums[i]);
		}
		return *si.begin();
	}
};

int main(int argc, char const *argv[])
{
	int arr[]={9,8,7,6,2,0,1,5,4};
	const int len=9;

	vector<int> vi(arr,arr+len);
	Solution s;
	cout<<s.findMissing(vi);

	return 0;
}
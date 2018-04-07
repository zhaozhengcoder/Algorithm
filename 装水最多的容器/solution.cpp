#include<iostream>
#include<algorithm> 
#include<vector>
using namespace std;

class Solution2 {
public:
	int maxArea(vector<int> height) {
		if(height.size()==0){
	        return 0;
	    }
		int left = 0;
		int right = height.size() - 1;
		int maxares = (right - left) * min(height[left], height[right]);

		while (left < right) {
			if (height[left] < height[right]) {
				left++;
			}
			else {
				right--;
			}
			int ares = (right - left) * min(height[left], height[right]);
			maxares = max(maxares, ares);
		}
		return maxares;
	}
};

int main(int argc, char const *argv[])
{
	vector<int> vi = { 1,2,3 };
	Solution2 s;

	cout<<s.maxArea(vi);

	system("pause");
	return 0;
}
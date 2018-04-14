#include <iostream>
#include <set>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	vector<string> generateParenthesis(int n)
	{
		vector<string> result;
		string path = "";
		DFS(result, path, n, 0, 0);
		return result;
	}

	/*
	采用递归树的思想 ：
	left: 左括号的数量
	right：右括号数量
	
	n：括号的对数
	当left == n：表示左括号已经到达最大值了，只能添加右括号
	当left >= right: 表示左括号数量 小于 右括号数量，可以添加左括号 也可以添加右括号
	*/

	void DFS(vector<string> &result, string path, int n, int left, int right)
	{
		if (left == n)
		{
			result.push_back(path.append(n - right, ')'));
			return;
		}
		DFS(result, path + "(", n, left + 1, right);
		if (left > right)
			DFS(result, path + ")", n, left, right + 1);
	}
};



int main()
{
	Solution s;
	vector<string> result1 = s.generateParenthesis(2);
	vector<string> result2 = s.generateParenthesis(3);
	return 0;
}
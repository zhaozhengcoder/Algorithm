## 二叉树从根节点到子节点的路径

```
#include <iostream>
#include <math.h>
#include <set>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <algorithm>
#include <queue>
#include <algorithm>
using namespace std;

struct Node
{
	int val;
	Node * left;
	Node * right;
};
int get_index(vector<int> vi, int val)
{
	int index = 0;
	for (auto ele : vi)
	{
		if (ele == val)
		{
			return index;
		}
		index++;
	}
	return -1;
}
Node * solution(vector<int> pre, vector<int> mid)
{
	if (pre.size()==0||pre.size()!=mid.size())
	{
		return NULL;
	}
	else
	{
		Node * root = new Node();
		root->val = pre[0];
		root->left = NULL;
		root->right = NULL;

		int index = get_index(mid, pre[0]);

		vector<int> pre_left(pre.begin()+1, pre.begin()+index+1);
		vector<int> pre_right(pre.begin()+index+1, pre.end());
		vector<int> mid_left(mid.begin(),mid.begin()+index);
		vector<int> mid_right(mid.begin()+index+1, mid.end());



		root->left = solution(pre_left, mid_left);
		root->right = solution(pre_right, mid_right);
		return root;
	}
}
void print_vector(vector<int> path)
{
	for (auto ele : path)
	{
		cout << ele << "  ";
	}
	cout << endl;
}


// 寻找根节点到子节点的所有路径
// 这个是类似与前序遍历的递归
void solution2(Node * root,vector<int> & path)
{
	if (root != NULL)
	{
		//类似于前序遍历里面的visit操作
		path.push_back(root->val);
		if (root->left == NULL && root->right == NULL)
		{
			print_vector(path);
		}

		//递归
		solution2(root->left, path);
		solution2(root->right, path);

		//清楚递归条件
		path.pop_back();
	}
}

int main()
{
	//构造二叉树
	vector<int> pre = { 1,2,4,7,3,5,6,8 };
	vector<int> mid = { 4,7,2,1,5,3,8,6 };
	Node * root = solution(pre, mid);

	//打印根结点到子节点的路径
	vector<int> path;
	solution2(root,path);

	return 0;
}

```
# 通过前序和中序遍历构建二叉树

```

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

int main()
{
	vector<int> pre = { 1,2,4,7,3,5,6,8 };
	vector<int> mid = { 4,7,2,1,5,3,8,6 };

	Node * root = solution(pre, mid);

	return 0;
}
```
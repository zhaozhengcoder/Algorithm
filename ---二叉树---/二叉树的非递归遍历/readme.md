## 二叉树的 前序/中序/后序 遍历

```
#include <iostream>
#include <math.h>
#include <set>
#include <vector>
#include <string>
#include <stack>
#include <queue>
using namespace std;

struct BinaryTree {
	int vec;
	BinaryTree* left;
	BinaryTree* right;
	BinaryTree(int data)
		:vec(data), left(nullptr), right(nullptr) {
	}
	int flag;
};

void pre_travel(BinaryTree * root)
{
	stack<BinaryTree *> bt_stack;
	while (root != NULL || !bt_stack.empty())
	{
		while (root != NULL)
		{
			cout << root->vec << endl;
			bt_stack.push(root);
			root = root->left;
		}
		if (!bt_stack.empty())
		{
			root = bt_stack.top();
			bt_stack.pop();
			root = root->right;
		}
	}
}

void mid_travel(BinaryTree * root)
{
	stack<BinaryTree *> bt_stack;
	while (root != NULL || !bt_stack.empty())
	{
		while (root != NULL)
		{
			bt_stack.push(root);
			root = root->left;
		}
		if (!bt_stack.empty())
		{
			root = bt_stack.top();
			cout << root->vec << endl;
			bt_stack.pop();
			root = root->right;
		}
	}
}

/*
对于任一结点P，将其入栈，然后沿其左子树一直往下搜索，直到搜索到没有左孩子的结点，此时该结点出现在栈顶，
但是此时不能将其出栈并访问，因此其右孩子还为被访问。

所以接下来按照相同的规则对其右子树进行相同的处理，当访问完其右孩子时，该结点又出现在栈顶，
此时可以将其出栈并访问。这样就保证了正确的访问顺序。

可以看出，在这个过程中，每个结点都两次出现在栈顶，只有在第二次出现在栈顶时，才能访问它。
因此需要多设置一个变量标识该结点是否是第一次出现在栈顶。
*/
void post_travel(BinaryTree * root)
{
	stack<BinaryTree *> bt_stack;
	while (root != NULL || !bt_stack.empty())
	{
		while (root != NULL)
		{
			root->flag = 0;
			bt_stack.push(root);
			root = root->left;
		}

		if (!bt_stack.empty())
		{
			root = bt_stack.top();
			bt_stack.pop();

			//flag =0 说明右子树没有遍历
			if (root->flag == 0)
			{
				root->flag = 1;
				bt_stack.push(root);
				root = root->right;
			}
			else
			{
				cout << root->vec << endl;
				root = NULL;
			}
		}
	}
}

int main()
{
	BinaryTree* s_arr[6];
	s_arr[0] = new BinaryTree(0);
	s_arr[1] = new BinaryTree(1);
	s_arr[2] = new BinaryTree(2);
	s_arr[3] = new BinaryTree(3);
	s_arr[4] = new BinaryTree(4);
	s_arr[5] = new BinaryTree(5);
	s_arr[0]->left = s_arr[1];  //   0
	s_arr[0]->right = s_arr[2]; //  1  2
	s_arr[1]->left = s_arr[3];  // 3     5
	s_arr[3]->left = s_arr[4];  //4
	s_arr[2]->right = s_arr[5]; //所以层序遍历的结果为：0 1 2 3 5 4

	//travel(s_arr[0]);
	//travel_by_layer(s_arr[0]);

	//cout << iscomplete_tree(s_arr[0]) << endl;

	//pre_travel(s_arr[0]);
	//mid_travel(s_arr[0]);
	post_travel(s_arr[0]);

	return 0;
}
```
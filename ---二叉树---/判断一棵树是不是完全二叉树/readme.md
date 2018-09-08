## 判断一棵树是不是完全二叉树

```
#include <iostream>
#include <math.h>
#include <set>
#include <vector>
#include <string>
#include <queue>
using namespace std;

struct BinaryTree {
	int vec;
	BinaryTree* left;
	BinaryTree* right;
	BinaryTree(int data)
		:vec(data), left(nullptr), right(nullptr) {
	}
};

//层序遍历二叉树
void travel(BinaryTree * root)
{
	if (root != NULL)
	{
		queue<BinaryTree *> bt_queue;
		bt_queue.push(root);
		while (!bt_queue.empty())
		{
			BinaryTree * q = bt_queue.front();
			bt_queue.pop();
			cout << q->vec << endl;
			if (q->left != NULL)
			{
				bt_queue.push(q->left);
			}
			if (q->right != NULL)
			{
				bt_queue.push(q->right);
			}
		}
	}
}

//分层打印二叉树
void travel_by_layer(BinaryTree * root)
{
	if (root != NULL)
	{
		queue<BinaryTree *> bt_queue;
		bt_queue.push(root);
		while (!bt_queue.empty())
		{
			int size = bt_queue.size();
			for (int i = 0; i < size; i++)
			{
				BinaryTree * q = bt_queue.front();
				cout << q->vec << "  ";
				bt_queue.pop();

				if (q->left != NULL)
				{
					bt_queue.push(q->left);
				}
				if (q->right != NULL)
				{
					bt_queue.push(q->right);
				}
			}
			cout << endl;
		}
	}
}


/*
任意的一个二叉树，都可以补成一个满二叉树。这样中间就会有很多空洞。在广度优先遍历的时候，如果是满二叉树，或者完全二叉树，这些空洞是在广度优先的遍历的末尾，所以，但我们遍历到空洞的时候，整个二叉树就已经遍历完成了。而如果，是非完全二叉树，

我们遍历到空洞的时候，就会发现，空洞后面还有没有遍历到的值。这样，只要根据是否遍历到空洞，整个树的遍历是否结束来判断是否是完全的二叉树。
*/
bool iscomplete_tree(BinaryTree * root)
{	
	queue<BinaryTree *> bt_queue;
	if (root != NULL)
	{
		bt_queue.push(root);
		while (!bt_queue.empty())
		{
			BinaryTree * q = bt_queue.front();
			bt_queue.pop();
			if (q == NULL)
			{
				break;
			}
			bt_queue.push(q->left);
			bt_queue.push(q->right);
		}
	}

	while (!bt_queue.empty())
	{
		BinaryTree * q = bt_queue.front();
		bt_queue.pop();

		if (q != NULL)
		{
			return false;
		}
	}
	return true;
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

	cout << iscomplete_tree(s_arr[0]) << endl;

	return 0;
}
```
#include <iostream>
#include <vector>
using namespace std;

template<typename T>
struct TreeNode {
	T data;
	TreeNode<T> *left;
	TreeNode<T> * right;
};


template <typename T>
void visit(TreeNode<T> * node) {
	cout << node->data << "  ";
}

//非递归遍历二叉树 （中序）
//我觉得我自己写的要比晚上其他的答案要易于理解一点

/*
整体的思想就是用一个栈来保存上一级的结点，如果当前这一层遍历完了之后，那么栈pop上一级的结点，然后继续遍历
*/
template <typename T>
void BSTreeNoRecursive(TreeNode<T> * root) {
	vector<TreeNode<T> *> mystack;
	
	if (root == NULL) {
		return;
	}
	TreeNode<T> * p = root;
	while (true) {
		while (p!= NULL) {
			// 用一个vector来模拟栈
			mystack.push_back(p);
			visit(p);
			p = p->left;
		}
		if (p == NULL) {
			mystack.pop_back();
		}
		if (!mystack.empty()) {
			p=mystack[mystack.size() - 1]->right;
			mystack.pop_back();
			continue;
		}
		else {
			break;
		}
	}
}

int main() {
	//构建一颗二叉树
	TreeNode<int> *root = new TreeNode<int>();
	root->data = 10;
	root->left = NULL;
	root->right = NULL;

	TreeNode<int> *node_level1_1 = new TreeNode<int>();
	node_level1_1->data = 6;
	node_level1_1->left = NULL;
	node_level1_1->right = NULL;

	TreeNode<int> *node_level1_2 = new TreeNode<int>();
	node_level1_2->data = 14;
	node_level1_2->left = NULL;
	node_level1_2->right = NULL;


	TreeNode<int> *node_level2_1 = new TreeNode<int>();
	node_level2_1->data = 4;
	node_level2_1->left = NULL;
	node_level2_1->right = NULL;

	TreeNode<int> *node_level2_2 = new TreeNode<int>();
	node_level2_2->data = 8;
	node_level2_2->left = NULL;
	node_level2_2->right = NULL;


	TreeNode<int> *node_level2_3 = new TreeNode<int>();
	node_level2_3->data = 12;
	node_level2_3->left = NULL;
	node_level2_3->right = NULL;

	TreeNode<int> *node_level2_4 = new TreeNode<int>();
	node_level2_4->data = 16;
	node_level2_4->left = NULL;
	node_level2_4->right = NULL;

	root->left = node_level1_1;
	root->right = node_level1_2;

	node_level1_1->left = node_level2_1;
	node_level1_1->right = node_level2_2;

	node_level1_2->left = node_level2_3;
	node_level1_2->right = node_level2_4;

	//测试
	BSTreeNoRecursive(root);

	return 0;
}
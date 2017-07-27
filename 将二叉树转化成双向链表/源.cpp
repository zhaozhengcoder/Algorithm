#include <iostream>
using namespace std;


template<typename T>
struct TreeNode
{
	T data;
	TreeNode* pLChild;
	TreeNode* pRChild;
};

// 要求两个输出参数要初始化为NULL
// 基本的思路是：相当于把每一个visit的结点，插入到pListLast后面,这个新的list就是要的双向链表。pListHead是双向链表的头部，pListLast是双向链表的尾部。

//得到一个中序的链表
template<typename T>
void ConvertBSTree2List_MiddleOrder(TreeNode<T>* pTreeRoot/*树的根节点*/, TreeNode<T>*& pListHead/*双向链表的头指针*/, TreeNode<T>*& pListLast/*双向链表的尾指针*/)
{
	if (pTreeRoot == NULL)
	{
		return;
	}

	// 中序遍历左子树
	ConvertBSTree2List(pTreeRoot->pLChild, pListHead, pListLast);

	/* 处理当前节点，把节点链到双向链表尾部*/

	// 修改当前节点左指针，指向双向链表尾部
	pTreeRoot->pLChild = pListLast;
	if (pListLast)		// 非第一个节点
	{
		pListLast->pRChild = pTreeRoot;
	}
	else				// 第一个节点
	{
		pListHead = pTreeRoot;
	}
	pListLast = pTreeRoot;

	// 中序遍历右子树
	ConvertBSTree2List(pTreeRoot->pRChild, pListHead, pListLast);
}

//的到一个先序的链表
template<typename T>
void ConvertBSTree2List_PreOrder(TreeNode<T>* pTreeRoot/*树的根节点*/, TreeNode<T>*& pListHead/*双向链表的头指针*/, TreeNode<T>*& pListLast/*双向链表的尾指针*/) {

	if (pTreeRoot == NULL) {
		return;
	}

	/* 处理当前节点，把节点链到双向链表尾部*/
	TreeNode<int> * temp_left;
	TreeNode<int> * temp_right;

	temp_left = pTreeRoot->pLChild;
	temp_right = pTreeRoot->pRChild;

	pTreeRoot->pLChild = pListLast;

	if (pListLast) {
		pListLast->pRChild = pTreeRoot;
	}
	else {
		pListHead = pTreeRoot;
	}
	pListLast = pTreeRoot;

	//遍历后面结点
	ConvertBSTree2List_preorder(temp_left, pListHead, pListLast);
	ConvertBSTree2List_preorder(temp_right, pListHead, pListLast);
}

//如果要的到后序的链表，就比较麻烦了

int main() {
	TreeNode<int> *root = new TreeNode<int>();
	root->data = 10;
	root->pLChild = NULL;
	root->pRChild = NULL;

	TreeNode<int> *node_level1_1 = new TreeNode<int>();
	node_level1_1->data = 6;
	node_level1_1->pLChild = NULL;
	node_level1_1->pRChild = NULL;

	TreeNode<int> *node_level1_2 = new TreeNode<int>();
	node_level1_2->data = 14;
	node_level1_2->pLChild = NULL;
	node_level1_2->pRChild = NULL;


	TreeNode<int> *node_level2_1 = new TreeNode<int>();
	node_level2_1->data = 4;
	node_level2_1->pLChild = NULL;
	node_level2_1->pLChild = NULL;

	TreeNode<int> *node_level2_2 = new TreeNode<int>();
	node_level2_2->data = 8;
	node_level2_2->pLChild = NULL;
	node_level2_2->pRChild = NULL;


	TreeNode<int> *node_level2_3 = new TreeNode<int>();
	node_level2_3->data = 12;
	node_level2_3->pLChild = NULL;
	node_level2_3->pRChild = NULL;

	TreeNode<int> *node_level2_4 = new TreeNode<int>();
	node_level2_4->data = 16;
	node_level2_4->pLChild = NULL;
	node_level2_4->pRChild = NULL;

	root->pLChild = node_level1_1;
	root->pRChild = node_level1_2;

	node_level1_1->pLChild = node_level2_1;
	node_level1_1->pRChild = node_level2_2;

	node_level1_2->pLChild = node_level2_3;
	node_level1_2->pRChild = node_level2_4;

	TreeNode<int> *head = NULL;
	TreeNode<int> *last = NULL;

	//ConvertBSTree2List_MiddleOrder(root, head, last);
	ConvertBSTree2List_PreOrder(root, head);

	int val = head->data;
	cout << val << endl;

	TreeNode<int> * p = head;
	while (p != NULL) {
		cout << p->data << "  ";
		p = p->pRChild;
	}

	cout << endl;
	TreeNode<int> * q = last;
	while (q != NULL) {
		cout << q->data << "  ";
		q = q->pLChild;
	}

	return 0;
}
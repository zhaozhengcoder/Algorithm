// ConsoleApplication1.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h" //这个不能删除啊
// ConsoleApplication1.cpp: 定义控制台应用程序的入口点。
//
#include <iostream>
#include <string>

using namespace std;


#define size  26

struct TrieNode {
	int count;
	TrieNode * child[size];
};

TrieNode * createTrieNode() {
	TrieNode * node = new TrieNode();
	node->count = 0;
	for (int i = 0; i < size; i++) {
		node->child[i] = NULL;
	}
	return node;
}

void insert(TrieNode * tree,char * str) {
	TrieNode * node = tree;
	while (*str != '\0') {
		if (node->child[*str - 'a'] == NULL) {
			node->child[*str - 'a'] = createTrieNode();
		}
		node = node->child[*str - 'a'];
		str++;
	}
	node->count += 1;
}


int search(TrieNode * tree, char * keystr) {
	TrieNode * node = tree;

	while (*keystr != '\0' && node!=NULL) {
		node = node->child[*keystr - 'a'] ;
		keystr++;
	}
	if (node == NULL) {
		return 0;
	}
	else {
		return node->count;
	}
}


int main()
{


	char keys[][8] = { "the", "a", "there", "answer", "any", "by", "bye", "their" };
	TrieNode* root = createTrieNode();

	// 创建trie树
	for (int i = 0; i < 8; i++)
		insert(root, keys[i]);

	//查找
	char find_str1[] = "the";
	cout<<search(root,find_str1);

	char find_str2[] = "answer";
	cout << search(root, find_str2);

	char find_str3[] = "xxx";
	cout << search(root, find_str3);


	return 0;
}
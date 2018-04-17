#include <iostream>
#include <string>
using namespace std;

#define ALPHABET_SIZE 26

typedef struct trie_node
{
	int count;   // 记录该节点代表的单词的个数
	trie_node *children[ALPHABET_SIZE]; // 各个子节点 
}*trie;

trie_node* create_trie_node()
{
	trie_node* pNode = new trie_node();
	pNode->count = 0;
	for (int i = 0; i<ALPHABET_SIZE; ++i)
		pNode->children[i] = NULL;
	return pNode;
}

void trie_insert(trie root, char* key)
{
	trie_node* node = root;
	char* p = key;
	while (*p)
	{
		if (node->children[*p - 'a'] == NULL)
		{
			node->children[*p - 'a'] = create_trie_node();
		}
		node = node->children[*p - 'a'];
		++p;		//插入第一个字符 ; 指向第二个
	}
	node->count += 1;
}

/**
* 查询：不存在返回0，存在返回出现的次数
*/
int trie_search(trie root, char* key)
{
	trie_node* node = root;
	char* p = key;
	while (*p && node != NULL)
	{
		node = node->children[*p - 'a'];
		++p;
	}

	if (node == NULL)
		return 0;
	else
		return node->count;
}

int main()
{
	// 关键字集合
	char keys[][8] = { "the", "a", "there", "answer", "any", "by", "bye", "their" };
	trie root = create_trie_node();

	// 创建trie树
	for (int i = 0; i < 8; i++)
		trie_insert(root, keys[i]);

	// 检索字符串
	char s[][32] = { "Present in trie", "Not present in trie" };
	printf("%s --- %s\n", "the", trie_search(root, "the")>0 ? s[0] : s[1]);
	printf("%s --- %s\n", "these", trie_search(root, "these")>0 ? s[0] : s[1]);
	printf("%s --- %s\n", "their", trie_search(root, "their")>0 ? s[0] : s[1]);
	printf("%s --- %s\n", "thaw", trie_search(root, "thaw")>0 ? s[0] : s[1]);

	return 0;
}
# 二叉树的问题


二叉树的很多问题（尤其是递归的问题）都是二叉树前序遍历的思想可以解决。

//以打印根节点到叶子结点的路径为例
```
void solution(Node * root,vector<int> path)
{

    if(root != null)
    {
        //visit操作
        path.push_back(root->val);

		if (root->left == NULL && root->right == NULL)
		{
			print_vector(path);
		}

        //递归
        solution(root->left,path);
        solution(root->right,path);

        //清除递归条件
        path.pop_back();
    }
}
```
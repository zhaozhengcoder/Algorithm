
class Solution 
{
    public:
    void handle_solution(TreeNode * root, int target,int &sum , vector<int> path ,vector<vector<int>> & res)
    {
        if(root != NULL)
        {
            if(sum + root->val == target && root->left==NULL && root->right ==NULL)
            {
                path.push_back(root->val);
                res.push_back(path);
                
                //清除递归条件
                path.pop_back();
                return;
            }
            else
            {
                path.push_back(root->val);
                sum=sum+root->val;
                handle_solution(root->left,target,sum,path,res);
                handle_solution(root->right,target,sum,path,res);
                //清除递归条件
                sum=sum-root->val;
                path.pop_back();
            }
        }
        return;
    }
    vector<vector<int>> binaryTreePathSum(TreeNode * root, int target) {
        // write your code here
        vector<int> path;
        vector<vector<int>> res;
        int sum = 0;
        handle_solution(root,target,sum,path,res);
        return res;
    }
};
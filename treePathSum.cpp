#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    /*解法1：递归先序遍历(dfs)，当达到叶子节点，并且curSum == sum时，记录路径，
    并且回溯到上一步，继续搜索，直到遍历整棵树*/
    vector<vector<int>> pathSum(TreeNode* root, int sum) 
    {
        vector<vector<int> > paths;
        if (!root) return paths;
        vector<int> curPath;

        dfs(root, sum, curPath, paths);

        return paths;
    }

    void dfs(TreeNode* root, int sum, vector<int>& curPath, vector<vector<int>>& paths)
    {
        if (!root) return;

        curPath.push_back(root->val);
        sum -= root->val;

        if (sum == 0 && !root->left && !root->right)
        {
            paths.push_back(curPath);
        }

        dfs(root->left, sum, curPath, paths);
        dfs(root->right, sum, curPath, paths);
        curPath.pop_back(); // 如果左右子节点都遍历完毕，说明到达叶节点，则进行回溯
    }
};
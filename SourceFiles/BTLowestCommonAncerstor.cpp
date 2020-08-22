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

class Solution 
{
private:
    /*解法1：剑指offer思路*/
    bool getTreePath(TreeNode* root, TreeNode* dst, vector<TreeNode*>& path)
    {
        if (!root) return false;

        path.push_back(root);
        if (root == dst) return true;

        if (!getTreePath(root->left, dst, path) && !getTreePath(root->right, dst, path))
        {
            path.pop_back();
            return false;
        }    

        return true;
    }

public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        if (!root) return nullptr;

        vector<TreeNode*> pathP, pathQ;
        getTreePath(root, p, pathP);
        getTreePath(root, q, pathQ);

        TreeNode* ancetor = root;

        for (auto iterP = pathP.begin(), iterQ = pathQ.begin(); iterP != pathP.end() && iterQ != pathQ.end(); ++iterP, ++iterQ)
        {
            if (*iterP == *iterQ)
                ancetor = *iterQ;
            else
                break;
        }

        return ancetor;
    }
};
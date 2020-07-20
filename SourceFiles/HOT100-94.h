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
    vector<int> inorderTraversal(TreeNode* root) 
    {
        /*解法1：递归*/
        // vector<int> nodes;
        // if (!root) return nodes;

        // rinorderTraversal(root, nodes);
        // return nodes;

        /*解法2：迭代*/
        vector<int> nodes;
        if (!root) return nodes;

        stack<TreeNode*> paths;
        
        while (!paths.empty())
        {
            paths.push(root);
            root = root->left;

            while (!root)
            {
                root = paths.top();
                paths.pop();
                nodes.push_back(root->val);
                root = root->right;
            }
        }

        return nodes;
    }

    void rinorderTraversal(TreeNode* root, vector<int>& nodes)
    {
        if (!root) return;

        rinorderTraversal(root->left, nodes);
        nodes.push_back(root->val);
        rinorderTraversal(root->right, nodes);
    }
};
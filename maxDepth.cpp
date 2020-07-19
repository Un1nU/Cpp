#include <iostream>
#include <queue>
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
    /*解法1：后序遍历*/
    int maxDepth(TreeNode* root) 
    {
        if (!root) return 0;

        int leftDepth = maxDepth(root->left);
        int rightDepth = maxDepth(root->right);

        return max(leftDepth, rightDepth);
    }

    /*解法2：层序遍历*/
    int maxDepth(TreeNode* root) 
    {
        if (!root) return 0;
        int depth = 0;
        queue<TreeNode*> nodes;
        nodes.push(root);

        while (!nodes.empty())
        {
            int nodesNum = nodes.size();

            for (int i = 0; i < nodesNum; i++)
            {
                TreeNode* node = nodes.front();
                nodes.pop();

                if (node->left) nodes.push(node->left);
                if (node->right) nodes.push(node->right);
            }
            
            depth++;
        }
        
        return depth;
    }
};
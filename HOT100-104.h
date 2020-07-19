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
    int maxDepth(TreeNode* root) 
    {
        if (!root) return 0;
        if (!root->left && !root->right) return 1;

        int layerCnt = 0;
        int curNodes = 1;
        int nextNodes = 0;

        queue<TreeNode*> nodes;
        nodes.push(root);

        while (!nodes.empty())
        {
            root = nodes.front();
            nodes.pop();
            curNodes--;

            if (root->left)
            {
                nodes.push(root->left);
                nextNodes++;
            }

            if (root->right)
            {
                nodes.push(root->right);
                nextNodes++;
            }

            if (curNodes == 0)
            {
                curNodes = nextNodes;
                nextNodes = 0;
                layerCnt++;
            }
        }

        return layerCnt;
    }
};
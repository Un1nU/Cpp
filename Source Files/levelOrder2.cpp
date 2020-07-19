#include <iostream>
#include <queue>
#include <vector>
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
    vector<vector<int>> levelOrder(TreeNode* root) 
    {
        vector<vector<int> > traversal;
        if (!root) return traversal;

        queue<TreeNode*> nodes;
        nodes.push(root);
        int curNodes = 1;
        int nextNodes = 0;
        vector<int> layer;

        while(!nodes.empty())
        {
            root = nodes.front();
            nodes.pop();
            layer.push_back(root->val);
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
                traversal.push_back(layer);
                layer.clear();
            }
        }

        return traversal;
    }
};
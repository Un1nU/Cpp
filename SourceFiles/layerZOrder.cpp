#include <iostream>
#include <vector>
#include <deque>

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

        vector<int> layer;
        deque<TreeNode*> nodes;
        nodes.push_back(root);
        int layerCnt = 1;

        while (!nodes.empty())
        {
            int nodesNum = nodes.size();

            for (int i = 0; i < nodesNum; i++)
            {
                if (layerCnt % 2 == 1)
                {
                    root = nodes.front();
                    nodes.pop_front();
                    layer.push_back(root->val);
                    if (root->left) nodes.push_back(root->left);
                    if (root->right) nodes.push_back(root->right);
                }
                else
                {
                    root = nodes.back();
                    nodes.pop_back();
                    layer.push_back(root->val);
                    if (root->right) nodes.push_front(root->right);
                    if (root->left) nodes.push_front(root->left);
                }
            }
            
            layerCnt++;
            traversal.push_back(layer);
            layer.clear();
        }

        return traversal;
    }
};
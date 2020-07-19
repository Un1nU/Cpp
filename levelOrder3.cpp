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

        vector<int> layer;
        deque<TreeNode*> nodes;
        nodes.push_front(root);
        bool isOddLayer = true; // 层数奇偶标志位

        while(!nodes.empty())
        {
            int nodesNum = nodes.size();

            for (int i = 0; i < nodesNum; i++)
            {
                if (isOddLayer) // 对于奇数层
                { 
                    root = nodes.front(); // 按队列顺序取
                    nodes.pop_front();
                    if (root->left) nodes.push_back(root->left); // 下一层结点为偶数层，因此顺序入队
                    if (root->right) nodes.push_back(root->right);
                }
                else
                {
                    root = nodes.back(); // 对于偶数层，由于是顺序入队，所以需要倒序出队
                    nodes.pop_back();
                    if (root->right) nodes.push_front(root->right); //由于出队是倒序，因此下一层逆序放至队列中，从头出队才会是正序
                    if (root->left) nodes.push_front(root->left);
                }
                
                layer.push_back(root->val);
            }

            traversal.push_back(layer);
            layer.clear();
            isOddLayer = !isOddLayer;

        }

        return traversal;
    }
};
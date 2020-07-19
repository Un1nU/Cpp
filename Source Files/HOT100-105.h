#include <iostream>
#include <vector>
#include <algorithm>

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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
    {
        return rbuildTree(preorder.begin(), preorder.end(), inorder.begin(), inorder.end());
    }

    TreeNode* rbuildTree(vector<int>::iterator preBegin, vector<int>::iterator preEnd,
    vector<int>::iterator inBegin, vector<int>::iterator inEnd)
    {
        if (preBegin == preEnd) return nullptr;

        TreeNode* root = new TreeNode(*preBegin);
        auto inRoot = find(inBegin, inEnd, *preBegin);
        /*
        auto inRoot = inBegin;
        for (; inRoot != inEnd && *inRoot != *preBegin; inRoot++);
        */

        if (*inRoot != *(preBegin) && inRoot == inEnd) throw -1;

        root->left = rbuildTree(preBegin+1, preBegin+(inRoot-inBegin+1), inBegin, inRoot);
        root->right = rbuildTree(preBegin+(inRoot-inBegin+1), preEnd, inRoot+1, inEnd);

        return root;
    }

};
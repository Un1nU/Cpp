#include <iostream>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;     
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

static TreeNode* preNode = nullptr;

class Solution 
{
public:
    void flatten(TreeNode* root) 
    {
        if (!root) return;

        flatten(root->right);
        flatten(root->left);

        root->right = preNode;
        root->left = nullptr;
        preNode = root;
    }
};
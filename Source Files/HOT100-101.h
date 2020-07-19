#include <iostream>
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
    bool isSymmetric(TreeNode* root) 
    {
        if (!root) return true;
        if (!root->left && !root->right) return true;
        if (!root->left || !root->right) return false;

        return risSymmetric(root->left, root->right);        
    }

    bool risSymmetric(TreeNode* r1, TreeNode* r2)
    {
        if (!r1 && !r2) return true;
        if (!r1 || !r2) return false;

        return (r1->val == r2->val) && risSymmetric(r1->left, r2->right) && risSymmetric(r1->right, r2->left);
    }
};
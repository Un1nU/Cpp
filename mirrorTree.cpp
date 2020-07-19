#include <iostream>
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
    /*
            4              4
          /  \           /  \
         2    7        7    2
        / \  / \     / \  /  \
      1   3 6  9   9   6 3   1

        可以发现，两颗树镜像就是将左右子树进行交换
    */

    TreeNode* mirrorTree(TreeNode* root) 
    {
        if (!root) return nullptr; 
        if (!root->left && !root->right) return root; // 当节点没有左右子树时，不需要交换，直接返回根节点

        TreeNode* temp = root->left; // 交换左右子树
        root->left = root->right;
        root->right = temp;

        root->left = mirrorTree(root->left); // 递归进行左右子树的镜像操作
        root->right = mirrorTree(root->right);

        return root;
    }
};
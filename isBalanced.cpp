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
    bool isBalanced(TreeNode* root) 
    {
        if (!root) return true;
        
        // int leftDepth = treeDepth(root->left);
        // int rightDepth = treeDepth(root->right);

        // return abs(leftDepth - rightDepth) < 2 && isBalanced(root->left) && isBalanced(root->right);
        return risBalanced(root) != -1;
    }

    /*解法1：先序遍历的同时判断深度，再判断子树是否平衡
    时间复杂度 ： O(NlogN)
    空间复杂度 ： O(N) 递归调用栈
    */
    int treeDepth(TreeNode* root)
    {
        if (!root) return 0;

        return max(treeDepth(root->left), treeDepth(root->right)) + 1;
    }

    /*解法2：后序遍历同时判断子树是否平衡，对存在不平衡的子树直接返回，起到剪枝的作用
    时间复杂度： O(N)
    空间复杂度： O(N) 调用栈
    */
    int risBalanced(TreeNode* root)
    {
        if (!root) return 0;

        int leftDepth = risBalanced(root->left);
        if (leftDepth == -1) return -1;

        int rightDepth = risBalanced(root->right);
        if (rightDepth == -1) return -1;

        return abs(leftDepth - rightDepth) < 2 ? max(leftDepth, rightDepth)+1 : -1;
    }

};
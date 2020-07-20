#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isSubStructure(TreeNode* A, TreeNode* B) 
    {
        if (!A || !B) return false;

        // 相当于先序遍历，判断B是否是在以A为根节点子结构中，若不是，那么A的左子树是否是B的子结构，若不是，那么A的右子树是否是
        return isInclude(A, B) || isSubStructure(A->left, B) || isSubStructure(A->right, B);

    }

    bool isInclude(TreeNode* A, TreeNode* B)
    {
        if (!B) return true;
        if (!A || A->val != B->val) return false;

        return isInclude(A->left, B->left) && isInclude(A->right, B->right);
    }
};
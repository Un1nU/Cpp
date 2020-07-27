#include <iostream>
#include <stack>

using namespace std;

struct TreeNode 
{
    long val; // 注意是 long
    TreeNode *left;
    TreeNode *right;
    TreeNode(long x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
    /*解法1：递归法，同时更新左右子树值的上下界*/
    // bool isValidBST(TreeNode* root) 
    // {
    //     return risValidBST(root, lLONG_MIN, lLONG_MAX); // 需要设为long long，样例中包含闭区间[LONG_MIN, LONG_MAX]取值
    // }

    // bool risValidBST(TreeNode* root, long long lBound, long long uBound)
    // {
    //     if (!root) return true;
    //     if (root->val <= lBound || root->val >= uBound) return false;

    //     bool leftisBST = true;
    //     bool rightisBST = true;

    //     if (root->left)
    //     {
    //         long long upperBound = root->val; // 画一个 BST 就可以找到规律
    //         long long lowerBound = lBound;
    //         leftisBST = risValidBST(root->left, lowerBound, upperBound);
    //     }
        
    //     if (root->right)
    //     {
    //         long long upperBound = uBound;
    //         long long lowerBound = root->val;
    //         rightisBST = risValidBST(root->right, lowerBound, upperBound);
    //     }

    //     return leftisBST && rightisBST;

    //     /*简洁写法： 由于root为空时返回true，因此不用判断左右子树是否为空*/
    //     // return risValidBST(root->left, lBound, root->val) && risValidBST(root->right, root->val, uBound);
    // }

    /*解法2：中序遍历，BST的中序遍历序列是一个递增的序列*/
    bool isValidBST(TreeNode* root)
    {
        if (!root) return true;

        long long preNodeVal = (long long) LONG_MIN - 1;
        stack<TreeNode*> nodes;

        while (root)
        {
            nodes.push(root);
            root = root->left;

            while (!root && !nodes.empty())
            {
                root = nodes.top();
                nodes.pop();
                
                if (root->val <= preNodeVal) return false;
                preNodeVal = root->val;

                root = root->right;
            }
        }

        return true;
    }
};
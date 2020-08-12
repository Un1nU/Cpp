#include <iostream>
#include <unordered_map>

using namespace std;

struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution 
{
public:
    /*解法1：记忆化递归，通过遍历整颗树，来找到当前结点的最优解
    对于一个结点 root，能够偷到的金额最大与其子节点以及孙子节点有关。
    如果选择了 root 盗窃，则能够偷取的金额为 selected = root->val + root->left->left + root->left->right + root->right->left + root->right->right
    如果不选择盗窃 root，则能够偷取的金额为 notSelected = root->left->val + root->right->val
    因此对于节点 root，所能盗窃到的最大金额为 max(selected, notSelected)
    注意到，对于 root的子节点，其盗窃金额包含了 root孙子节点 的重复计算
    因此可以使用 map 来记忆遍历过的节点的最大盗窃金额，以优化时间复杂度

    时间复杂度 O(n)，相当于遍历了一遍二叉树
    空间复杂度 O(n) + O(n)， hashmap的空间以及递归调用栈的空间
    */
    // int rob(TreeNode* root) 
    // {
    //     unordered_map<TreeNode*, int> mp;
    //     return dfs(root, mp);
    // }

    // int dfs(TreeNode* root, unordered_map<TreeNode*, int>& mp)
    // {
    //     if (!root) return 0;

    //     if (mp.count(root) != 0) return mp[root];

    //     int money = root->val;

    //     if (root->left)
    //         money += dfs(root->left->left, mp) + dfs(root->left->right, mp);
        
    //     if (root->right)
    //         money += dfs(root->right->left, mp) + dfs(root->right->right, mp);

    //     int maxMoney = max(money, dfs(root->left, mp) + dfs(root->left, mp));

    //     return maxMoney;
    // }

    /*解法2：动态规划，树形DP
    pair<int, int> .first 表示选择该节点时的最大金额，.second 表示不选择该节点的最大金额。
    因此，对于节点 root，选择该节点时，最大金额为该节点金额加上不选择其子节点的最大金额
    不选择root节点时，最大金额为 选择其子节点 与 不选择其子节点 的金额的 两者最大
    
    时间复杂度： O(n)
    空间复杂读： O(n) 递归调用栈的空间
    */
    int rob(TreeNode* root)
    {
        auto money = rRob(root);
        return max(money.first, money.second);
    }

    pair<int, int> rRob(TreeNode* root)
    {
        if (!root) return {0, 0};

        auto left = rRob(root->left);
        auto right = rRob(root->right);

        int notSelected = max(left.first, left.second) + max(right.first, right.second);
        int Selected = root->val + left.first + right.first;

        return make_pair(notSelected, Selected);
    }
};
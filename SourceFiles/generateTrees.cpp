#include <vector> 

using namespace std;

struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<TreeNode*> generateTrees(int n) 
    {
        if (n == 0) return {};

        return generate(1, n);
    }

private:
    vector<TreeNode*> generate(int start, int end) // 递归构建AVL树
    {
        if (start > end)
            return { nullptr };
        
        vector<TreeNode*> trees;

        if (start == end) // 只有一个数时，返回该数值节点
        {
            TreeNode* root = new TreeNode(start);
            trees.emplace_back(root);
            return trees;
        }

        // 依次取[start,end]区间内的数作为根节点构建AVL树
        for (int i = start; i <= end; i++)  
        {
            vector<TreeNode*> leftTree;
            leftTree = generate(start, i - 1); // 递归获得所有左子树的集合

            vector<TreeNode*> rightTree;
            rightTree = generate(i + 1, end); // 递归获得所有右子树的集合

            // 取每一个左右子树，与当前节点 i 构建一个AVL树
            for (auto& left : leftTree) 
            {
                for (auto& right : rightTree)
                {
                    TreeNode* node = new TreeNode(i); // 创建当前值节点
                    node->left = left; // 连接左子树
                    node->right = right; // 连接右子树
                    trees.emplace_back(node); // 加入到结果集合中
                }
            }
        }

        return trees;
    }
};
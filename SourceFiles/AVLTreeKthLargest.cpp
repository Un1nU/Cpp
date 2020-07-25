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
    int kthLargest(TreeNode* root, int k) 
    {
        // vector<int> seq;

        // serilize(root, seq);
        
        // return seq[seq.size() - k];
        int result = root->val;

        reverseMidTraversal(root, k, result);
        return result;
    }

    void serilize(TreeNode* root, vector<int>& seq)
    {
        if (!root) return;

        serilize(root->left, seq);
        seq.push_back(root->val);
        serilize(root->right, seq);
    }

    void reverseMidTraversal(TreeNode* root, int& k, int& res)
    {
        if (!root) return;

        reverseMidTraversal(root->right, k, res);
        k--;
        if (k == 0) res = root->val;
        reverseMidTraversal(root->left, k, res);
    }
};
#include <iostream>
#include <vector>

using namespace std;

struct ListNode 
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution 
{
private:
    vector<int> getNodeArr(ListNode* head)
    {
        vector<int> nodes;

        while(head)
        {
            nodes.push_back(head->val);
            head = head->next;
        }

        return nodes;
    }

    TreeNode* buildTree(vector<int>& nodes, int start, int end) // 闭区间 [start, end]
    {
        if (start > end) return nullptr;

        int mid = start + (end - start) / 2;
        TreeNode* root = new TreeNode(nodes[mid]);
        root->left = buildTree(nodes, start, mid-1);
        root->right = buildTree(nodes, mid+1, end);

        return root;
    }

    ListNode* getMidianNode(ListNode* head, ListNode* tail) // 左闭右开区间 [head, tail)
    {   
        if (!head) return nullptr;
        ListNode* faster = head;
        ListNode* slower = head;

        while (faster != tail && faster->next != tail)
        {
            faster = faster->next;
            faster = faster->next;
            slower = slower->next;
        }

        return slower;
    }

    TreeNode* buildTree(ListNode* head, ListNode* tail) // 左闭右开区间 [head, tail)
    {
        if (head == tail) return nullptr;

        ListNode* mid = getMidianNode(head, tail);
        TreeNode* root = new TreeNode(mid->val);
        root->left = buildTree(head, mid);
        root->right = buildTree(mid->next, tail);

        return root;
    }

public:
    /*解法1：快慢指针查找链表的中间结点，即BST的根节点，然后递归重建左右子树
    时间复杂度：O(nlogn)
    空间复杂度：O(logn)
    */
    TreeNode* sortedListToBST(ListNode* head)
    {
        if (!head) return nullptr;

        return buildTree(head, nullptr);
    }

    /*解法2：分治法重建二叉树，使用数组保存链表的结点，通过二分来寻找左右子树的根，然后递归重建左右子树
    时间复杂度：O(n)
    空间复杂度：O(n)
    */
    // TreeNode* sortedListToBST(ListNode* head) 
    // {
    //     if (!head) return nullptr;

    //     vector<int> nodes = getNodeArr(head);

    //     return buildTree(nodes, 0, nodes.size() - 1);
    // }
};
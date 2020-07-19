#include <iostream>

using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) 
    {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) 
    {
        val = _val;
        left = _left;
        right = _right;
    }
};

class Solution {
public:
    /*解法1：中序遍历二叉树，并修改指针指向。
    二叉搜索树的中序遍历正好为从小到大的排序链表，
    左子树的后继为根节点，右子树的前驱为根节点
    */
    Node* treeToDoublyList(Node* root) 
    {
        if (!root) return nullptr;
        Node* head = nullptr; 
        Node* pre = nullptr;  

        dfsTransfer(root, head, pre);

        pre->right = head; // dfs搜索完毕后，pre 指向的是链表最后一个结点, 其后继为 头结点head
        head->left = pre; // head 的前驱为链表最尾结点，此时为 pre

        return head;
    }

    // curNode 表示当前遍历到的结点，headNode 指针指向双向链表的头结点, preNode 指针表示当前结点的前驱结点
    void dfsTransfer(Node* curNode, Node*& headNode, Node*& preNode)
    {
        if (!curNode) return; // 当前指针为空时，递归产生回溯

        dfsTransfer(curNode->left, headNode, preNode); // 中序遍历，先遍历到最左结点

        // preNode为空，表示第一次遍历到最左结点（preNode还没有赋值）,即链表的头结点，将 headNode 指向该结点
        if (!preNode) headNode = curNode; 
        else preNode->right = curNode; // 访问 preNode 的后继时，需要判断 preNode 是否为空，不为空就指向 curNode
        
        curNode->left = preNode; // 将 curNode 的前驱指向 preNode
        preNode = curNode; // 更新 preNode 为 curNode， 以进行下一层递归

        dfsTransfer(curNode->right, headNode, preNode); // 当左子树遍历完后，遍历右子树
    }
};
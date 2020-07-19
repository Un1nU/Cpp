#include <iostream>
#include <unordered_map>

using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) 
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:

    /*解法1：首先在原始列表中复制每一个结点，将复制的结点置于原始结点的下一位(A->B : A->A'->B->B')；
    再根据原始random指针的关系，在复制的结点中对应地复制random指针指向 (A->B->C : A->A'->...->C->C')
                                                                   ------^   ------------^
                                                                                -------------^
    最后根据奇偶位置，将拓展后的链表分离为 原始链表 (A->B->C) 和 克隆链表(A'->B'->C')
    
    时间复杂度: O(n)
    空间复杂度: O(1)
    */
    // Node* copyRandomList(Node* head) 
    // {
    //     cloneNode(head);
    //     copyRandomPtr(head);
        
    //     return splitClone(head);
    // }

    // void cloneNode(Node* head)
    // {
    //     if (!head) return;

    //     Node* phead = head;

    //     while (phead)
    //     {
    //         Node* cloneNode = new Node(phead->val);
    //         cloneNode->next = phead->next;
    //         phead->next = cloneNode;

    //         phead = cloneNode->next;
    //     }
    // }

    // void copyRandomPtr(Node* head)
    // {
    //     if (!head) return;

    //     Node* phead = head;
    //     Node* pclone = nullptr;

    //     while (phead)
    //     {
    //         pclone = phead->next;
    //         if (phead->random)
    //             pclone->random = phead->random->next;
    //         phead = pclone->next;
    //         //pclone = phead->next; // 此时phead可能为空指针,需要判断，将该条语句放于句首可以将判断放于while中
    //     }
    // }

    // Node* splitClone(Node* head)
    // {
    //     if (!head) return nullptr;

    //     Node* phead = head;
    //     Node* pclone = head->next;
    //     Node* pCloneHead = pclone;

    //     while (phead)
    //     {
    //         phead->next = pclone->next;
    //         phead = phead->next;
    //         if (!phead) break; // 当phead指向nullptr时，说明已经完成了复制
    //         pclone->next = phead->next;
    //         pclone = pclone->next;
    //     }

    //     return pCloneHead;
    // }

    /*解法2：顺序遍历原链表的同时复制结点，并使用哈希表来保存每一个原结点指针地址对应的新结点指针地址，
            遍历完链表后，根据hash查找再来设定新建结点的 next 和 random 指针指向
    
    时间复杂度: O(n)
    空间复杂度: O(n)
    */
    Node* copyRandomList(Node* head) 
    {
        if (!head) return nullptr;

        Node* phead = head;
        unordered_map<Node*, Node*> randomMap;

        while (phead)
        {
            randomMap[phead] = new Node(phead->val);
            phead = phead->next;
        }

        phead = head;
        Node* cloneHead = randomMap.find(head)->second;
        const auto mapEnd = randomMap.end();
        while (phead)
        {
            auto cloneNodeIter = randomMap.find(phead);

            if (phead->next && cloneNodeIter != mapEnd)
            {
                auto cloneNextIter = randomMap.find(phead->next);

                if (cloneNodeIter != mapEnd)
                    cloneNodeIter->second->next = cloneNextIter->second;
            }

            if (phead->random && cloneNodeIter != mapEnd)
            {
                auto cloneRandIter = randomMap.find(phead->random);

                if (cloneRandIter != mapEnd)
                    cloneNodeIter->second->random = cloneRandIter->second;
            }

            phead = phead->next;
        }

        return cloneHead;   
    }  
};
#include <iostream>
#include <queue>
using namespace std;

struct ListNode 
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    /*解法1: 新建一个头结点，将较小的结点接到其后面*/
    // ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) 
    // {
    //     if (!l1 && !l2) return NULL;
    //     if (!l1) return l2;
    //     if (!l2) return l1;

    //     ListNode* head = NULL;
    //     ListNode* phead = NULL;

    //     if (l1->val >= l2->val)
    //         head->next = l2;
    //     else
    //         head->next = l1;

    //     phead = head->next;

    //     while(l1 && l2)
    //     {
    //         if (l1->val > l2->val)
    //         {
    //             phead->next = l2;
    //             l2 = l2->next;
    //             phead = phead->next;
    //         }
    //         else
    //         {
    //             phead->next = l1;
    //             l1 = l1->next;
    //             phead = phead->next;
    //         }
            
    //     }

    //     if (l1) phead->next = l1;
    //     if (l2) phead->next = l2;

    //     return head->next;
    // }

    /*解法2:不新建头结点，在原有的list基础上合并*/
    // ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
    // {
    //     if (!l1 && !l2) return NULL;
    //     if (!l1) return l2;
    //     if (!l2) return l1;

    //     ListNode* head = NULL;
    //     ListNode* phead ;

    //     if (l1->val < l2->val)
    //     {
    //         head = l1;
    //         l1 = l1->next;
    //     }
    //     else
    //     {
    //         head = l2;
    //         l2 = l2->next;
    //     }

    //     phead = head;

    //     while(l1 && l2)
    //     {
    //         if (l1->val < l2->val)
    //         {
    //             phead->next = l1;
    //             l1 = l1->next;
    //         }
    //         else
    //         {
    //             phead->next = l2;
    //             l2 = l2->next;
    //         }

    //         phead = phead->next;
    //     }

    //     if (l1) phead->next = l1;
    //     if (l2) phead->next = l2;

    //     return head;
    // }

    /*解法3：递归法*/
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
    {
        if (!l1 && !l2) return NULL;
        if (!l1) return l2;
        if (!l2) return l1;

        if (l1->val <= l2->val)
        {
            // 递归求解l1->next及之后的合并结果，并把l1->next指向合并后的头结点
            l1->next = mergeTwoLists(l1->next, l2); 
            return l1; // 合并完成后返回头结点
        }
        else 
        {
            l2->next = mergeTwoLists(l2->next, l1);
            return l2;
        }
    }   
};
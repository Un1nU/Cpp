#include <iostream>

using namespace std;

struct ListNode 
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution 
{
private:
    ListNode* mergeList(ListNode* l1, ListNode* l2)
    {
        if (!l1 && !l2) return nullptr;
        if (!l1) return l2;
        if (!l2) return l1;

        ListNode* head = new ListNode(0);
        ListNode* phead = head;

        while (l1 && l2)
        {
            if (l1->val > l2->val)
            {
                phead->next = l2;
                l2 = l2->next;
                phead = phead->next;
            }
            else
            {
                phead->next = l1;
                l1 = l1->next;
                phead = phead->next;
            }           
        }

        if (l1) phead->next = l1;
        if (l2) phead->next = l2;

        phead = head->next;
        delete head;

        return phead;
    }

    ListNode* cutList(ListNode* head, int n)
    {
        if (!head || n == 0) return head;

        ListNode* phead = head;
        ListNode* tail = nullptr;

        while (--n && phead)
        {
            phead = phead->next;
        }

        if (!phead) return nullptr;

        tail = phead;
        phead = phead->next;
        tail->next = nullptr;

        return phead;      
    }

public:
    ListNode* sortList(ListNode* head) 
    {
        if (!head) return nullptr;
        
        int length = 0;
        ListNode* phead = head;
        while (phead)
        {
            length++;
            phead = phead->next;
        }

        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;

        for (int part = 1; part < length; part *= 2)
        {
            ListNode* left = cutList(head, part);

            ListNode* right = cutList(left, part);


        }

    }
};
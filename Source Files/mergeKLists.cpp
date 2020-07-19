#include <iostream>
#include <vector>

using namespace std;

struct ListNode 
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
    {
        if (!l1 && !l2) return nullptr;
        if (!l1) return l2;
        if (!l2) return l1;

        ListNode* head = nullptr;

        if (l1->val > l2->val)
        {
            head = l2;
            l2 = l2->next;
        }
        else
        {
            head = l1;
            l1 = l1->next;
        }

        ListNode* phead = head;
        while (l1 && l2)
        {
            if (l1->val > l2->val)
            {
                phead->next = l2;
                l2 = l2->next;
            }
            else
            {
                phead->next = l1;
                l1 = l1->next;
            }

            phead = phead->next;
        }

        if (l1) phead->next = l1;
        if (l2) phead->next = l2;

        return head;
    }

    ListNode* rmergeKLists(vector<ListNode*>& lists, int start, int end)
    {
        if (start == end) return lists[start];
        if (start > end) return nullptr;
        int mid = start + (end - start) / 2;

        // 分治思想，分的最小单位为start == end，此时返回该链表的头指针，然后返回到倒数第二层递归，合并最左两个链表，并返回头指针
        // 依次回推，最后返回合并的链表
        return mergeTwoLists(rmergeKLists(lists, start, mid), rmergeKLists(lists, mid+1, end));
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
        if (lists.size() <= 0) return nullptr;

        return rmergeKLists(lists, 0, lists.size()-1);
    }
};
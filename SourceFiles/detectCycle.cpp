#include <iostream>

using namespace std;

struct ListNode 
{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution 
{
private:
    ListNode* getIntersect(ListNode* head)
    {
        if (!head) return nullptr;

        ListNode* faster = head;
        ListNode* slower = head;

        while (faster && faster->next)
        {
            faster = faster->next->next;
            slower = slower->next;

            if (faster == slower) return faster;
        }

        return nullptr;
    }

public:
    ListNode* detectCycle(ListNode* head) 
    {
        if (!head) return nullptr;

        ListNode* intersect = getIntersect(head);

        if (!intersect) return nullptr;

        ListNode* phead = head;
        while (phead != intersect)
        {
            phead = phead->next;
            intersect = intersect->next;
        }

        return phead;
    }
};
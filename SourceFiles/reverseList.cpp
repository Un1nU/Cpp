#include <iostream>
using namespace std;
struct ListNode 
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) 
    {
        if (!head) return nullptr;
        if (!head->next) return head;

        ListNode* current = head->next;
        ListNode* behind = head;
        behind->next = nullptr;
    
        while (current)
        {
            ListNode* nextNode = current->next;

            current->next = behind;
            behind = current;
            current = nextNode;
        }

        return behind;
    }
};
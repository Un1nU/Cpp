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
    ListNode* getKthFromEnd(ListNode* head, int k) 
    {
        if (!head || k == 0) return nullptr;

        ListNode* front = head;
        ListNode* behind = head;

        for (int i = 0; i < k; i++)
        {
            if (front)
                front = front->next;
            else
                return nullptr;
        }

        while (front)
        {
            behind = behind->next;
            front = front->next;
        }

        return behind;
    }
};
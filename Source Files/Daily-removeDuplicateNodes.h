#include <iostream>
#include <unordered_set>

using namespace std;

struct ListNode 
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeDuplicateNodes(ListNode* head) 
    {
        if (!head) return nullptr;

        unordered_set<int> nodes;
        nodes.insert(head->val);
        ListNode* phead = head;
        //ListNode* behind = head;

        while (phead->next)
        {
            if (nodes.find(phead->next->val) != nodes.end())
            {
                ListNode* cur = phead->next;
                phead->next = cur->next;
                //behind->next = phead;
                cur->next = nullptr;
                delete cur;
            }
            else
            {
                nodes.insert(phead->next->val);
                //behind = phead;
                phead = phead->next;
            }
        }

        return head;
    }
};
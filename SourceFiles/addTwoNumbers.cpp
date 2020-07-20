#include <iostream>
#include <stack>

using namespace std;

struct ListNode 
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution 
{
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        if (!l1) return l2;
        if (!l2) return l1;

        stack<ListNode*> stk1;
        stack<ListNode*> stk2;

        while(l1)
        {
            stk1.push(l1);
            l1 = l1->next;
        }

        while(l2)
        {
            stk2.push(l2);
            l2 = l2->next;
        }

        ListNode* res = nullptr;
        int carry = 0;

        while(!stk1.empty() || !stk2.empty() || carry != 0) // carry ！= 0 的条件表示最高位相加依然有进位 
        {
            int a = 0;
            if (!stk1.empty())
            {
                a = stk1.top()->val;
                stk1.pop();
            }
            
            int b = 0;
            if (!stk2.empty())
            {
                b = stk2.top()->val;
                stk2.pop();
            }

            int sum = a + b + carry;

            if (sum >= 10)
            {
                sum -= 10;
                carry = 1;
            }
            else
                carry = 0;

            // 注意这三条语句，能够从后往前构建链表
            ListNode* node = new ListNode(sum);
            node->next = res;
            res = node;
        }

        return res;
    }
};
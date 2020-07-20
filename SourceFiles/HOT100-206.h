 #include <iostream>
 
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
    /*解法1： 迭代方法，前中后三个指针，保存当前，前一个和后一个的地址*/
        // if (!head) return nullptr;
        // if (!head->next) return head;
        // ListNode* behind = head;
        // ListNode* current = head->next;
        // ListNode* front = current->next;
        // head->next = nullptr;

        // while (front)
        // {
        //     current->next = behind;
        //     behind = current;
        //     current = front;
        //     front = front->next;
        // }

        // current->next = behind; // 循环跳出后，最后一个结点(current)还没有指向倒数第二个结点(behind)

        // return current;

    /*解法2：递归，最后一层递归首先达到最后一个结点，然后返回地址给倒数第二层递归
        此时的 head->next->next 表示倒数第二个结点(head)的下一个结点（倒数第一个结点）的下一个结点指向倒数第二个结点(head)
        然后 head->next = nullptr 表示断开倒数第二个结点指向最后一个结点的指针
    */
        if (!head) return nullptr;
        if (!head->next) return head;

        ListNode* res = reverseList(head->next);
        head->next->next = head; // 这里对head操作的原因，是递归函数的参数为head
        head->next = nullptr;

        return res;
    }
};
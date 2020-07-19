#include <iostream>

struct ListNode 
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) 
    {
        /*解法1：使用hashmap或者set存储访问过的地址，如果遇到了之前访问过的地址，则表示有环
            时间复杂度 O(n)
            空间复杂度 O(n)
        */

       /*解法2：利用快慢指针，如果存在环则一定会相遇，否则无环
            时间复杂度 O(n) 分析见 https://leetcode-cn.com/problems/linked-list-cycle/solution/dui-guan-fang-ti-jie-de-kuai-man-zhi-zhen-jie-fa-d/
            空间复杂度 O(1)
       */
        if (!head || !head->next) return false;

        ListNode* lower = head;
        ListNode* faster = head->next;

        while (lower != faster)
        {
            lower = lower->next;
            faster = faster->next->next;

            if (!lower || !faster)
                return false;
        }

        return true;
    }
};
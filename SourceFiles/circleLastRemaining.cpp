#include <list>

using namespace std;

class Solution 
{
public:
    /*解法1：模拟法，使用链表模拟约瑟夫环，删除每 m 步遍历到的链表结点，
    当到达链表的末尾 list.end()，则将其重新赋值为 list.begin() 以模拟圆环
    需要注意，每当进行删除操作时， list 的迭代器会失效，因此需要预先保存 下一位的迭代器next
    删除 iter 当前值后，赋值为 next 以继续遍历
    遍历结束的条件是 circle.size() == 1

    时间复杂度 O(n x m)，当数据量非常大时 timeout
    空间复杂度 O(n)
    */
    // int lastRemaining(int n, int m) 
    // {
    //     if (n == m && n == 1) return 0;

    //     list<int> circle;
    //     for (int i = 0; i < n; ++i)
    //         circle.emplace_back(i);

    //     auto iter = circle.begin();

    //     while (circle.size() > 1)
    //     {
    //         for (int i = 0; i < m; ++i)
    //         {
    //             auto next = ++iter;
                
    //             if (i == m - 1)
    //             {
    //                 --iter;
    //                 circle.erase(iter);
    //                 iter = next;
    //             }
                
    //             if (iter == circle.end())
    //                 iter = circle.begin();
    //         }
    //     }

    //     return *circle.begin();
    // }

    /*解法2：
    */
    int lastRemaining(int n, int m)
    {
        
    }
};
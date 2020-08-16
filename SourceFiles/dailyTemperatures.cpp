#include <vector>
#include <stack>

using namespace std;

class Solution 
{
public:
    /*解法1：单调栈，维护一个单调递减栈，当遇到比栈顶元素大的温度时，
    计算当前天数与栈顶元素的天数之差，并记录结果

    时间复杂度：O(n)
    空间复杂度：O(n)
    */
    vector<int> dailyTemperatures(vector<int>& T) 
    {
        stack<int> stk;
        int size = T.size();
        vector<int> days(size, 0);
        
        for (int i = 0; i < size; ++i)
        {
            while (!stk.empty() && T[stk.top()] < T[i])
            {
                int day = i - stk.top();
                days[stk.top()] = day;
                stk.pop();
            }

            stk.push(i);
        }

        return days;
    }
};
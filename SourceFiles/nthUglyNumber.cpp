#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution 
{
public:
    /*解法1：动态规划，或者三指针法，根据丑数的定义，只包含质因子2、3、5的数，
    根据第一个丑数为1，因此接下来的丑数，必定为 1x2, 1x3, 1x5 之间的最小值，
    从而所有的丑数都可根据之前的丑数递推得到，假设指针 a b c 构成的集合为
    A = {1x2, 2x2, 3x2, 4x2 ... a_ix2}
    B = {1x3, 2x3, 3x3, 4x3 ... b_ix3}
    C = {1x5, 2x5, 3x5, 4x5 ... c_ix5}
    所以，所有的丑数构成的集合就是 A、B、C 三个集合的并集，
    由于三个集合中可能存在重复的数字，因此递推时需要进行去重
    */
    int nthUglyNumber(int n) 
    {
        if (n < 7) return n;

        vector<int> dp(n);
        dp[0] = 1;

        int a, b, c;
        a = b = c = 0; 

        for (int i = 1; i < n; ++i)
        {
            dp[i] = min(dp[a] * 2, min(dp[b] * 3, dp[c] * 5));

            if (dp[a] * 2 == dp[i]) ++a;
            if (dp[b] * 3 == dp[i]) ++b;
            if (dp[c] * 5 == dp[i]) ++c;
        }

        return dp[n - 1];
    }
};
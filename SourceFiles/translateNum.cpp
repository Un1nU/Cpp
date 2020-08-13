#include <string>
#include <vector>

using namespace std;

class Solution 
{
public:
    /*解法1：动态规划，对于数字 abcdefg 的某一位，例如 c
    其可以单独翻译为字符，也可以与 b 组合翻译为字符
    若与 b 组合翻译为字符，则需要符合 （b为0不符合要求） 10 <= bc <= 25
    因此对于第 i 位数字，其能被翻译为不同字符串的总数为 
        dp[i] = dp[i - 1] + dp[i - 2], num[i-1:i-2] 处于区间 [10, 25]
        dp[i] = dp[i - 1]， num[i-1:i-2] 属于区间 (0, 10) && (25, 99]
    边界条件为，dp[0] = 1，dp[1] = 1 表示空字符翻译为 1 种，单个字符翻译为 1 种

    可以只保留前两步的状态，以优化空间复杂度
    */
    int translateNum(int num) 
    {
        string strNum = to_string(num);
        int n = strNum.length();
        // vector<int> dp(n+1);

        // dp[0] = 1;
        // dp[1] = 1;

        int dp = 1;
        int dp_1 = 1;
        int dp_2 = 1;

        for (int i = 2; i <= n; ++i)
        {
            if (strNum[i - 2] == '1' || strNum[i - 2] == '2' && strNum[i - 1] <= '5')
            {
                // dp[i] = dp[i - 1] + dp[i - 2];
                dp = dp_1 + dp_2;
            }            
            else
            {
                // dp[i] = dp[i - 1];
                dp = dp_1;
            }

            dp_2 = dp_1;
            dp_1 = dp; 

        }

        // return dp[n];
        return dp;
    }
};
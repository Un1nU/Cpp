#include <vector>
#include <limits.h>

using namespace std;

class Solution 
{
public:
    int splitArray(vector<int>& nums, int m) 
    {
        int n = nums.size();
        vector<long> subSum(n+1, 0); 

        // subSum[i] 表示数组前 i 个元素的和
        for (int i = 1; i <= n; i++)
            subSum[i] = subSum[i - 1] + nums[i - 1];

        vector<vector<long> > dp(n+1, vector<long>(m+1, LONG_MAX));

        // 由于划分的子数组要为非空，因此 i == 0 表示不划分，
        // j == 0 表示在 i 处划分为 0 组，两种情况并不合法，将其初始化为一个无穷大值
        // i = j = 0 表示在 第一个元素前划分 0 组，即空集，和为0
        dp[0][0] = 0;

        // dp[i][j] 表示前 i 个元素分为 j 组
        for (int i = 1; i <= n; i++)
        {
            // j 必须满足 j <= i 且 j <= m
            for (int j = 1; j <= min(i, m); j++)
            {
                // 前 i 个元素分为 1 组，即前缀子列和
                if (j == 1) dp[i][j] = subSum[i];
                else
                {   // 在前 i-1 个元素中，从 k 处划分为 j-1 组
                    // 由于 k 一定满足 k >= j-1，所以也可以初始化为 k = j-1
                    for (int k = 0; k < i; k++)
                    {
                        dp[i][j] = min(dp[i][j], max(dp[k][j - 1], subSum[i]-subSum[k]));
                    }   
                }                
            }
        }

        return dp[n][m];
    }
};
#include <vector>
#include <algorithm>

using namespace std;

class Solution 
{
public:
    /*解法1：动态规划，n 个骰子所有点数出现的概率为 n个骰子所有点数出现频率 / 6^n
    dp[i][j] 表示投掷出 第i次 骰子后，得到点数（累加和）为 j 的次数
    因此，转移方程为 dp[i][j] = sum(dp[i-1][j-1], dp[i-1][j-2], ..., dp[i-1][j-6])
    初始条件， dp[1][j] = 1*/
    // vector<double> twoSum(int n) 
    // {
    //     // 第二维是 6*n+1，因为如果第二次投掷，只可能出现 7~12 点数
    //     vector<vector<int>> dp(n+1, vector<int>(6*n + 1)); 

    //     for (int j = 1; j <= 6; ++j)
    //         dp[1][j] = 1;

    //     for (int i = 2; i <= n; ++i)
    //     {
    //         // 第 i 次投掷，点数只会出现在 [i, 6i] 之间，
    //         // 从这里可以看出这个二维 dp 矩阵是稀疏的，因此可以很容易优化
    //         for (int j = i; j <= 6*i; ++j) 
    //         {
    //             for (int k = 1; k <= 6; ++k)
    //             {
    //                 if (j - k <= 0) break;

    //                 dp[i][j] += dp[i - 1][j - k];
    //             }
    //         }
    //     }

    //     vector<double> res;
    //     double pn = pow(6, n);

    //     for (int j = 1; j <= 6*n; ++j)
    //         res.emplace_back(dp[n][j] / pn);

    //     return res;
    // }

    /*解法2：动态规划，在解法1的基础上，使用一维数组进行点数的保存*/
    vector<double> twoSum(int n)
    {
        vector<int> dp(6*n + 1, 0);

        for (int j = 1; j <= 6; ++j)
            dp[j] = 1;

        for (int i = 2; i <= n; ++i)
        {
            // 为何是倒序，类似于背包问题的优化
            // 在二维dp中，dp[i][j] += dp[i-1][j-k]
            // 而在一维中，如果是顺序遍历，dp[j] += dp[j-k]，
            // 此时的 dp[j-k] 相当于 dp[i][j-k]，产生错误结果
            for (int j = 6*i; j >= i; --j)
            {   
                // 即使初始化时已经清零，然而 dp[j] 可能存储着上一次(i-1次)投掷时，出现点数累加为 j 的结果
                // 因而第 i 次投掷时，需要重新置零
                dp[j] = 0; 
                for (int k = 1; k <= 6; ++k)
                {
                    // 由于 dp[j - k] 是 i-1 次的点数，因而 j-k 最小不可能小于 i-1
                    if (j - k < i - 1) break;

                    dp[j] += dp[j - k];
                }
            }
        }

        vector<double> prob;
        double pn = pow(6, n);

        for (int j = n; j <= 6*n; ++j)
            prob.emplace_back(dp[j] / pn);

        return prob;
    } 
};
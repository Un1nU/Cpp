#include <vector>
using namespace std;

class Solution 
{
public:
    /**
     * @param m: An integer m denotes the size of a backpack
     * @param A: Given n items with size A[i]
     * @return: The maximum size
     */
    int backPack(int m, vector<int> &A) 
    {
        // write your code here
        if (A.empty()) return 0;
        
        int n = A.size();
        vector<vector<int> > dp(n, vector<int>(m + 1));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j <= m; j++)
            {
                if (j == 0)
                    dp[i][j] = 0; // 初始化：背包容量为0时， 容纳的最大价值也为0
                else if (j < A[i])
                {
                    if (i == 0)
                        dp[i][j] = 0; // 初始化：当 i == 0 时， i-1 会产生越界，单独处理
                    else
                        dp[i][j] = dp[i - 1][j]; // 背包容量不够，维持上一状态
                }
                else
                {
                    if (i == 0)
                        dp[i][j] = A[i]; // 初始化：当 i == 0 时， i-1 会产生越界，单独处理
                    else
                        dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - A[i]] + A[i]); // 转移方程
                }
            }
        }

        return dp[n - 1][m];
    }
};
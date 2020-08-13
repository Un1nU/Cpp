#include <vector>

using namespace std;

class Solution 
{
public:
    int maxValue(vector<vector<int>>& grid) 
    {
        int rows = grid.size();
        if (rows == 0) return 0;

        int cols = grid[0].size();
        if (cols == 0) return 0;

        vector<vector<int>> dp(rows, vector<int>(cols, 0));

        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                if (i == 0 && j == 0)
                    dp[i][j] = grid[i][j];
                else if (i == 0)
                    dp[i][j] = dp[i][j - 1] + grid[i][j];
                else if (j == 0)
                    dp[i][j] = dp[i - 1][j] + grid[i][j];
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]) + grid[i][j];
            }
        }

        return dp[rows - 1][cols - 1];
    }
};
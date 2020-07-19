#include <vector>

using namespace std;

class Solution {
public:
    /*解法1： dfs，每当到达右下角，计数加1，但会超时*/
    // int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) 
    // {
    //     int cnt = 0;
    //     dfs(obstacleGrid, 0, 0, cnt);

    //     return cnt;
    // }

    // // dfs
    // void dfs(vector<vector<int> >& obstacleGrid, int nextx, int nexty, int& cnt)
    // {
    //     if (nextx == obstacleGrid.size()-1 && nexty == obstacleGrid[0].size()-1 && obstacleGrid[nextx][nexty] != 1)
    //     {
    //         cnt++;
    //         return;
    //     }
    //     else if (nextx < obstacleGrid.size() && nexty < obstacleGrid[0].size() && obstacleGrid[nextx][nexty] != 1)
    //     {
    //         dfs(obstacleGrid, nextx+1, nexty, cnt);
    //         dfs(obstacleGrid, nextx, nexty+1, cnt);
    //     }
    // }

    /*解法2： 动态规划*/
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) 
    {
        int sizeX = obstacleGrid.size();
        int sizeY = obstacleGrid[0].size();

        if (sizeX == 0 || sizeY == 0) return 0;
        if (obstacleGrid[0][0] == 1) return 0;

        vector<vector<int> > dp(sizeX, vector<int>(sizeY));

        dp[0][0] = 1;
        for (int row = 0; row < sizeX; row++)
        {
            for (int col = 0; col < sizeY; col++)
            {
                if (obstacleGrid[row][col] == 1) 
                    dp[row][col] = 0;
                else
                {
                    if (row == 0 && col > 0)
                        dp[row][col] = dp[row][col - 1];
                    else if (col == 0 && row > 0)
                        dp[row][col] = dp[row - 1][col];
                    else if (row > 0 && col > 0)
                        dp[row][col] = dp[row - 1][col] + dp[row][col - 1];
                }
                
            }
        }

        return dp[sizeX - 1][sizeY - 1];
    }
};
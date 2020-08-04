#include <vector>

using namespace std;

class Solution {
public:
    /*
    解法1：DFS，搜索到陆地'1'时，以该点为起点进行dfs，
    遍历过的陆地都设为'0'，直到达到海水的边界。
    并且岛屿数量 +1
    */
    int numIslands(vector<vector<char>>& grid) 
    {
        int rows = grid.size();
        if (rows == 0) return 0;

        int cols = grid[0].size();
        if (cols == 0) return 0;

        int isLandNum = 0;

        for (int row = 0; row < rows; row++)
        {
            for (int col = 0; col < cols; col++)
            {
                if (grid[row][col] == '1')
                {
                    isLandNum++;
                    dfs(grid, row, col);
                }
            }
        }

        return isLandNum;
    }

    void dfs(vector<vector<char>>& grid, int x, int y)
    {
        int rows = grid.size();
        int cols = grid[0].size();

        if (x < 0 || x >= rows || y < 0 || y >= cols || grid[x][y] == '0') 
            return;

        grid[x][y] = '0';

        dfs(grid, x + 1, y);
        dfs(grid, x - 1, y);
        dfs(grid, x, y + 1);
        dfs(grid, x, y - 1);
    }
};
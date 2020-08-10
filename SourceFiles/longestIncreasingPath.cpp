#include <vector>
#include <limits.h>
using namespace std;

class Solution 
{
public:
    /*解法1： DFS + 记忆化搜索
        memo[x][y] 记录的是从 x,y 出发所能到达的最长路径
        由于搜索时需要满足 matrix[nextx][nexty] > matrix[x][y]，这个条件保证了一定不会遍历到已访问的路径中，
        因此不需要设置已访问的标志位
    */
    int longestIncreasingPath(vector<vector<int>>& matrix) 
    {
        int rows = matrix.size();
        int cols = matrix[0].size();

        if (rows == 0 || cols == 0) return 0;

        vector<vector<int> > memo(rows, vector<int>(cols, 0)); 

        int length = 0;
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                length = max(length, dfs(matrix, i, j, memo));
            }
        }

        return length;
    }

    int dfs(vector<vector<int> >& matrix, int x, int y, vector<vector<int> >& memo)
    {
        if (memo[x][y] != 0) return memo[x][y];

        // 此处加一是保证计算了(x, y)的点本身的这条路径，就是周围元素都小于它或者越界这种情况是不会运行到这条语句的
        memo[x][y]++;

        int rows = matrix.size();
        int cols = matrix[0].size();

        // 此处dfs的加一是因为dfs计算的是从(x, y)出发的递增路径的长度(不包括自身)，所以需要加上本身的长度
        if ((x + 1 >= 0) && (x + 1 < rows) && matrix[x + 1][y] > matrix[x][y])
            memo[x][y] = max(memo[x][y], dfs(matrix, x+1, y, memo) + 1);
        
        if ((x - 1 >= 0) && (x - 1 < rows) && matrix[x - 1][y] > matrix[x][y])
            memo[x][y] = max(memo[x][y], dfs(matrix, x-1, y, memo) + 1);
        
        if ((y + 1 >= 0) && (y + 1 < cols) && matrix[x][y+1] > matrix[x][y])
            memo[x][y] = max(memo[x][y], dfs(matrix, x, y+1, memo) + 1);

        if ((y - 1 >= 0) && (y - 1 < cols) && matrix[x][y-1] > matrix[x][y])
            memo[x][y] = max(memo[x][y], dfs(matrix, x, y-1, memo) + 1);

        return memo[x][y];
    }
};
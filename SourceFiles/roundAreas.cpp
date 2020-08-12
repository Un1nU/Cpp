#include <vector>

using namespace std;

class Solution 
{
private:
    // void dfs(vector<vector<char>>& board, int x, int y, vector<vector<bool>>& canFill, bool isborder)
    // {
    //     int rows = board.size();
    //     int cols = board[0].size();

    //     if (x < 0 || x >= rows || y < 0 || y >= cols || !canFill[x][y]) 
    //         return;

    //     if (board[x][y] == 'O' && canFill[x][y])
    //     {
    //         if (x == 0 || y == 0 || x == rows-1 || y == cols-1 || isborder)
    //         {
    //             canFill[x][y] = false;
                
    //             dfs(board, x+1, y, canFill, true);
    //             dfs(board, x-1, y, canFill, true);
    //             dfs(board, x, y+1, canFill, true);
    //             dfs(board, x, y-1, canFill, true);
    //         }
    //         else
    //         {
    //             canFill[x][y] = false;
    //             board[x][y] = 'X';

    //             dfs(board, x+1, y, canFill, false);
    //             dfs(board, x-1, y, canFill, false);
    //             dfs(board, x, y+1, canFill, false);
    //             dfs(board, x, y-1, canFill, false);
    //         }
            
    //     }
    // }

    /*解法2：先处理边界，再遍历修改*/
    void dfs(vector<vector<char>>& board, int x, int y)
    {
        int rows = board.size();
        int cols = board[0].size();

        if (x < 0 || x >= rows || y < 0 || y >= cols || board[x][y] != 'O') 
            return;

        board[x][y] = 'V';

        int dir[] = {0, 1, 0, -1, 0};

        for (int i = 0; i < 4; ++i)
        {
            int newx = x + dir[i];
            int newy = y + dir[i + 1];

            dfs(board, newx, newy);
        }
    }

public:
    void solve(vector<vector<char>>& board) 
    {
        int rows = board.size();
        if (rows == 0) return;

        int cols = board[0].size();
        if (cols == 0) return;
        
        for (int col = 0; col < cols; ++col)
        {
            if (board[0][col] == 'O')
                dfs(board, 0, col);

            if (board[rows-1][col] == 'O')
                dfs(board, rows-1, col);
        }

        for (int row = 0; row < rows; ++row)
        {
            if (board[row][0] == 'O')
                dfs(board, row, 0);
            
            if (board[row][cols-1] == 'O')
                dfs(board, row, cols-1);
        }

        for (int row = 0; row < rows; ++row)
        {
            for (int col = 0; col < cols; ++col)
            {
                if (board[row][col] == 'V')
                    board[row][col] = 'O';
                else if (board[row][col] == 'O')
                    board[row][col] = 'X';
            }
        }
        // vector<vector<bool>> canFill(rows, vector<bool>(cols, true));

        // for (int i = 0; i < rows; ++i)
        // {
        //     for (int j = 0; j < cols; ++j)
        //     {
        //         if (board[i][j] == 'O')
        //             dfs(board, i, j, canFill, false);
        //     }
        // }
    }
};
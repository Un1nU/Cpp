#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    /*解法1：回溯法（深度优先搜索DFS）
        矩阵行列大小为 m, n, 字符串长度为 k
        时间复杂度：O(mn*3^k):最差情况下，需要遍历矩阵中长度为 k 字符串的所有方案，时间复杂度为 O(3^k)；矩阵中共有 m*n 个起点，时间复杂度为 O(mn).
        方案数计算： 设字符串长度为 k，搜索中每个字符有上、下、左、右四个方向可以选择，舍弃回头（上个字符）的方向，剩下 3 种选择，因此方案数的复杂度为 O(3^k)
        空间复杂度：O(k+m*n):搜索的递归深度不超过k，因此占用栈空间O(k)，最坏情况下 k = m*n，需要分配 m*n大小的isVisited矩阵，占用空间 O(mn)

        优化：使用isVisited矩阵，导致了多余的空间利用，因此可以将访问过的位置 board[row][col] 设置为一非法字符（视具体情况而定），从而减少了空间复杂度
        空间复杂度： O(k)
    */
    bool exist(vector<vector<char>>& board, string word) 
    {
        vector<vector<bool> > isVisited(board.size(), vector<bool>(board[0].size(), false));

        for (int row = 0; row < board.size(); row++)
        {
            for (int col = 0; col < board[0].size(); col++)
            {
                if (isPath(board, row, col, word, 0))   return true;
            }
        }

        return false;
    }

    /* // 方法1：剑指offer方案
    bool isPath(const vector<vector<char> >& board, int row, int col, const string& word, int wordIdx, vector<vector<bool> >& isVisited)
    {
        if (wordIdx == word.length())   return true;

        bool isExist = false;
        if (row < 0 || row >= board.size() || col < 0 || col >= board[0].size() ||
            isVisited[row][col]) // 需要先判断，否则会对 isVisited 矩阵越界访问
            return false;

        if (board[row][col] == word[wordIdx])
        {
            isVisited[row][col] = true;
            isExist = isPath(board, row+1, col, word, wordIdx+1, isVisited) ||
                    isPath(board, row-1, col, word, wordIdx+1, isVisited) ||
                    isPath(board, row, col-1, word, wordIdx+1, isVisited) ||
                    isPath(board, row, col+1, word, wordIdx+1, isVisited);
        }

        if (!isExist)
            isVisited[row][col] = false;

        return isExist;
    }*/

    // 优化了 isVisited 矩阵的空间
    bool isPath(vector<vector<char> >& board, int row, int col, const string& word, int wordIdx)
    {
        if (wordIdx == word.length())   return true;

        bool isExist = false;
        if (row < 0 || row >= board.size() || col < 0 || col >= board[0].size() ||
            board[row][col] == '\0')
            return false;

        char temp = board[row][col]; // 需要保存一下当前的字符，如果下一步没有搜索到路径，则需要恢复
        if (board[row][col] == word[wordIdx])
        {
            board[row][col] = '\0';
            isExist = isPath(board, row+1, col, word, wordIdx+1) ||
                    isPath(board, row-1, col, word, wordIdx+1) ||
                    isPath(board, row, col-1, word, wordIdx+1) ||
                    isPath(board, row, col+1, word, wordIdx+1);
        }

        if (!isExist)
            board[row][col] = temp;

        return isExist;
    }
};

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<char> > board(n, vector<char>(m));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cin >> board[i][j];
    }

    string word;
    cin >> word;

    Solution sol;
    if (sol.exist(board, word))
        cout << "Exist" << endl;
    else
        cout << "Has not path" << endl;

    return 0;
}
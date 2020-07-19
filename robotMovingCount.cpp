#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    /*解法1：DFS（回溯法）*/
    int movingCount(int m, int n, int k) 
    {
        if (m == 0 || n == 0)  return 0;

        vector<vector<bool> > isVisited(m, vector<bool>(n, false));
        
        int cnt = 0;
        searchPath(isVisited, cnt, 0, 0, k); // 从(0,0)坐标开始搜索

        return cnt;
    }

    void searchPath(vector<vector<bool> >& isVisited, int& cnt, int row, int col, const int& k)
    {
        int rows = isVisited.size();
        int cols = isVisited[0].size();

        // 越界或不可达，返回上一步
        if (row < 0 || row >= rows || col < 0 || col >= cols || isVisited[row][col] || !canEnter(row, col, k))
            return;

        isVisited[row][col] = true;
        cnt++;

        searchPath(isVisited, cnt, row+1, col, k);
        //searchPath(isVisited, cnt, row-1, col, k); //隐式优化，机器人只需往右和下方搜索就可以搜索完整个路径
        searchPath(isVisited, cnt, row, col+1, k);
        //searchPath(isVisited, cnt, row, col-1, k);

    }

    bool canEnter(int row, int col, const int& k) // 判断位置是否可达
    {
        int sum = 0;

        while (row && col)
        {
            sum += (row % 10) + (col % 10);
            row /= 10;
            col /= 10;
        }

        while (row)
        {
            sum += row % 10;
            row /= 10;
        }

        while (col)
        {
            sum += col % 10;
            col /= 10;
        }

        if (sum > k)
            return false;
        else
            return true;
    }
};
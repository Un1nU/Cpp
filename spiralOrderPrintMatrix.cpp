#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void matrixSpiralPrint(const vector<vector<int>>& matrix, int row, int col, vector<int>& res)
    {
        int maxRow = matrix.size() - 1 - row; // 该次打印的行边界
        int maxCol = matrix[0].size() - 1 - col; // 该次打印的列边界

        if (col <= maxCol) // 只要存在一行，第一步打印就可以执行
        {
            for (int cols = col; cols <= maxCol; cols++)
                res.push_back(matrix[row][cols]);
        }

        if (row < maxRow) // 只要存在两行，第二步打印就可以执行
        {
            for (int rows = row + 1; rows <= maxRow; rows++)
                res.push_back(matrix[rows][maxCol]);
        }

        if (col < maxCol && row < maxRow) // 至少存在两行，两列，才能进行第三步打印
        {
            for (int cols = maxCol-1; cols >= col; cols--)
                res.push_back(matrix[maxRow][cols]);
        }

        if (maxRow - row > 1 && col < maxCol) // 至少存在三行，两列，才进行第四步打印
        {
            for (int rows = maxRow-1; rows > row; rows--)
                res.push_back(matrix[rows][col]);
        }
    }

    vector<int> spiralOrder(vector<vector<int>>& matrix) 
    {
        vector<int> res;
        if (matrix.empty()) return res;

        int sizeX = matrix.size();
        int sizeY = matrix[0].size();

        // 注意循环终止条件，打印起始点的行号和列号2倍 小于 矩阵的行列大小
        for (int row = 0, col = 0; sizeX > row*2 && sizeY > col*2; row++, col++)
        {
            matrixSpiralPrint(matrix, row, col, res);
        }

        return res;
    }
};
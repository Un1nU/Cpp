#include <vector>

using namespace std;

class Solution 
{
public:
    vector<vector<int>> generate(int numRows) 
    {
        vector<vector<int>> res(numRows);

        if (numRows == 0) return res;
        else if (numRows == 1)
        {
            res[0] = {1};
            return res;
        }
        else if (numRows == 2)
        {
            res[0] = {1};
            res[1] = {1, 1};
            return res;
        }

        res[0] = {1};
        res[1] = {1, 1};

        for (int i = 2; i < numRows; ++i)
        {
            res[i].resize(i + 1, 1);
            for (int j = 1; j < i; ++j)
            {
                res[i][j] = res[i - 1][j] + res[i - 1][j - 1];
            }
        }

        return res;
    }
};
#include <vector>

using namespace std;

class Solution 
{
private:
    vector<int> dir = {0, 1, 0, -1, 0};

    void dfs(vector<vector<int>>& image, int x, int y, int oldColor, int newColor)
    {
        int rows = image.size();
        int cols = image[0].size();

        if (x < 0 || x >= rows || y < 0 || y >= cols || image[x][y] != oldColor)
            return;

        image[x][y] = newColor;

        for (int i = 0; i < 4; ++i)
        {
            int newx = x + dir[i];
            int newy = y + dir[i + 1];

            dfs(image, newx, newy, oldColor, newColor);
        }
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) 
    {
        if (image.size() == 0) return image;

        int oldColor = image[sr][sc];

        if (oldColor != newColor) // 注意判断，如果颜色相等会造成无限递归
            dfs(image, sr, sc, oldColor, newColor);

        return image;
    }
};
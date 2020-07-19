#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

/*
8 8
*0******
*00**0**
**0**0**
**0**0**
*00000**
*****0**
*000000*
******0*
0 1
7 6
*/

int main()
{
    int n, m;
    cin >> n >> m;
    //cin.get();

    vector<vector<char> > maze(n, vector<char>(m));
    string rows;

    for (int i = 0; i < n; i++)
    {
        cin >> rows;
        for (int j = 0; j < m; j++)
        {
            maze[i][j] = rows[j];
        }
    }

    int entx, enty;
    int extx, exty;

    cin >> entx >> enty;
    cin >> extx >> exty;

    int curx = entx;
    int cury = enty;
    maze[curx][cury] = 'x';

    int incx[4] = {1, -1, 0, 0};
    int incy[4] = {0, 0, 1, -1};
    int direction = 0;
    vector<vector<int> > histPath;
    vector<int> beforePath(3);

    while(curx != extx && cury != exty)
    {
        if (direction <= 3)
        {
            int nextx = curx + incx[direction];
            int nexty = cury + incy[direction];

            if (nextx >= 0 && nextx < n && nexty >= 0 && nexty < m && maze[nextx][nexty] == '0')
            {
                beforePath[0] = curx;
                beforePath[1] = cury;
                beforePath[2] = direction;
                histPath.push_back(beforePath);
                curx = nextx;
                cury = nexty;
                maze[curx][cury] = 'x';
                direction = 0;
            }
            else
            {
                direction++;
            }
        }
        else
        {
            beforePath = histPath.back();
            histPath.pop_back();
            curx = beforePath[0];
            cury = beforePath[1];
            direction = beforePath[2] + 1;
        }        
    }

    for (auto paths : histPath)
        cout << "(" << paths[0] << "," << paths[1] << ")" << "-> "; // 栈中的历史路径
    cout << "(" << curx << "," << cury << ")" << "-> "; // 当前的坐标
    cout << "(" << extx << "," << exty << ")" << endl; // 出口坐标

    return 0;
}
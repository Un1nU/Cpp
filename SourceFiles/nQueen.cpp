#include <iostream>
#include <vector>

using namespace std;

bool CanPlace(const vector<int>& queens, int kth, int pos)
{
    for (int row = 0; row < kth; row++)
    {
        // 列减列等于行减行表明在同一主对角线上，副对角线则将等号的一边取相反数即可
        if ((queens[row] == pos) || (queens[row] - pos == row - kth) || (queens[row] - pos == kth - row)) 
            return false;
    }

    return true;
}

void PlaceQueens(vector<int>& queens, int k, int& cnt)
{
    if (queens.size() == k) // 当k == queens.size()时，说明已经放置完毕了，停止递归，打印结果
    {
        cnt++;
        cout << cnt << ":";
        for (auto x : queens)
            cout << x << " ";
        cout << endl;
        return;
    }
    else
    {
        for (int col = 0; col < queens.size(); col++) // 搜索第k行的每一列，找到能放置第k个皇后的位置
        {
            if (CanPlace(queens, k, col))
            {
                queens[k] = col;
                PlaceQueens(queens, k+1, cnt); // 递归放置下一个皇后
            }
        }

        return; // 如果没有找到放置的位置，回溯到上一个皇后的放置
    }
    
}

int main() // 递归法解决n皇后问题
{
    int n;
    cout << "How many queens you want to place:" << endl;
    cin >> n;

    // 由于每一行必定只能放置一个皇后，因此只需要一个n维的行向量来记录每个皇后放置的列数即可
    vector<int> queens(n, -1); 
    int count = 0;

    PlaceQueens(queens, 0, count);
    cout << endl;

    return 0;
}

// int main() // 迭代法解决n皇后问题
// {
//     int n;
//     cout << "How many queens you want to place:" << endl;
//     cin >> n;

//     vector<int> queens(n, -1);
//     int count = 0;
//     int row = 0;

//     while(row >= 0)
//     {
//         queens[row]++;
//         while(col < n && !CanPlace(queens, row, col))
//             queens[col]++;

//         if (col < n)
//         {
//             // queens[row] = col;

//             if (row == n-1)
//             {
//                 count++;
//                 for (auto x : queens)
//                     cout << x << " ";
//                 cout << endl;
//             }
//             else
//             {
//                 row++;
//                 queens[row] = -1;
//             }
            
//         }
//         else
//         {
//             row--;
//         }
        
//     }

//     cout << count << endl;

//     return 0;
// }
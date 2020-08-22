#include <vector>

using namespace std;

class Solution 
{
public:
    /*解法1：构建两个乘积数组，由于 B[i] = A[0] x A[1] x ... A[i-1] x A[i+1]x ...xA[n-1]
    因此，可以视为 B[i] 为两部分的乘积 B[i] = C[i] x D[i]
    其中， C[i] = A[0] x A[1] x ... x A[i-1]
          D[i] = A[i+1] x A[i+2] x ... x A[n-1]
    因此，可以正序构建 C[i]，即 C[i] = C[i-1] x A[i-1], C[0] = 1
            倒序构建 D[i]，即 D[i] = D[i+1] x A[i+1], D[n-1] = 1

    时间复杂度 O(n)
    空间复杂度 O(2n) = O(n)
    */
    // vector<int> constructArr(vector<int>& a) 
    // {
    //     int size = a.size();
    //     if (size == 0) return {};

    //     vector<int> b(size, 1);
    //     vector<int> c(size, 1);
    //     vector<int> d(size, 1);

    //     for (int i = 1; i < size; ++i)
    //     {
    //         c[i] = c[i - 1] * a[i - 1];
    //         d[size - i - 1] = d[size - i] * a[size - i]; 
    //     }

    //     for (int i = 0; i < size; ++i)
    //     {
    //         b[i] = c[i] * d[i];
    //     }

    //     return b;
    // }

    /*解法2：可以优化 C[i] 和 D[i] 占用的空间，可以根据对称矩阵来计算

    时间复杂度 O(n)
    空间复杂度 O(1)
    */
    vector<int> constructArr(vector<int>& a) 
    {
        int size = a.size();
        if (size == 0) return {};

        vector<int> b(size, 1);
        int right = 1;

        for (int i = 1; i < size; ++i)
        {
            b[i] *= b[i-1] * a[i-1]; // 下三角形

            right *= a[size - i];
            b[size - i - 1] *= right;
        }

        return b;
    }
};
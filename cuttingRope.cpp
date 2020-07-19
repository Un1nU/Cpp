#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    /*解法1：动态规划*/
    int cuttingRope(int n) 
    {
        if (n < 3)
            return 1;
        if (n == 3)
            return 2;

        vector<int> products(n+1, 0);

        products[0] = 0;
        products[1] = 1;
        products[2] = 2;
        products[3] = 3;

        for (int i = 4; i <= n; i++) // i表示绳子的长度
        {
            int maxProduct = i;
            int product = 0;

            for (int j = 1; j <= i/2; j++) // j表示切出来的长度，则i-j则是切断后剩余的长度
            {
                product = products[j] * products[i - j]; // products[j] 表示切出 j 长度（继续切分或不切分）的最大乘积；products[i - j]同理
                if (product > maxProduct) // 取 i （不切分）与 product[i]*product[i - j] （切分i与i-j）间最大
                    maxProduct = product;
            }

            products[i] = maxProduct;
        }

        return products[n+1];
    }

    /*解法2：贪心，切分出3的长度是最优的，而2的长度为次优，1的长度为最差
    对于长度为4的绳子，切出3x1 < 2x2，因此对于4的长度其实可以不切，但由于至少切1刀，因此选2x2切
    */
    int cuttingRope(int n) 
    {
        if (n < 3) return 1;
        if (n == 3) return 2;

        int timesOf3 = n / 3;
        int residual = n % 3;

        if (residual == 0) return pow(3, timesOf3);
        else if (residual == 1) return pow(3, timesOf3-1) * 4;
        else if (residual == 2) return pow(3, timesOf3) * 2;
    }

    int cuttingRope2(int n) 
    {
        if (n < 3) return 1;
        if (n == 3) return 2;

        const int mod = 1000000007;
        long maxProduct = 1;

        while (n > 4)
        {
            maxProduct *= 3;
            maxProduct %= mod;
            n -= 3;
        }

        return maxProduct * n % mod;
    }
};
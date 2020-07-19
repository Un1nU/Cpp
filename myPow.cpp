#include <iostream>
#include <string>
#include <math.h>

using namespace std;

const double EPSILON = 1e-6;

class Solution {
public:
    double myPow(double x, int n) 
    {

        /*x = 2.00000
        n = -2147483648
        由于使用循环来求次幂，会超时*/
        // if (n == 0 || fabs(x - 1.0) <= EPSILON) return 1.0;
        // if (fabs(x) <= EPSILON) return 0.0;

        // bool isNegativeExp = false;

        // // 因为abs(INT_MIN) 比 INT_MAX 大1， 所以不能直接取绝对值
        // if(n == INT32_MIN) 
        // {
        //     n = n >> 1;
        //     x = x * x;
        // }

        // if (n < 0)
        // {
        //     n = -n;
        //     isNegativeExp = true;
        // }

        // double result = unsignedPower(x, absExp);

        // if (isNegativeExp)
        //     result = 1.0 / result;

        // return result;

        /*快速幂解法，*/
        long exp = n;

        if (n < 0)
            return 1.0 / rmyPow(x, -exp);
        else
            return rmyPow(x, exp);
    }

    double unsignedPower(double base, int exponent)
    {
        double result = 1.0;

        for (int i = 0; i < exponent; i++)
            result *= base;

        return result;
    }

    double rmyPow(double x, long n)
    {
        if (n == 0 || fabs(x - 1.0) <= EPSILON) return 1.0;
        if (fabs(x) <= EPSILON) return 0.0;

        // 为了加快运算速度，使用位运算求余，使用%也可
        // 用 (n & 1) == 1 判断是否为奇数
        if ((n & 1) == 1) 
        {
            // double result = rmyPow(x, (n - 1) / 2);
            double result = rmyPow(x, n >> 1);
            return result*result*x;
        }
        else
        {
            // double result = rmyPow(x, n / 2);
            double result = rmyPow(x, n >> 1);  
            return result*result;
        }
    }
};
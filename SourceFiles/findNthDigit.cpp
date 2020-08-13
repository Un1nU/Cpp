#include <algorithm>

using namespace std;

class Solution 
{
public:
    int findNthDigit(int n)
    {
        if (n < 10) return n;

        long digit = 1; // 数位标记，1 表示个位数
        long beginNum = 1; // 具有 digit 位数字的起始数字
        long digitCnt = 9; // 十位数、百位数... 有 90、900 .. 9x10^(digit-1)个

        while (n > digitCnt) // 计算第 n 位数字属于几位数（个位、十位、百位……）
        {
            n -= digitCnt;

            ++digit;
            beginNum *= 10;
            digitCnt = 9 * beginNum * digit;
        }

        long num = beginNum + (n - 1) / digit; // n 所在的数字
        int numDigit = (n - 1) % digit; // n 在 num 中的第 numDigit 位

        string strNum = to_string(num); // 转化为 string 容易就能取出 numDigit 位

        return strNum[numDigit] - '0';
    }
};
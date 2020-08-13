class Solution 
{
public:
    /*解法1：找规律
    对于具有 x 位的整数 n，设其第 i 位为当前位 cur = n_i，
    则第 i 位的高位为 high = n_x n_x-1 ... n_i+1
    第 i 位的低位为 low = n_i-1 n_i-2 ... n_1
    因此固定第 i 位为 1 时，包含 1 的个数由其 高位high 和 低位low 的组合确定
    举例来说，对于数字 23101，如果取当前位为百位的1 cur = 1, digit = 100(表示cur所处十进制百位)
    从而 high = 23， low = 01，固定 cur 为 1 时，所有的可能为 23_1_01 ~ 00_1_00
    即有 2301 ~ 0000 = 2302 种可能，即 high * digit + low + 1 种 
    同理，当 cur 为 0 时， high = 231，low = 1，digit = 10，固定十位为1，则所有可能为 230_1_9 ~ 000_1_0
    即有 2309 ~ 0000 = 2310 种可能，即 high * digit
    当 cur > 1 时， 同理分析可得，有 (high + 1) * digit 种可能，详细见leetcode题解
    */
    int countDigitOne(int n) 
    {
        int high = n / 10;
        int low = 0;
        int cur = n % 10;
        long digit = 1;
        
        int numOf1 = 0;

        while (high != 0 || cur != 0)
        {
            if (cur == 0)
                numOf1 += high * digit;
            else if (cur == 1)
                numOf1 += high * digit + low + 1;
            else
                numOf1 += (high + 1) * digit;

            low = cur * digit + low;
            cur = high % 10;
            high /= 10;
            digit *= 10;
        }

        return numOf1;
    }
};
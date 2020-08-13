#include <string>
#include <limits.h>

using namespace std;

class Solution 
{
public:
    int strToInt(string str) 
    {
        int len = str.length();
        if (len < 1) return 0;

        int idx = 0;
        while (str[idx] == ' ') idx++;
        if (str[idx] != '-' && str[idx] != '+' && (str[idx] < '0' && str[idx] > '9') ) 
            return 0;

        long num = 0;
        bool isNagetive = false;
        if (str[idx] == '-')  
        {
            isNagetive = true;
            ++idx;
        }
        else if (str[idx] == '+') 
            ++idx;

        while (idx < len && str[idx] >= '0' && str[idx] <= '9')
        {
            int digit = str[idx] - '0';
            num = num * 10 + digit;

            if (num >= INT_MAX && !isNagetive) return INT_MAX;
            else if (num > INT_MAX && isNagetive) return INT_MIN;

            ++idx;
        }

        return isNagetive? -num : num;
    }
};
#include <string>

using namespace std;

class Solution 
{
public:
    string addStrings(string num1, string num2) 
    {
        int len1 = num1.length();
        int len2 = num2.length();

        if (len1 == 0) return num2;
        if (len2 == 0) return num1;

        string result(max(len1, len2) + 1, ' ');

        int idx1 = len1 - 1;
        int idx2 = len2 - 1;
        int idx3 = result.length() - 1;
        int carry = 0;

        while (idx1 >= 0 || idx2 >= 0)
        {
            int sum = 0;

            if (idx1 >= 0 && idx2 >= 0)
            {
                sum = (num1[idx1--] - '0') + (num2[idx2--] - '0') + carry;
            }
            else if (idx1 >= 0)
            {
                sum = (num1[idx1--] - '0') + carry;
            }
            else if (idx2 >= 0)
            {
                sum = (num2[idx2--] - '0') + carry;
            }

            if (sum >= 10)
            {
                sum -= 10;
                carry = 1;
            }
            else
            {
                carry = 0;
            }

            result[idx3--] = sum + '0';
            
        }

        if (carry) result[idx3] = carry + '0';

        if (result[0] == ' ') return string(result, 1);
        else return result;         
    }
};
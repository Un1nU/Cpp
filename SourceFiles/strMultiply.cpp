#include <string>

using namespace std;

class Solution 
{
private:
    string& addString(const string& num1, const string& num2)
    {
        string res;
        int idx1 = num1.length() - 1;
        int idx2 = num2.length() - 1;
        int carry = 0;

        while (idx1 >= 0 || idx2 >= 0 || carry != 0)
        {
            int sum = carry;

            if (idx1 >= 0) sum += num1[idx1] - '0';
            if (idx2 >= 0) sum += num2[idx2] - '0';

            if (sum >= 10)
            {
                carry = sum / 10;
                sum -= 10;
            }
            res.push_back(sum + '0');

            --idx1;
            --idx2;
        }

        reverse(res.begin(), res.end());
   
        return res;
    }

public:
    /*解法1：模拟竖式加法，三位数相乘时，会timeout

    时间复杂度 O(mn + n^2)
    空间复杂度 O(m + n)
    */
    // string multiply(string num1, string num2) 
    // {
    //     if (num1 == "0" || num2 == "0") return "0";

    //     int len1 = num1.length();
    //     int len2 = num2.length();
    //     int numBit = 1;
    //     string res;

    //     for (int i = len2 - 1; i >= 0; --i)
    //     {
    //         int digit = num2[i] - '0';
    //         int carry = 0;
    //         int mulRes = 0;
    //         int bits = 1;
    //         string strMul;

    //         for (int j = len1 - 1; j >= 0; --j)
    //         {   
    //             int a = num1[j] - '0';
    //             int mul = a * digit + carry;

    //             if (mul >= 10)
    //             {
    //                 carry = mul / 10;
    //                 mul = mul % 10;
    //             }

    //             mulRes += mul * bits;
    //             bits *= 10;
    //         }

    //         strMul = to_string(mulRes * numBit);
    //         res = addString(res, strMul);
    //         numBit *= 10;
    //     }

    //     return res;
    // }


    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") {
            return "0";
        }
        int m = num1.size(), n = num2.size();
        auto ansArr = vector<int>(m + n);
        for (int i = m - 1; i >= 0; i--) {
            int x = num1.at(i) - '0';
            for (int j = n - 1; j >= 0; j--) {
                int y = num2.at(j) - '0';
                ansArr[i + j + 1] += x * y;
            }
        }
        for (int i = m + n - 1; i > 0; i--) {
            ansArr[i - 1] += ansArr[i] / 10;
            ansArr[i] %= 10;
        }
        int index = ansArr[0] == 0 ? 1 : 0;
        string ans;
        while (index < m + n) {
            ans.push_back(ansArr[index]);
            index++;
        }
        for (auto &c: ans) {
            c += '0';
        }
        return ans;
    }
};
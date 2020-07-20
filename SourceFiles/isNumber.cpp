#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    /*
        整数或小数的模式可以写为 A[.[B]][e|EC]或者.B[e|EC]
        其中，A、B、C都表示一串连续的数字
    */

    //　　函数功能：扫描数字串，当遇到非数字字符时，返回主函数中判断出现的非数字字符是'.'还是'e'，
    //如果都不是，则表明出现了其他字符，此时isNum = true 而 sIter != sEnd，主函数返回false。
    bool scanNumber(string::iterator& sIter, string::const_iterator sEnd)
    {
        bool haveNumber = false;

        while (sIter != sEnd)
        {
            if (*sIter >= '0' && *sIter <= '9')
            {
                haveNumber = true;
                sIter++;
            }
            else
                break;
        }

        return haveNumber;
    }

    //　　函数功能：扫描数字串是否为有符号数，如果遇到一个符号位，则跳过后进行数字串的扫描
    bool scanInteger(string::iterator& sIter, string::const_iterator sEnd)
    {
        if (*sIter == '+' || *sIter == '-') sIter++;

        return scanNumber(sIter, sEnd);
    }
 
    bool isNumber(string s) 
    {
        if (s.size() == 0) return false;

        int sBeginIdx = 0;
        int sEndIdx = s.size() - 1;

        while (s[sBeginIdx] == ' ' && sBeginIdx <= sEndIdx) sBeginIdx++; // 去掉字符串前后的空格
        while (s[sEndIdx] == ' ' && sBeginIdx <= sEndIdx) sEndIdx--;

        if (sBeginIdx <= sEndIdx)
            s = s.substr(sBeginIdx, sEndIdx-sBeginIdx+1);
        else
            return false;

        auto sIter = s.begin();
        const auto sEnd = s.end();

        bool isNum = scanInteger(sIter, sEnd);

        if (*sIter == '.')
        {
            sIter++;
            // 只要满足小数点前为数字串(123.)或者小数点后为数字串(.5123)，或者两者均满足(123.5123)就是合法，因此使用 ||
            // isNum需要放在||运算符的右边，否则会产生短路效应，不对小数点后的字符进行判断
            isNum = scanNumber(sIter, sEnd) || isNum; 
        }

        if (*sIter == 'e') // leetcode上只有'e'合法，而'E'不合法
        {
            sIter++;
            // 需要满足e符号前为数字串同时e之后为有符号数字串才合法，因此使用 && 
            isNum = isNum && scanInteger(sIter, sEnd);
        }

        // 当字符串中的只出现一次'+', '-', '.', 'e'或者都不出现才可能扫描完毕，因此需要加入 sIter == sEnd判断
        return isNum && sIter == sEnd; 
    }
};

int main()
{
    Solution sol;
    string str;

    while(cin >> str)
        if (sol.isNumber(str))
            cout << "It is a number." << endl;
        else
            cout << "It isn't a number." << endl;

    return 0;
} 
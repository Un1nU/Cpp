/*
写出一个程序，接受一个十六进制的数，输出该数值的十进制表示。（多组同时输入）

输入描述:
输入一个十六进制的数值字符串。

输出描述:
输出该数值的十进制字符串。

输入例子1:
0xA

输出例子1:
10
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
    string hex;
    unordered_map<char, int> hex2dec = {
        {'F', 15}, {'E', 14}, {'D', 13},
        {'C', 12}, {'B', 11}, {'A', 10},
        {'9', 9}, {'8', 8}, {'7', 7},
        {'6', 6}, {'5', 5}, {'4', 4},
        {'3', 3}, {'2', 2}, {'1', 1},
        {'0', 0}};

    while (cin >> hex)
    {
        int len = hex.length();
        int dec = 0;
        int digit = 1;

        for (int i = len - 1; i >= 2; --i)
        {
            int bits = hex2dec[hex[i]];
            dec += bits * digit;
            digit *= 16;
        }

        cout << dec << endl;
    }

    return 0;
}
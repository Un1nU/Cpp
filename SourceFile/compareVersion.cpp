#include <iostream>
#include <string>
using namespace std;

class Solution 
{
public:
    int compareVersion(string version1, string version2) 
    {
        int len1 = version1.length();
        int len2 = version2.length();

        int idx1, idx2;
        // int verNo1, verNo2;
        int start1, start2;

        idx1 = idx2 = 0;
        start1 = start2 = 0;

        while (idx1 < len1 || idx2 < len2)
        {
            int verNo1 = 0;
            int verNo2 = 0;

            while (idx1 < len1 && version1[idx1] != '.')
            {
                verNo1 += verNo1 * 10 + version1[idx1] - '0';
                idx1++;
            }

            while (idx2 < len2 && version2[idx2] != '.')
            {
                verNo2 += verNo2 * 10 + version2[idx2] - '0';
                idx2++;
            }

            // while (idx1 < len1 && version1[idx1] != '.') idx1++;
            // while (idx2 < len2 && version2[idx2] != '.') idx2++;

            // if (start1 == idx1) // 当到版本号长度不一致时，较短的用0表示
            //     verNo1 = 0;
            // else
            //     verNo1 = stoi(version1.substr(start1, idx1 - start1));

            // if (start2 == idx2)
            //     verNo2 = 0;
            // else
            //     verNo2 = stoi(version2.substr(start2, idx2 - start2));

            if (verNo1 > verNo2)
                return 1;
            else if (verNo1 < verNo2)
                return -1;

            idx1++; // 此时 idx1 指向'.'的位置，如果不加1，则下一轮循环不会进入while搜索下一位
            idx2++; // 同上
            // start1 = idx1;
            // start2 = idx2;
        }

        return 0;
    }
};

int main()
{
    Solution sol;

    string version1 = "1.0.1";
    string version2 = "1.0.1.1";

    sol.compareVersion(version1, version2);

    return 0;
}
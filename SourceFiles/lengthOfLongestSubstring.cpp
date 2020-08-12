#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution 
{
public:
    int lengthOfLongestSubstring(string s) 
    {
        int len = s.length();
        if (len < 2) return len;

        vector<int> hashMap(128, -1);

        // start 初始化为 -1，防止连续不重复的情况 "abcde"，少计算 start 位置字符数
        int start = -1, end = 0; 
        int maxLen = 0;

        while (end < len)
        {
            if (hashMap[s[end]] == -1) 
                hashMap[s[end]] = end;
            else
            {
                // maxLen = max(maxLen, end - start);
                // start = hashMap[s[end]];             
                start = max(start, hashMap[s[end]]); // 取max()，避免 "abba" 产生的 start 指针回退情况
                hashMap[s[end]] = end; // 其实可以放到 if 外面，但是这样写容易理解
            }

            maxLen = max(maxLen, end - start); // 每步都更新结果，防止 "aaa" 跳出循环后，start 指针未更新

            ++end;
        }

        return maxLen;
    }
};
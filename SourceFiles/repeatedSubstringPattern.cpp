#include <vector>
#include <string>

using namespace std;

class Solution 
{
private:
    vector<int> getNext(const string& pattern)
    {
        int len = pattern.length();
        vector<int> next(len+1);
        next[0] = -1;

        int right = 0;
        int left = -1;
        while (right <= len - 1) // 注意是 <=，因为需要求出最后一个字符的匹配位置
        {
            if (left == -1 || pattern[right] == pattern[left])
            {
                ++right;
                ++left;
                next[right] = left; 
            }
            else
            {
                left = next[left];
            }
        }

        return next;
    }

public:
    bool repeatedSubstringPattern(string s) 
    {
        int len = s.length();
        if (len < 2) return false;

        vector<int> next = getNext(s);

        // next.back() > 0 表示字符串存在最长公共前后缀
        // len - next.back() 表示最长公共前后缀的长度
        return next.back() && (len % (len - next.back()) == 0);
    }
};
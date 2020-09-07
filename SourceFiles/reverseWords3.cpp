#include <string>
#include <algorithm>

using namespace std;

class Solution 
{
private:
    void reverseWord(string& s, int start, int end)
    {
        for (int i = start, j = end-1; i <= j; ++i, --j)
            swap(s[i], s[j]);
    }
    
public:
    string reverseWords(string s) 
    {
        int len = s.length();
        if (len < 2) return s;

        for (int idx = 0; idx < len; ++idx)
        {
            int end = idx;
            while (s[end] != ' ' && end < len) ++end;

            reverseWord(s, idx, end);
            idx = end;
        }

        return s;
    }
};
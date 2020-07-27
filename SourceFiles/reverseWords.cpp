#include <iostream>

using namespace std;

class Solution 
{
public:
    string reverseWords(string s) 
    {
        if (s == "") return s;

        int beginIdx = 0;
        int endIdx = s.length() - 1;

        while (s[beginIdx] == ' ' && beginIdx <= endIdx) beginIdx++;
        while (s[endIdx] == ' ' && beginIdx <= endIdx) endIdx--;
        
        if (beginIdx > endIdx) return "";
 
        s = s.substr(beginIdx, endIdx-beginIdx+1);

        string rs;

        int idx = endIdx - beginIdx;

        while (idx >= 0)
        {
            while (idx >= 0 && s[idx] != ' ') idx--;
            
            rs += s.substr(idx+1, endIdx-idx);

            if (idx < 0) break;
            while (idx >= 0 && s[idx] == ' ') idx--;

            endIdx = idx;
            rs += ' ';
        }

        return rs;
    }
};
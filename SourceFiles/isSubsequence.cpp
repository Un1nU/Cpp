#include <iostream>

using namespace std;

class Solution 
{
public:
    /*解法1：双指针法*/
    bool isSubsequence(string s, string t) 
    {
        int len1 = s.length();
        int len2 = t.length();

        if (len1 == 0) return true;
        if (len2 == 0) return false;

        int idx1 = 0;
        int idx2 = 0;

        while (idx1 < len1 && idx2 < len2)
        {
            while (idx2 < len2 && s[idx1] != t[idx2]) idx2++;

            if (s[idx1] == t[idx2])
            {
                idx1++;
                idx2++;
            }
        }

        return idx1 == len1;
    }

};
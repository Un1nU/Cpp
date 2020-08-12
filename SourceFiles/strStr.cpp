#include <string>
#include <vector>

using namespace std;

class Solution 
{
private:
    vector<int> getNext(const string& pattern)
    {
        vector<int> nextVal;
        if (pattern == "") return nextVal;
        
        int len = pattern.length();
        nextVal.resize(len);
        nextVal[0] = -1;

        int left = -1;
        int right = 0;

        while (right < len)
        {
            if (left == -1 || pattern[left] == pattern[right])
            {
                ++left;
                ++right;
                nextVal[right] = left; 
            }
            else
            {
                left = nextVal[left];
            }
        }

        return nextVal;
    }

public:
    int strStr(string haystack, string needle) 
    {
        int len1 = haystack.length();
        int len2 = needle.length();

        if (len1 < len2) return -1;
        if (len2 == 0) return 0;

        vector<int> next = getNext(needle);
        int idx1 = 0;
        int idx2 = 0;

        int match = 0;
        while (idx1 < len1 && idx2 < len2)
        {
            if (haystack[idx1] == haystack[idx2])
            {
                idx1++;
                idx2++;
            }
            else
            {
                idx2 = next[idx2];
            }
            
        }

        if (idx2 == len2) return idx1 - idx2;
        else return -1;
    }
};
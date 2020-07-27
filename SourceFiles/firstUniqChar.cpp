#include <vector>
#include <iostream>

using namespace std;

class Solution 
{
public:
    char firstUniqChar(string s) 
    {
        if(s.empty()) return ' ';
        
        vector<int> isFirst(26, 0);

        for (int i = 0; i < s.length(); i++)
        {
            int idx = s[i] - 'a';

            isFirst[idx]++;
        }

        for (int i = 0; i < s.length(); i++)
        {
            int idx = s[i] - 'a';

            if (isFirst[idx] == 1)
                return s[i];
        }

        return ' ';
    }
};
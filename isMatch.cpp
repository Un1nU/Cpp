#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) 
    {
        int len_s = s.length();
        int len_p = p.length();

        if (len_s == 0 && len_p == 0) return true;

        bool dp[len_s+1][len_p+1];

        for (int i = 0; i <= len_s; i++)
        {
            for (int j = 0; j <= len_p; j++)
            {
                if (j == 0 && i == 0)
                    dp[i][j] = true;
                else if (j == 0)
                    dp[i][j] = false;
                else if (p[j - 1] != '*')
                {   
                    if (i > 0 && (p[j - 1] == s[i - 1] || p[j - 1] == '.'))
                        dp[i][j] = dp[i - 1][j - 1];
                }
                else
                {
                    if ((i > 0 && p[j - 2] == s[i - 1]) || (p[j - 2] == '.'))
                        dp[i][j] = dp[i - 1][j - 2];
                }
            }
        }
    }
};
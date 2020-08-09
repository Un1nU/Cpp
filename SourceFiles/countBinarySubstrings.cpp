#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution 
{
public:
    /*解法1：题目要求组成01连续的二进制子串，举例来说
    对于字符串 000111，先统计连续的 0 的个数, cur = 3
    遇到1时， pre = cur = 3，此时 cur = 1，即表示 遇到的第一个 1 可以与 0 组成01连续二进制子串，
    往后依然为 1 , cur = 2 <= pre，因此依然可以与 前面的0，组成长度为4的子串，
    再往后 cur = 3，同理*/
    int countBinarySubstrings(string s) 
    {
        if (s.length() < 2) return 0;

        /*由于 counts[i] 只与 counts[i-1] 有关，因此可以不必用数组存储*/
        // vector<int> counts;
        
        // int cnt = 1;
        // for (int i = 1; i < s.length(); ++i)
        // {   
        //     if (s[i] == s[i - 1]) cnt++;
        //     else
        //     {
        //         counts.push_back(cnt);
        //         cnt = 1;
        //     }
        // }
        // counts.push_back(cnt);

        // cnt = 0;
        // for (int i = 1; i < counts.size(); ++i)
        // {
        //     cnt += min(counts[i], counts[i-1]);
        // }

        // return cnt;

        int cnt = 0;
        int cur = 1;
        int pre = 0;

        for (int i = 1; i < s.length(); ++i)
        {
            if (s[i] == s[i - 1]) 
                cur++;
            else
            {
                pre = cur;
                cur = 1;
            }

            if (cur <= pre) cnt++;
        }

        return cnt;
    }
};
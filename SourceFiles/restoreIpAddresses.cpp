#include <string>
#include <vector>

using namespace std;

class Solution 
{
private:
    void dfs(const string& s, vector<string>& res, vector<string>& seg, int begin, int segNum)
    {
        if (segNum == 4) // 已经分了四段
        {
            if (begin == s.length()) // 已经遍历完了 s，说明有可行解，记录到res中，并回溯
            {
                string ip;

                for (int i = 0; i < 3; ++i)
                    ip += seg[i] + '.';
                ip += seg[3];

                res.push_back(ip);
            }

            return; // 如果已经分成了四段，还没有遍历完 s，说明不是合法的IP，回溯
        }

        if (begin == s.length()) return; // 如果已经遍历完 s，但是没有切分成四段，也不是合法的IP，回溯

        if (s[begin] == '0') // IP不存在前导0，如果遇到 0 则直接作为地址的一段
        {
            seg[segNum] = '0';
            dfs(s, res, seg, begin+1, segNum+1);
        }

        // int addr = 0;
        for (int i = begin; i < s.length(); ++i) // 一般情况，以每 i 位作为切分点，从 i+1 位dfs
        {
            string temp = s.substr(begin, i-begin+1);
            int addr = stoi(temp);

            if (addr > 0 && addr <= 255)
            {
                // seg[segNum] = to_string(addr);
                seg[segNum] = temp;
                dfs(s, res, seg, i+1, segNum+1);
                // seg.pop_back(); // 使用segNum来填写结果的，无需pop_back，因为回溯后仍可用 seg[segNum] 覆盖
            }
            else // addr 非法，可以直接结束搜索，回溯
                break;
        }
    }

public:
    vector<string> restoreIpAddresses(string s) 
    {
        int len = s.length();
        if (len < 4 || len > 12) return {};

        vector<string> res;
        vector<string> seg(4);
        dfs(s, res, seg, 0, 0);

        return res;
    }
};
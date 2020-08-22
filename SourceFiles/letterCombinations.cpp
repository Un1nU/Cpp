#include <vector>
#include <string>

using namespace std;

class Solution 
{
private:
    // 存储号码映射表
    vector<string> table = {" ", "", "abc", 
                            "def", "ghi", "jkl", 
                            "mno", "pqrs", "tuv",
                            "wxyz"};

    /* idx 表示遍历到的 digits 数位，
       current 存储当前的字母排列，当长度为 digits.length()，表示一个排列结果 
    */
    void dfs(int idx, const string& digits, string& current, vector<string>& res)
    {
        if (idx == digits.length())
        {
            res.push_back(current);
            return;
        }

        string curNum = table[digits[idx] - '0'];
        for (int i = 0; i < curNum.length(); ++i)
        {
            current.push_back(curNum[i]); // 进行下一位的排列
            dfs(idx+1, digits, current, res);
            current.pop_back(); // 回溯
        }
    }

public:
    vector<string> letterCombinations(string digits) 
    {
        vector<string> res;
        if (digits.empty()) return res;
        string current;

        dfs(0, digits, current, res);

        return res;
    }
};
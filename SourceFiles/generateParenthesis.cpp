#include <vector>
#include <string>

using namespace std;

class Solution 
{
private:
    /*解法1：DFS

    生成的任何括号组合中都有两个规律：
    1，括号组合中左括号的数量等于右括号的数量
    2，括号组合中任何位置左括号的数量都是大于等于右括号的数量
    第一条很容易理解，我们来看第二条，比如有效括号"(())()"，在任何一个位置右括号的数量都不大于左括号的数量，所以他是有效的。
    如果像这样"())()"第3个位置的是右括号，那么他前面只有一个左括号，而他和他前面的右括号有2个，所以无论如何都不能组合成有效的括号。

    cur 表示当前的生成结果， leftNum, rightNum 分别表示左右括号 剩余 的个数
    */
    void dfs(string cur, int leftNum, int rightNum, vector<string>& res)
    {
        if (leftNum == 0 && rightNum == 0)
        {
            res.push_back(cur);
            return;
        }
        
        if (leftNum > 0)    // 只有左括号数量大于 0 才能选左括号，小于等于 0 时还可以选右括号
            dfs(cur + '(', leftNum - 1, rightNum, res);

        if (leftNum < rightNum) // 当左括号剩余个数比右括号少时（相当于 cur 中左括号比右括号多），才可以选择右括号
            dfs(cur + ')', leftNum, rightNum - 1, res);
    }

public:
    vector<string> generateParenthesis(int n) 
    {
        vector<string> res;
        dfs("", n, n, res);

        return res;
    }
};
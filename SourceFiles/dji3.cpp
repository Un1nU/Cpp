#include <string>
#include <stack>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    string num;
    int k;

    cin >> num >> k;

    stack<char> stk;
    int len = num.length();

    for (int i = 0; i < len; ++i)
    {
        while (!stk.empty() && stk.top() > num[i] && k)
        {
            k--;
            stk.pop();
        }

        stk.push(num[i]);
    }

    string res;

    while (!stk.empty())
    {
        if (k > 0)
            k--;
        else if (k == 0)
            res += stk.top();

        stk.pop();
    }

    reverse(res.begin(), res.end());

    int idx = 0;
    while (idx < res.length() && res[idx] == '0') ++idx;

    if (idx == res.length())
        cout << "0" << endl;
    else
        cout << res.substr(idx, res.length() - idx) << endl;

    return 0;
}
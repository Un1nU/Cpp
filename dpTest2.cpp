#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> money(n);
    for (int i = 0; i < n; i++)
        cin >> money[i];

    vector<int> dp(n);
    dp[0] = money[0];
    dp[1] = max(money[0], money[1]);

    for (int i = 2; i < n; i++)
    {
        dp[i] = max(money[i]+dp[i-2], dp[i-1]);
    }

    return 0;
}
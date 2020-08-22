#include <vector>
#include <iostream>

using namespace std;

int main()
{
    int n, x;
    cin >> n >> x;

    vector<int> a(n, 0);
    vector<int> b(n, 0);

    for (int i = 0; i < n; ++i)
    {
        cin >> a[i] >> b[i];
    }

    vector<vector<int>> f(n+1, vector<int>(x+1, 0));

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= x; ++j)
        {
            if (j - b[i - 1] >= 0)
                f[i][j] = max(f[i - 1][j], f[i - 1][j - b[i - 1]] + a[i - 1]);
            else
                f[i][j] = f[i - 1][j];
        }
    }

    cout << f[n][x] << endl;

    return 0;
}
#include <iostream>

using namespace std;

int gcd(int x, int y)
{
    int res = x % y;
    if (res == 0) return y;
    
    while (res)
    {
        x = y;
        y = res;
        res = x % y;
    }

    return y;
}

int main()
{
    int x, y;
    cin >> x >> y;

    cout << gcd(x, y) << endl;

    return 0;
}
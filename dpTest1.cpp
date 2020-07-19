#include <iostream>
#include <vector>

using namespace std;


/*
8
5 1 8 4 6 3 2 4
1 3 0 4 3 5 6 8
4 5 6 7 8 9 10 11
*/
int main()
{
    int n;
    cin >> n;
    
    vector<int> profit(n);
    vector<int> start(n);
    vector<int> finish(n);

    for (int i = 0; i < n; i++)
        cin >> profit[i];
    
    for (int i = 0; i < n; i++)
        cin >> start[i];

    for (int i = 0; i < n; i++)
        cin >> finish[i];

    vector<int> opt(n, 0);
    vector<int> pre(n);
    pre[0] = -1;
    opt[0] = profit[0];
    
    for (int i = n-1; i > 0; i--)
    {
        int j = i;
        while (start[i] < finish[--j] && j >= 0);
        pre[i] = j;  
    }

    for (int i = 1; i < n; i++)
    {
        if (pre[i] == -1)
            opt[i] = max(profit[i], opt[i-1]);
        else
            opt[i] = max(profit[i]+opt[pre[i]], opt[i-1]);
    }

    for (auto item : opt)
        cout << item << " ";
    cout << endl;

    return 0;
}
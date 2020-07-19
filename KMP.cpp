#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> getNext(string pattern)
{
    int pLen = pattern.length();
    vector<int> next(pLen);
    next[0] = -1;

    int k = -1;
    int j = 0;

    while (j < pLen - 1)
    {
        if (k == -1 || pattern[k] == pattern[j])
        {
            k++;
            j++;
            next[j] = k;
        }
        else
            k = next[k];
    }

    return next;
}

int main()
{
    string str;
    string pattern;
/*acacabacacabacacac*/
    //cin >> str;
    cin >> pattern;

    vector<int> next = getNext(pattern);

    for (auto item : next)
        cout << item << " ";
    cout << endl;

    return 0;
}
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main()
{
    int N,value;
    cin >> N;
    vector<int> arr;
    map<int,int> duMap;

    for(int i = 0; i < N; i++)
    {
        cin >> value;
        arr.push_back(value);
        duMap[value] = i;
    }

    sort(arr.begin(), arr.end());

    int index = N, count = 0;
    for(int i = 0; i < N - 1; i++)
    {
        if(duMap[arr[i]] > duMap[arr[i + 1]])
        {
            duMap[arr[i + 1]] = index++;
            count++;
        }
    }

    cout << count;

    system("pause");
    return 0;
}
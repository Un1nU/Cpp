#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<int> arr = {1, 3, 4, 6, 3, 7, 8};
    vector<int> res;

    int len = arr.size();
    vector<int> leftMax(len);
    vector<int> rightMin(len);

    leftMax[0] = INT32_MIN;
    for (int i = 1; i < len; i++)
    {
        if (arr[i-1] > leftMax[i-1])
            leftMax[i] = arr[i-1];
        else 
            leftMax[i] = leftMax[i-1];
    }

    rightMin[len-1] = INT32_MAX;
    for (int i = len-2; i >= 0; i--)
    {
        if (arr[i+1] < rightMin[i+1])
            rightMin[i] = arr[i+1];
        else
            rightMin[i] = rightMin[i+1];
    }

    for (int i = 0; i < len; i++)
    {
        if (arr[i] > leftMax[i] && arr[i] < rightMin[i])
            res.push_back(arr[i]);
    }

    return 0;
}
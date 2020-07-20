#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> arr = {1,3,5,7,9,11,13,8,1};

    int left = 0;
    int right = arr.size() - 1;
    int mid = left;

    while (left <= right)
    {
        mid = left + (right - left) / 2;

        if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1])
        {
            cout << arr[mid] << endl;
            break;
        }
        else if (arr[mid] > arr[mid + 1])
            right = mid - 1;
        else if (arr[mid] > arr[mid - 1])
            left = mid + 1;          
    }

    return 0;
}
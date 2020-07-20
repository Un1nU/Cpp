#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) 
    {
        if (nums.size() == 0) return 0;

        int left = 0;
        int right = nums.size() - 1;
        int mid;

        while (left <= right)
        {
            mid = left + (right - left) / 2;

            if (nums[mid] > target)
                right = mid - 1;
            else if (nums[mid] < target)
                left = mid + 1;
            else
                return mid;
        }

        return left;
    }
};
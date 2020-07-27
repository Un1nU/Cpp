#include <iostream>
#include <vector>

using namespace std;

class Solution 
{
public:
    int search(vector<int>& nums, int target) 
    {
        if (nums.size() < 1) return 0;

        int left = 0;
        int right = nums.size() - 1;
        int mid = left;

        while (left <= right)
        {
            mid = left + (right - left) / 2;

            if (nums[mid] >= target)
                right = mid - 1;
            else
                left = mid + 1;
        }

        int leftBound = right;

        left = 0;
        right = nums.size() - 1;
        while (left <= right)
        {
            mid = left + (right - left) / 2;

            if (nums[mid] > target)
                right = mid - 1;
            else 
                left = mid + 1;
        }

        int rightBound = left;

        return rightBound - leftBound - 1;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {5, 7, 7, 8, 8, 10};
    int target = 8;
    sol.search(nums, target);

    return 0;
}
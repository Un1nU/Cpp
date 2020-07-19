#include <vector>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) 
    {
        vector<int> res(2, -1);
        if (nums.size() == 0) return res;

        res[0] = left_bound(nums, target);
        res[1] = right_bound(nums, target);

        return res;
    }

    int left_bound(const vector<int>& nums, const int target)
    {
        if (nums.size() == 0) return -1;

        int left = 0;
        int right = nums.size() - 1;

        while (left <= right)
        {
            int middle = left + (right - left) / 2;

            if (nums[middle] < target)
                left = middle + 1;
            else if (nums[middle] > target)
                right = middle - 1;
            else if (nums[middle] == target)
                right = middle - 1;
        }

        if (left >= nums.size() || nums[left] != target)
            return -1;
        else
            return left;
    }

    int right_bound(const vector<int>& nums, const int target)
    {
        if (nums.size() == 0) return -1;

        int left = 0;
        int right = nums.size() - 1;

        while (left <= right)
        {
            int middle = left + (right - left) / 2;

            if (nums[middle] < target)
                left = middle + 1;
            else if (nums[middle] > target)
                right = middle - 1;
            else if (nums[middle] == target)
                left = middle + 1;
        }

        if (right < 0 || nums[right] != target)
            return -1;
        else
            return right;
    }
};
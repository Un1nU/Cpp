#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        vector<int> res;
        if (nums.size() <= 1) return res;

        int left = 0;
        int right = nums.size() - 1;

        while (left < right)
        {
            if (nums[left] + nums[right] > target)
                right--;
            else if (nums[left] + nums[right] < target)
                left++;
            else 
            {
                res.push_back(nums[left]);
                res.push_back(nums[right]);
                break;
            }
        }

        return res;
    }
};
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        vector<vector<int> > res;
        if (nums.size() < 3) return res;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++)
        {
            if (i > 0 && nums[i] == nums[i-1]) // 保证取值不重复
                continue;

            int start = i + 1;
            int end = nums.size() - 1;

            while (start < end)
            {
                int sum = nums[i] + nums[start] + nums[end];
                
                if (sum < 0)
                {
                    start++;
                    while (nums[start] == nums[start-1] && start < end) start++; // 保证一下次取值不重复
                }
                else if (sum > 0)
                {
                    end--;
                    while (nums[end] == nums[end+1] && start < end) end--; // 同上
                }
                else if (sum == 0)
                {
                    res.push_back({nums[i], nums[start], nums[end]});
                    start++;
                    end--; //由于start增加，nums[start]变大，要保持和不变，nums[end]就必须减小
                    while (nums[start] == nums[start-1] && start < end) start++; // 保证取的不是相同值
                    while (nums[end] == nums[end+1] && start < end) end--;
                }
            }
        }

        return res;
    }
};
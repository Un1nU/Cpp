#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    /*
    解法1：排序+双指针，排序后，对于每个nums[i]进行一次双指针遍历搜索
        时间复杂度： O(nlogn) + O(n^2) = O(n^2)
        空间复杂度： O(logn) 排序使用空间
        
        可优化空间：保证每次判断不取重复的元素，如果遇到重复的元素则跳过
    */
    int threeSumClosest(vector<int>& nums, int target) 
    {   
        int minSum = nums[0]+nums[1]+nums[2];
        if (nums.size() == 3) return minSum;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++)
        {
            int start = i + 1;
            int end = nums.size() - 1;

            while (start < end)
            {
                int curSum = nums[i] + nums[start] + nums[end];
                if (abs(curSum - target) < abs(minSum - target))
                    minSum = curSum;

                if (curSum > target)
                    end--;
                else if (curSum < target)
                    start++;
                else if (curSum == target)
                    return curSum;
            }
        }

        return minSum;
    }
};
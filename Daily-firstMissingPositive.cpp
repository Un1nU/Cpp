#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) 
    {
        /*遍历数组，将出现的正数插入到有序集合中，然后遍历集合，找到缺失的正数
        时间复杂度:O(n)
        空间复杂度:O(n)，不满足O(1)的要求
        */
        // if (nums.size() == 0) return 1;

        // set<int> numsSet;

        // for (int i = 0; i < nums.size(); i++)
        // {
        //     if (nums[i] > 0 && !numsSet.count(nums[i]))
        //         numsSet.insert(nums[i]);
        // }

        // int missing = 1;
        // for (auto num : numsSet)
        // {
        //     if (num > 0 && num == missing)
        //         missing++;
        //     else if (num > 0)
        //         return missing;
        // }

        // return missing;

        /*解法1：置换法（原地哈希），由于空间要求为O(1)，所以只能在原数组的基础上修改*/
        int n = nums.size();

        for (int i = 0; i < n; i++)
        {
            while (nums[i] > 0 && nums[i] <= n && nums[i] != nums[nums[i] - 1])
                swap(nums[i], nums[nums[i] - 1]);
        }

        for (int i = 0; i < n; i++)
        {
            if (nums[i] != i + 1)
                return i + 1;
        }
        
        return n + 1;
    }
};
#include <vector>

using namespace std;

class Solution 
{
public:
    /*解法1：动态规划，由于本题为环形房间，因此对于 第一间房和最后一间房 需要特殊对待
    如果抢第一间房，则最后一间房不能抢，因此在 [0, n-1) 区间内计算最大金额
    如果不抢第一间房，则可以抢最后一间房，因此在 [1, n) 区间内计算最大金额
    以上两种情况的最大值就表示最终的最大金额

    时间复杂度 O(n) + O(n)
    空间复杂度 O(n) + O(n)，可以优化为 O(1)，即类似斐波那契数列只保留前两次的状态
    */
    int rob(vector<int>& nums) 
    {
        int n = nums.size();
        if (n == 0) return 0;
        else if (n == 1) return nums[0];
        else if (n == 2) return max(nums[0], nums[1]);

        return max(rangeRob(nums, 0, n - 1), rangeRob(nums, 1, n));
    }

    int rangeRob(vector<int>& nums, int start, int end) // 左闭右开区间
    {   
        // vector<int> dp(end - start, 0);
        // dp[0] = nums[start];
        // dp[1] = max(nums[start], nums[start + 1]);

        int dp_2 = nums[start];
        int dp_1 = max(nums[start], nums[start + 1]);

        for (int i = 2; i < end - start; ++i)
        {
            // dp[i] = max(dp[i - 1], dp[i - 2] + nums[start + i]);
            int temp = dp_1;
            dp_1 = max(dp_1, dp_2 + nums[start + i]);
            dp_2 = temp;
        }
        
        return dp_1;
        // return dp[end - start - 1];
    }
};
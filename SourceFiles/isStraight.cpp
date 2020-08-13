#include <vector>
#include <algorithm>

using namespace std;

class Solution 
{
private:
    void insertionSort(vector<int>& nums)
    {
        int n = nums.size();
        if (n < 2) return;

        for (int i = 1; i < n; ++i)
        {
            int curNum = nums[i];
            int j = i;

            for (; j > 0 && nums[j - 1] > curNum; --j)
                nums[j] = nums[j - 1];

            nums[j] = curNum;
        }   
    }

public:
    /*解法1：排序后计算手牌大小之间大于1的差值，大小王可以抵消中间的差值,
    从而判断出手牌大小的差，是否能用大小王来代替
    特殊情况要考虑抓到对子，这样不能构成顺子情况
    */
    bool isStraight(vector<int>& nums) 
    {
        int n = nums.size();

        insertionSort(nums);

        int kingNum = 0;
        int idx = 0;
        while (nums[idx++] == 0) ++kingNum;

        int numGap = 0;
        for (int i = idx; i < n; ++i) // 此时 idx 指向第一个非0数的 下一位 索引
        {
            if (nums[i - 1] == nums[i]) return false;

            numGap += nums[i] - nums[i - 1] - 1;
        }

        return numGap <= kingNum;
    }
};
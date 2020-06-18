#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /*解法1：前后双指针解法，左边遇到偶数时等待右边遇到奇数后交换，在左右指针相遇时返回结果*/
    // vector<int> exchange(vector<int>& nums) 
    // {
    //     if (nums.size() < 2) return nums;

    //     int left = 0;
    //     int right = nums.size() - 1;
    //     int temp = 0;

    //     while (left <= right)
    //     {
    //         if ((nums[left] % 2 == 0) && (nums[right] % 2 == 1)) 
    //         {
    //             temp = nums[left];
    //             nums[left] = nums[right];
    //             nums[right] = temp;
    //             left++;
    //             right--;
    //         }
    //         else if ((nums[left] % 2 == 0))
    //             right--;
    //         else if ((nums[right] % 2 == 1))
    //             left++;
    //         else
    //         {
    //             left++;
    //             right--;
    //         }
            
    //     }

    //     return nums;
    // }

    /*解法2：快慢双指针，慢指针指向偶数（即需要与后面的奇数交换的位置）时停止，当快指针搜索到右边第一个奇数时将值与其交换，直到快指针越界*/
    vector<int> exchange(vector<int>& nums)
    {
        int lower = 0;
        int faster = 0;

        while(faster < nums.size())
        {
            // while (nums[lower] % 2 != 0) // 不需要另做循环来寻找lower的位置，原因如下
            //     lower++;
            
            // 因为lower和faster初始值是相同的，如果一直遇到奇数（会产生自身与自身交换），那么lower和faster的值恒等，
            // 直到搜索到了偶数，lower才会比faster慢
            if (nums[faster] % 2 == 1) 
            {
                int temp = nums[faster];
                nums[faster] = nums[lower];
                nums[lower++] = temp;
            }

            faster++;
        }

        return nums;
    }
};
#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) 
    {
        /*
        解法1：根据middle与边界值的大小，判断middle左边有序还是middle右边有序
            如果左边有序，则将target与左边的有序区间边界比较，如果在这段区间内，则在左边搜索，否则右边搜索
            如果右边有序，则同理
        */
        // if (nums.size() == 0) return -1;
        // if (nums.size() == 1)
        // {
        //     if (nums[0] == target) return 0;
        //     else return -1;
        // }

        // int left = 0;
        // int right = nums.size() - 1;
        // int middle = left + (right - left) / 2;

        // while (left <= right)
        // {
        //     if (nums[middle] == target) return middle;

        //     if (nums[left] <= nums[middle])
        //     {
        //         if (nums[middle] > target && target >= nums[left])
        //         {
        //             right = middle - 1;
        //         }
        //         else
        //         {
        //             left = middle + 1;
        //         }
                
        //     } 
        //     else
        //     {
        //         if (nums[middle] < target && target <= nums[right])
        //         {
        //             left = middle + 1;
        //         }
        //         else
        //         {
        //             right = middle - 1;
        //         }
                
        //     }
            
        //     middle = left + (right - left) / 2;
        // }

        // return -1;

        /*解法2：先判断出旋转数组的分界点，然后在分界点两端的区间内判断，解法不完善，对于递增或递减序列会报错*/
        if (nums.size() == 0) return -1;
        if (nums.size() == 1)
        {
            if (nums[0] == target) return 0;
            else return -1;
        }

        int left = 0;
        int right = nums.size() - 1;
        int middle;

        while (left < right)
        {
            middle = left + (right - left) / 2;

            if (nums[middle] > nums[left])
                left = middle;
            else if (nums[middle] < nums[left])
                right = middle;
            else if (nums[middle] == nums[left])
                right--;
        }

        int border = left;
        left = 0;
        right = nums.size() - 1;
        if (target < nums[right] && target < nums[left])
            left = border;
        else if (target > nums[right] && target > nums[left])
            right = border;
            
        while (left <= right)
        {
            middle = left + (right - left) / 2;

            if (nums[middle] == target) return middle;
            else if (nums[middle] > target)
                right = middle - 1;
            else
                left = middle + 1;        
        }

        return -1;
    }
};
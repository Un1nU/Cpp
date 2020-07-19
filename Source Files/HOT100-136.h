#include <vector>

using namespace std;

class Solution {
public:
    /*
    若使用额外空间，可以考虑集合和哈希表，
    删除空间中已经出现的元素，加入未出现的元素到空间中，遍历完成，空间中剩下的元素就是不重复元素

    不使用额外的空间，利用异或运算的性质，
    1. 任何数与0异或，结果是0；
    2. 任何数与本身异或，结果是本身；
    3. 异或满足交换律和结合律；
    因此令数组中所有元素之间异或，则根据结合律和交换律，重复的两个元素之间异或为0，剩下的为不重复元素的值
    */
    int singleNumber(vector<int>& nums) 
    {
        if (nums.size() % 2 == 0) throw -1;
        if (nums.size() == 1) return nums[0];

        int res = nums[0];
        for (int i = 1; i < nums.size(); i++)
            res ^= nums[i];
        
        return res;
    }
};
#include <iostream>
#include <vector>

using namespace std;

class Solution 
{
public:
    /*解法1： 分组异或，原数组之间所有元素异或一定等于两个不同元素之间的异或值，
    因而根据这个异或值，可以取当中不为0的一位作为分组的标准，
    即两个不同的数在该位上一定是不同的，而相同的数在该位上的值一定相同
    从而可以分组进行异或得到最终的两个不同值
    时间复杂度： O(n)
    空间复杂度： O(1)
    */
    vector<int> singleNumbers(vector<int>& nums) 
    {
        int len = nums.size();
        if (len % 2 != 0) return {};
        
        int k = nums[0];
        for (int i = 1; i < len; i++)
            k ^= nums[i];

        int partition = 1;
        while ((partition & k) == 0) partition <<= 1; // 注意位运算优先级低，需要括号

        int first = 0; // 任何数与0异或，等于本身
        int second = 0;

        for (int i = 0; i < len; i++)
        {
            if ((nums[i] & partition) == 0)
                first ^= nums[i];
            else
                second ^= nums[i]; 
        }

        return {first, second};        
    }
};
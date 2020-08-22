#include <vector>
#include <math.h>

using namespace std;

class Solution 
{
private:
    static constexpr int TARGET = 24;
    static constexpr double EPSILON = 1e-6;
    enum OPER {ADD = 0, SUBTRACT, MULTIPLY, DIVIDE};

    bool dfs(vector<double>& nums)
    {
        int size = nums.size();
        if (size == 0) return false;
        if (size == 1) return fabs(nums[0] - TARGET) <= EPSILON; // 注意浮点数判断相等

        for (int i = 0; i < size; ++i) // 遍历选择 运算左值
        {
            for (int j = 0; j < size; ++j) // 遍历选择 运算右值
            {
                if (i == j) continue; // 一个数不能做重复运算

                vector<double> list; // 存储用选出的两个数做运算之后结果，与剩下元素构成的点数
                for (int k = 0; k < size; ++k) // list 初始化，排除即将做运算的数 nums[i], nums[j]
                {
                    if (k != i && k != j)
                        list.emplace_back(nums[k]);
                }

                for (int k = 0; k < 4; ++k)
                {
                    if ((k == ADD || k == MULTIPLY) && i > j) // 加法和乘法满足交换律，因此遇到重复计算可以跳过
                        continue;

                    // 选取其中一种运算符，运算结果构成的新数组继续dfs
                    if (k == ADD)
                        list.emplace_back(nums[i] + nums[j]);
                    else if (k == SUBTRACT)
                        list.emplace_back(nums[i] - nums[j]);
                    else if (k == MULTIPLY)
                        list.emplace_back(nums[i] * nums[j]);
                    else if (k == DIVIDE)
                    {
                        if (fabs(nums[j] <= EPSILON)) continue;
                        else list.emplace_back(nums[i] / nums[j]);
                    }

                    if (dfs(list))
                        return true;

                    list.pop_back(); // 回溯
                }
            }
        }

        return false;
    }

public:
    bool judgePoint24(vector<int>& nums) 
    {
        vector<double> dnums;
        for (auto& num : nums)
            dnums.emplace_back(static_cast<double> (num));

        return dfs(dnums);
    }
};
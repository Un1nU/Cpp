#include <vector>

using namespace std;

class Solution 
{
public:
    /*解法1：单调栈，维护一个单调递增栈（由于需要计算面积，因此存储的是索引），
    从左至右线性遍历 heights 数组，一旦遇到比栈顶索引表示的高度小的 高度 heights[idx]，
    则说明此时可以计算出 栈顶元素勾勒出的最大面积（因为左右的高度都比其小），
    并且栈内元素不断出栈（只要比当前的元素 heights[idx] 大，都可以确定面积），直到栈顶元素不严格大于当前元素
    具体可见 力扣题解前两个精选解答。

    当数组遍历完成时，还会存在栈内元素并未出栈（即一直未遇到比其严格小的元素），需要特殊处理；
    此外，在遍历数组时，可能出现栈为空的情况（每个柱子都只能与其自身构成矩形），从而代码注释 (1) 处需要判断栈是否为空

    在原数组中前后加入比 heights所有元素都严格小的元素（称为哨兵），可以将这两种特殊情况一般化处理。
    */
    int largestRectangleArea(vector<int>& heights) 
    {
        int size = heights.size();
        if (size == 0) return 0;
        else if (size == 1) return heights[0];

        vector<int> stk; // 使用 vector 来模拟栈
        stk.push_back(0);

        heights.insert(heights.begin(), 0); // 增加哨兵，避免特殊情况单独讨论
        heights.push_back(0);
        
        int idx = 0;
        int maxArea = 0;
        size += 2; // 头尾增加了哨兵元素，更新 size

        while (idx < size)
        {
            while (!stk.empty() && heights[stk.back()] > heights[idx]) // 遇到比栈顶小的元素，此时可以确定面积
            {
                int high = heights[stk.back()];
                stk.pop_back();

                int width = idx - stk.back() - 1; // (1)
                maxArea = max(maxArea, high * width); // 计算勾勒的面积
            }

            stk.push_back(idx);
            ++idx;
        }
        
        return maxArea;
    }
};
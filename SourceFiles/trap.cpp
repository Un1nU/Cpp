#include <vector>
#include <stack>

using namespace std;

class Solution 
{
public:
    int trap(vector<int>& height) 
    {
        int size = height.size();
        if (size < 2) return 0;

        // 该题中可以不使用哨兵，因为两边的柱子是构不成洼地的
        // 并且柱子未出栈，也表明右边没有柱子可以构成洼地
        
        // height.insert(height.begin(), 0);
        // height.push_back(0);
        // size += 2;

        int area = 0;
        stack<int> stk;
        // stk.push(0);

        for (int i = 0; i < size; ++i)
        {
            while (!stk.empty() && height[stk.top()] < height[i]) // 此时可能构成洼地
            {
                int bottom = height[stk.top()]; // 洼地的高度
                stk.pop();

                if (stk.empty()) break; // 此时栈为空，说明两个柱子之间是紧挨的，即没有洼地

                // min() 表示取洼地两侧柱子的最小高度，再减去洼地的高度即位盛水的高度
                int high = min(height[i], height[stk.top()]) - bottom; 
                int width = i - stk.top() - 1; // 洼地两侧的柱子宽度差
    
                area += high * width;
            }

            stk.push(i);
        }

        return area;
    }
};
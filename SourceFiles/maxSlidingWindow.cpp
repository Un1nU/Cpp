#include <vector>
#include <deque>

using namespace std;

class Solution 
{
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) 
    {
        int n = nums.size();

        vector<int> windowMax;
        deque<int> winNum;
        int window = k;

        for (int i = 0; i < window; ++i)
        {
            while (!winNum.empty() && winNum.back() < nums[i]) winNum.pop_back();

            winNum.push_back(nums[i]);
        }

        for (int i = window; i < n; ++i)
        {
            windowMax.push_back(winNum.front());

            while (!winNum.empty() && winNum.back() < nums[i]) winNum.pop_back();

            if (winNum.size() >= window) winNum.pop_front();

            winNum.push_back(nums[i]);
        }

        if (!winNum.empty()) windowMax.push_back(winNum.front());

        return windowMax;
    }
};
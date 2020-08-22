#include <vector>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) 
    {
        int size = nums.size();
        if (size < 2) return true;

        int jumpRange = nums[0];

        for (int i = 1; i < size; ++i)
        {
            if (i <= jumpRange)
                jumpRange = max(jumpRange, i + nums[i]);
        }

        return jumpRange >= size - 1;
    }
};
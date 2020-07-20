#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) 
    {
        int n = nums.size();
        if (n < 2) return n;

        int cnt = nums.size();
        int remove = 0;

        for (int i = 1; i < n; i++)
        {
            if (nums[i] > nums[remove])
                nums[++remove] = nums[i];
            else
                cnt--;
        }

        return cnt; 
    }
};
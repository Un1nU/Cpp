#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) 
    {
        vector<vector<int> > res;
        vector<int> seq;

        for (int left = 1, right = 2; left < right; )
        {
            int sum = (left + right) * (right - left + 1) / 2;
            if (sum < target)
                right++;
            else if (sum > target)
                left++;
            else
            {
                for (int i = left; i <= right; i++)
                    seq.push_back(i);

                res.push_back(seq);
                seq.clear();
                left++;
            }
        }

        return res;
    }
};
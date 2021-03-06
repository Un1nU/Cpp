#include <vector>

using namespace std;

class Solution 
{
public:
    int maxProfit(vector<int>& prices) 
    {
        int days = prices.size();
        if (days < 2) return 0;

        int profit = 0;

        for (int i = 1; i < days; ++i)
        {
            if (prices[i] > prices[i - 1])
            {
                profit += prices[i] - prices[i-1];

                if (i + 1 < days && prices[i + 1] < prices[i])
                    ++i;
            }
        }

        return profit;
    }
};
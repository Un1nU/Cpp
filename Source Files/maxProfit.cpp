#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        if (prices.size() < 2) return 0;

        int maxProfit = 0;
        int minBuy = prices[0];
        vector<int> profit(prices.size());
        profit[0] = 0;

        // for (int i = 1; i < prices.size(); i++)
        // {
        //     if (prices[i] - minBuy > maxProfit)
        //         maxProfit = prices[i] - minBuy;

        //     if (prices[i] < minBuy)
        //         minBuy = prices[i];
        // }

        // return maxProfit;

        for (int i = 1; i < prices.size(); i++)
        {
            if (prices[i] < minBuy)
                minBuy = prices[i];

            if (prices[i] - minBuy > profit[i-1])
                profit[i] = prices[i] - minBuy;
            else
                profit[i] = profit[i-1];
        }

        return profit[prices.size()-1];
    }
};
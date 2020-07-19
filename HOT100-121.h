#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        if (prices.size() < 2) return 0;
        
        int maxProfit = 0;
        int minPrices = prices[0];

        for (auto p : prices)
        {
            if (p < minPrices)
                minPrices = p;

            if (p - minPrices > maxProfit)
                maxProfit = p - minPrices;
        }

        return maxProfit;
    }
};
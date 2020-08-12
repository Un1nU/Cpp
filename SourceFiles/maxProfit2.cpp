#include <vector>

using namespace std;

class Solution 
{
public:
    /*解法1：贪心算法，每遇到一个连续的谷底和谷峰，就是最佳买卖的时机
    因而，如果价格连续递增，则符合最大收益，程序上体现为多次买卖*/
    int maxProfit(vector<int>& prices) 
    {
        int days = prices.size();
        if (days < 2) return 0;

        int maxProfit = 0;

        for (int i = 1; i < days; ++i)
        {
            if (prices[i] >= prices[i - 1])
                maxProfit += prices[i] - prices[i -1];
        }

        return maxProfit;
    }
};
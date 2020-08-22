#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution 
{
private:
    class cmp
    {
    public:
        // 优先队列是优先级高的位于队首，cmp算子返回 true 表示 lhs 的优先级小于 rhs 优先级
        // return lhs > rhs 则表示，大的数优先级越小，因此为小顶堆
        bool operator()(const pair<int, int>& lhs, const pair<int, int>& rhs)
        {
            return lhs.second > rhs.second;
        }
    };
    
public:
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        unordered_map<int, int> freq;
        for (int i = 0; i < nums.size(); ++i)
            freq[nums[i]]++;

        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> minHeap;

        auto iter = freq.begin();
        for (; iter != freq.end(); ++iter)
        {
            if (minHeap.size() < k)
            {
                minHeap.push(*iter);
            }
            else
            {
                if (minHeap.top().second < iter->second)
                {
                    minHeap.pop();
                    minHeap.push(*iter);
                }
            }
        }

        vector<int> res;
        while (!minHeap.empty())
        {
            res.emplace_back(minHeap.top().first);
            minHeap.pop();
        }

        return res;
    }
};
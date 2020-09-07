#include <vector>
#include <string>
#include <unordered_map>
#include <map>

using namespace std;

class Solution 
{
private:
    // <string, map<string, int>> 表示 <出发地，<目的地，经过次数>>
    unordered_map<string, map<string, int>> travel;

    bool dfs(string src, vector<vector<string>>& tickets, vector<string>& paths)
    {
        if (paths.size() - 1 == tickets.size())
            return true;

        for (auto& dst : travel[src])
        {
            if (dst.second <= 0) continue; // 表示出发地为 dst 的机票已用完

            dst.second--;
            paths.push_back(dst.first);

            if (dfs(dst.first, tickets, paths))
                return true;

            paths.pop_back();
            dst.second++;
        }

        return false;
    }

public:
    vector<string> findItinerary(vector<vector<string>>& tickets) 
    {
        int rows = tickets.size();
        if (rows == 0) return {};

        vector<string> paths;

        for (int i = 0; i < rows; ++i)
            travel[tickets[i][0]][tickets[i][1]]++;

        paths.push_back("JFK");
        dfs("JFK", tickets, paths);

        return paths;
    }
};
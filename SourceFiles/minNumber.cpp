#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution 
{
public:
    string minNumber(vector<int>& nums) 
    {
        vector<string> strNums;
        string res;

        for (auto& num : nums)
            strNums.emplace_back(to_string(num));

        sort(strNums.begin(), strNums.end(), [](string& s1, string& s2) {return s1 + s2 < s2 + s1;});

        for (auto& str : strNums)
            res += str;

        return res;
    }
};
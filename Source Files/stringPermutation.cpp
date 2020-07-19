#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution 
{
public:
    vector<string> permutation(string s) 
    {
        vector<string> res;
        if (s.empty()) return res;

        rpermutation(s, s.begin(), res);

        return res;
    }

    void rpermutation(string& s, string::iterator starIter, vector<string>& res)
    {
        if (starIter == s.end())
        {
            res.push_back(s);
            return;
        }

        unordered_set<char> isTraversed;
        for (auto iter = starIter; iter != s.end(); iter++)
        {
            if (isTraversed.count(*iter)) continue;

            isTraversed.insert(*iter);
            swap(iter, starIter);
            rpermutation(s, starIter+1, res);
            swap(iter, starIter);
        }

    }

    void swap(string::iterator& iter1, string::iterator& iter2)
    {
        auto temp = *iter1;
        *iter1 = *iter2;
        *iter2 = temp;
    }
};
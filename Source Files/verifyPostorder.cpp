#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool verifyPostorder(vector<int>& postorder) 
    {
        if (postorder.empty()) return true;

        return rescurVerify(postorder.begin(), postorder.end());
    }

    bool rescurVerify(vector<int>::iterator Begin, vector<int>::iterator End)
    {
        if (Begin == End) return true;

        int root = *(End - 1);

        auto Left = Begin;
        while(*Left < root && Left < End-1) Left++;

        auto Right = Left;
        while(*Right > root && Right < End-1) Right++;

        if (Left != End-1 && Right != End-1) return false;

        bool leftVerify = true;
        leftVerify = rescurVerify(Begin, Left);

        bool rightVerify = true;
        rightVerify = rescurVerify(Left, End-1);

        return leftVerify && rightVerify;

    }
};
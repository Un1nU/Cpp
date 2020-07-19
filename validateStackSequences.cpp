#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) 
    {
        if (popped.empty()) return true;
        if (pushed.empty() && !popped.empty()) return false;
        if (pushed.size() != popped.size()) return false;

        // /* 以popped序列的逻辑进行循环*/
        // stack<int> seq;
        // int idx = 0;

        // for (int i = 0; i < popped.size(); i++)
        // {
        //     if (seq.empty() && idx < pushed.size()) // 如果push一个元素马上就pop，则需要遍历一遍pushed
        //         seq.push(pushed[idx++]);

        //     while (seq.top() != popped[i]) // 栈顶元素与popped当前元素一直不相等，则不断入栈pushed元素
        //     {
        //         if (idx == pushed.size()) // 当pushed元素都入栈时，而栈顶元素扔与popped当前元素不相同                                 
        //             return false;       // 则表明popped元素不是合法出栈序列

        //         seq.push(pushed[idx++]);
        //     }

        //     seq.pop();
        // }

        // return true; // 如果顺利结束for循环，说明每一个popped元素都遍历完毕，即出栈序列合法

        /*以pushed序列的逻辑进行循环*/
        stack<int> seq;
        int idx = 0;

        for (auto item : pushed)
        {
            seq.push(item);

            while (!seq.empty() && seq.top() == popped[idx])
            {
                idx++;
                seq.pop();
            }
        }

        if (seq.empty())
            return true;
        else
            return false;
    }
};
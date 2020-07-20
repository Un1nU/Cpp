#include <iostream>
#include <stack>

using namespace std;

class MinStack {

private:
    stack<int> stk;
    stack<int> minStk;

public:
    /** initialize your data structure here. */
    MinStack() 
    {

    }
    
    void push(int x) 
    {
        stk.push(x);
        if (!minStk.empty())
        {
            if (minStk.top() <= x)
                minStk.push(minStk.top());
            else
                minStk.push(x);
        }
        else
            minStk.push(x);
    }
    
    void pop() 
    {
        if (!stk.empty() && !minStk.empty())
        {
            stk.pop();
            minStk.pop();
        }
    }
    
    int top() 
    {
        return stk.top();
    }
    
    int min() 
    {
        return minStk.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->min();
 */
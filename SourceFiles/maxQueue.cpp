#include <queue>
#include <deque>

using namespace std;

/*解法1：维护一个单调递减双端队列，因为当存储数据的队列元素出队时，可能删除的正好为当前队列最大值
因此，此时需要将当前存储最大值的队列的队首元素出队，即双端队列的功能
具体实现逻辑与 滑动窗口 相同 */
class MaxQueue 
{
private:
    queue<int> Queue;
    deque<int> maxQueue;

public:
    MaxQueue() 
    { }
    
    int max_value() 
    {
        if (Queue.empty()) return -1;

        return maxQueue.front();
    }
    
    void push_back(int value) 
    {
        while (!maxQueue.empty() && maxQueue.back() < value) 
            maxQueue.pop_back();

        maxQueue.push_back(value);
        Queue.push(value);
    }
    
    int pop_front() 
    {
        if (Queue.empty()) return -1;

        int frontNum = Queue.front();
        if (Queue.front() == maxQueue.front())  
            maxQueue.pop_front();
        
        Queue.pop();

        return frontNum;
    }   
};

/**
 * Your MaxQueue object will be instantiated and called as such:
 * MaxQueue* obj = new MaxQueue();
 * int param_1 = obj->max_value();
 * obj->push_back(value);
 * int param_3 = obj->pop_front();
 */
#include <queue>

using namespace std;

class MedianFinder 
{
private:
    priority_queue<int, vector<int>, less<int>> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;

public:
    /** initialize your data structure here. */
    MedianFinder() {}
    
    void addNum(int num) 
    {
        if (minHeap.size() == maxHeap.size())
        {
            maxHeap.push(num);
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
        else
        {
            minHeap.push(num);
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    
    double findMedian() 
    {
        if (minHeap.size() == maxHeap.size())
            return (minHeap.top() + maxHeap.top()) / 2.0;
        else
            return minHeap.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
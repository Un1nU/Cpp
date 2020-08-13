#include <vector>
#include <queue>
#include <iostream>

using namespace std;

class Solution 
{
public:
    void printHeap(const vector<int>& heap)
    {
        for (int i = 1; i < heap.size(); ++i)
            cout << heap[i] << " ";
        cout << endl;
    }

    vector<int> buildMaxHeap(vector<int>& nums)
    {
        int size = nums.size();
        if (size < 1) return {};
        
        vector<int> heap(size+1);
        
        for (int i = 0; i < size; ++i)
            heap[i + 1] = nums[i];

        for (int i = size / 2; i > 0; --i)
            percolateUp(heap, i);
    }

    bool percolateUp(vector<int>& heap, int index)
    {
        int heapSize = heap.size();
        if (index < 2 || heapSize < index) return false;

        int parent = heap[index];
        int child = index * 2;

        while (index >= 1)
        {
            if (child < heapSize && heap[child + 1] > heap[child])
                child += 1;

            if (heap[child] <= parent) break;

            heap[child] = heap[index];
            child = index;
            index /= 2;

            printHeap(heap);
        }
        
        heap[child] = parent;
    }

public:
    /*解法1：最大堆，使用STL中的优先队列，先让元素入队，然后出队k-1次，堆顶元素即为第 K 大元素*/
    int findKthLargest(vector<int>& nums, int k) 
    {
        int size = nums.size();
        priority_queue<int, vector<int>, less<int>> heap(nums.begin(), nums.end());

        while (--k)
            heap.pop();
        
        return heap.top();
    }

    /*解法2：最大堆，不使用 STL，手动创建一个堆*/
};

int main()
{
    vector<int> nums(10);

    for (int i = 0; i < 10; ++i)
        cin >> nums[i];

    Solution sol;

    vector<int> heap = sol.buildMaxHeap(nums);

    for (auto item : heap)
        cout << item << " ";
    cout << endl;

    return 0;
}
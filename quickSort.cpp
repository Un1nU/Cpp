#include <iostream>
#include <vector>
#include <random>

using namespace std;
const int cutoff = 3;

void swap(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}

void insertionSort(vector<int>::iterator begin, vector<int>::iterator end)
{
    if (begin == end-1) return;
    
    int temp;
    for (int i = 1, j; i < (end - begin); i++)
    {
        temp = *(begin + i); // temp = a[i];

        for (j = i; j > 0 && *(begin+j-1) > temp; j--)
            *(begin+j) = *(begin+j-1); // a[j] = a[j -1];
 
        *(begin+j) = temp; // a[j] = a[i];
    }
}

int medianPivot(vector<int>& nums, int beginIdx, int endIdx)
{
    int midIdx = beginIdx + (endIdx - beginIdx) / 2;

    if (nums[beginIdx] > nums[midIdx]) swap(nums[midIdx], nums[beginIdx]);
    if (nums[endIdx] < nums[midIdx]) swap(nums[midIdx], nums[endIdx]);
    if (nums[beginIdx] > nums[endIdx]) swap(nums[beginIdx], nums[endIdx]);

    swap(nums[midIdx], nums[endIdx-1]);

    return nums[endIdx-1];
}

void quickSortMedianPivot(vector<int>& nums, int beginIdx, int endIdx)
{   
    if ((endIdx - beginIdx) >= cutoff)
    {
        int pivot = medianPivot(nums, beginIdx, endIdx);
        // 当数组中元素小于2时，right会产生数组越界，因此取medianPivot的快排只适用于nums元素大于等于2的情况,即cutoff必不可少
        // 如果使用一般情况的快排（即随机取pivot然后pivot左右交换比较大小），则没有cutoff >= 2的限制
        int left = beginIdx; // 由于下面是 ++left，因此初值取最左位置
        int right = endIdx - 1; // 与上同理
        
        while (1) // 由于至少是在找到满足条件的left与right（即内部两个while完成）后，if判断才决定是否交换，因此写成while(1)形式
        {
            while (nums[++left] < pivot);
            while (nums[--right] > pivot);

            if (left < right) swap(nums[left], nums[right]);
            else break;
        }

        swap(nums[endIdx-1], nums[left]); // 最后将pivot放到中间位置

        quickSortMedianPivot(nums, beginIdx, left-1);
        quickSortMedianPivot(nums, left+1, endIdx); 
    }
    else
    {
        insertionSort(nums.begin()+beginIdx, nums.begin()+endIdx+1);
    }
    
}

int Partition(vector<int>& nums, int begin, int end)
{
    default_random_engine e;
    uniform_int_distribution<int> u(begin, end);
    int pivot = u(e);

    swap(nums[pivot], nums[end]); // 把pivot的值放到最后

    int border = begin - 1; 
    for (int i = begin; i < end; i++) // 把小的数放到左边的位置
    {
        if (nums[i] < nums[end]) // 如果找到了小数，就将其与分界点的数交换
        {
            border++; // border下一位始终指向的是大数的位置，或者是与i相同的位置（当从头一直遇到小于pivot的数时）

            if (i != border)
                swap(nums[border], nums[i]);
        }
    }

    swap(nums[++border], nums[end]); // 将pivot交换到中间位置

    return border;
}

void quickSort(vector<int>& nums, int begin, int end)
{
    if (begin == end)   return;
    
    int border = Partition(nums, begin, end);

    if (border > begin) quickSort(nums, begin, border-1);
    if (border < end) quickSort(nums, border+1, end);
}

int main()
{
    vector<int> nums;
    int data;

    while (cin >> data)
        nums.push_back(data);

    // quickSort(nums, 0, nums.size()-1);
    // insertionSort(nums.begin(), nums.end());
    quickSortMedianPivot(nums, 0, nums.size()-1);
    // cout << medianPivot(nums, 0, nums.size()-1) << endl;
    
    for (auto x : nums)
        cout << x << " ";
    cout << endl;

    return 0;
}
class Solution 
{
public:
    /*解法1：二分法，sqrt(x) 一定处于 [1, x] 之间，因此二分查找到 mid^2 == x 时，middle即为 sqrt(x)
    时间复杂度： O(logn)
    空间复杂度： O(1)
    */
    int mySqrt(int x) 
    {
        if (x < 2) return x;

        int left = 1;
        int right = x;
        int ans = -1;

        while (left <= right)
        {
            int middle = left + (right - left) / 2;

            // 使用 middle <= x / middle 以防止 middle * middle 出现溢出
            if (middle <= x / middle)
            {
                ans = middle;
                left = middle + 1;
            }
            else
                right = middle - 1;
        }

        return ans;
    }
};
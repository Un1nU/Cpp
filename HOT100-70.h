class Solution {
public:
    int climbStairs(int n) 
    {
        /*斐波那契数列，使用动态规划*/
        if (n < 3) return n; 

        int fn_1 = 1;
        int fn_2 = 2;
        n -= 2;

        while(n--)
        {
            int temp = fn_2;
            fn_2 = fn_2 + fn_1;
            fn_1 = temp;
        }

        return fn_2;        
    }
};
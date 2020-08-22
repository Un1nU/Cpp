class Solution 
{
public:
    /*解法1：递归实现，如果 || 左边表达式为 False 则会执行 右边的表达式，从而实现递归的出口判断
    同理 可以使用 && 符号，如果 && 左边的表达式为 True 则会继续执行 右边的表达式*/
    int sumNums(int n) 
    {
        n && (n += sumNums(n-1));
        // !n || (n += sumNums(n - 1));
        return n;
    }

    /*解法2：快速乘展开
    */
};
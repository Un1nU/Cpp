#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> printNumbers(int n) 
    {
        
    }

    void print1ToNNumbers(int n)
    {
        if (n <= 0) return;

        string num(n, '0');

        while (!increment(num))
        {
            printStringNum(num);
        }
    }

    bool increment(string& num)
    {
        int isOverFlow = false;
        int carry = 0;

        for (int idx = num.size()-1; idx >= 0; idx--)
        {
            int sum = num[idx] - '0' + carry;

            if (idx == num.size() - 1)
                sum++;

            if (sum >= 10)
            {
                if (idx == 0)
                    isOverFlow = true;
                else
                {
                    sum -= 10;
                    carry = 1;
                    num[idx] = sum + '0';
                }
            }
            else
            {
                carry = 0;
                num[idx] = sum + '0';
            }

            if (!carry) break;
        }

        return isOverFlow;
    }

    void printStringNum(const string& num)
    {
        bool canPrint = false;

        for (int i = 0; i < num.size(); i++)
        {
            if (num[i] != '0')
                canPrint = true;
            
            if (canPrint)
                cout << num[i];
        }
        cout << " ";
    }
};

int main()
{
    string nums; 
    Solution sol;

    //cin >> nums;

    sol.print1ToNNumbers(3);


    return 0;
}
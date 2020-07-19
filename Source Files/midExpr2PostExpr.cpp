#include <iostream>
#include <string>
#include <stack>
#include <sstream>

using namespace std;
/*
    Convert a midfix experssion to postfix expression.

    Kowned bug: 
        1.the numbers in midfix cannot bigger than 9.
        2.the numbers in midfix must be positive.
*/
string midfix2Postfix(string midExpr)
{
    stack<char> oper;
    string postExpr("");

    for (int i = 0; i < midExpr.length(); i++)
    {
        // 左边括号，直接入栈
        if (midExpr[i] == '(' || midExpr[i] == '[' || midExpr[i] == '{')
        {
            oper.push(midExpr[i]);
        }
        else if (midExpr.at(i) <= '9' && midExpr.at(i) >= '0') // 如果为数字则直接输出，缺陷：数字不能超过两位；没有考虑负数情况
        {
            postExpr += midExpr[i];
            cout << midExpr[i];
        }
        else if (midExpr[i] == ')' || midExpr[i] == ']' || midExpr[i] == '}') // 如果为右边括号，弹出栈元素，直到找到栈中第一个匹配的左边括号
        {
            if (midExpr[i] == ')') // can be writed as a function.
            {
                while (oper.top() != '(')
                {
                    postExpr += oper.top();
                    cout << oper.top();
                    oper.pop();
                }
                oper.pop(); // pop out the matched left bucket
                continue; // scan the next number or operator
            }

            if (midExpr[i] == ']')
            {
                while (oper.top() != '[')
                {
                    postExpr += oper.top();
                    cout << oper.top();
                    oper.pop();
                }
                oper.pop(); 
                continue;
            }

            if (midExpr[i] == '}')
            {
                while (oper.top() != '{')
                {
                    postExpr += oper.top();
                    cout << oper.top();
                    oper.pop();
                }
                oper.pop();
                continue;
            }

        }
        else if (midExpr[i] == '+' || midExpr[i] == '-' || midExpr[i] == '*' || midExpr[i] == '/')
        {
            // 如果表达式为操作符且运算优先级不大于栈顶的操作符，则将栈元素弹出，再将该表达式压入栈
            if ((midExpr[i] == '+' || midExpr[i] == '-') && (oper.top() == '*' || oper.top() == '/'))
            {
                while(!oper.empty())
                {
                    postExpr += oper.top();
                    cout << oper.top();
                    oper.pop();
                }
            }

            oper.push(midExpr[i]);
        }
        else
        {
            cout << "Invalid input expression." << endl;
            return "";
        }
        
    }

    while(!oper.empty())
    {
        postExpr += oper.top();
        cout << oper.top();
        oper.pop();
    }
    cout << endl;

    return postExpr;
}

int calPostexpr(const string postExpr)
{
    if (postExpr == "") return 0;

    stack<int> nums;

    for (int i = 0; i < postExpr.length(); i++)
    {
        if (postExpr[i] <= '9' && postExpr[i] >= '0')
        {
            nums.push(postExpr[i] - '0');
        }
        else if (postExpr[i] == '*' || postExpr[i] == '/' || postExpr[i] == '+' || postExpr[i] == '-')
        {
            int lefter = 0;
            int righter = 0;
            int result = 0;

            righter = nums.top();
            nums.pop();

            lefter = nums.top();
            nums.pop();

            if (postExpr[i] == '*')
                result = lefter * righter;
            else if (postExpr[i] == '/')
                result = lefter / righter;
            else if (postExpr[i] == '+')
                result = lefter + righter;
            else 
                result = lefter - righter;

            nums.push(result);
        }
    }

    cout << "The value of expression is:" << endl;
    cout << nums.top() << endl;

    return nums.top();
}   

int main()
{
    string midExpr;
    cout << "Please input a valid midfix expression." << endl;
    cin >> midExpr;

    cout << "Convert it to postfix expression as following:" << endl;
    string postExpr;
    postExpr = midfix2Postfix(midExpr);

    int result = calPostexpr(postExpr);

    return 0;
}
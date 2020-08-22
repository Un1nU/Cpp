/*
开发一个简单错误记录功能小模块，能够记录出错的代码所在的文件名称和行号。
处理:
1.记录最多8条错误记录，对相同的错误记录(即文件名称和行号完全匹配)只记录一条，错误计数增加；(文件所在的目录不同，文件名和行号相同也要合并)
2.超过16个字符的文件名称，只记录文件的最后有效16个字符；(如果文件名不同，而只是文件名的后16个字符和行号相同，也不要合并)
3.输入的文件可能带路径，记录文件名称不能带路径

输入描述:
一行或多行字符串。每行包括带路径文件名称，行号，以空格隔开。

    文件路径为windows格式

    如：E:\V1R2\product\fpgadrive.c 1325

输出描述:
将所有的记录统计并将结果输出，格式：文件名代码行数数目，一个空格隔开，如: fpgadrive.c 1325 1 

    结果根据数目从多到少排序，数目相同的情况下，按照输入第一次出现顺序排序。

    如果超过8条记录，则只输出前8条记录.

    如果文件名的长度超过16个字符，则只输出后16个字符

输入例子1:
E:\V1R2\product\fpgadrive.c 1325
*/

#include <string>
#include <iostream>
#include <map>
#include <deque>
#include <vector>

using namespace std;

string getFileName(const string& path)
{
    string fileName;

    int len = path.length();
    int idx = len - 1;

    while (idx >= 0 && path[idx] != '\\') --idx;

    if (len - idx <= 16)
        fileName = path.substr(idx + 1, len - idx);
    else
        fileName = path.substr(len - 15, 16);

    return fileName;
}

int main()
{
    string path;
    string lineNo;
    map<string, int> log;
    deque<string> apperSort(8);

    while (cin >> path >> lineNo)
    {
        string err = path + lineNo;

        if (!log.count(err))
        {
            if (log.size() <= 8)
            {
                log[err] = 1;
                apperSort.push_back(err);
            }
            // else
            // {
            //     string remove = apperSort.front();
            //     apperSort.pop_front();
            //     log.erase(remove);
            //     log[err] = 1;
            // }
        }
        else
        {
            log[err]++;
        }
    }

    for (auto iter = log.begin(); iter != log.end(); ++iter)
    {
        string err = iter->first;

        int idx = err.length() - 1;
        while (idx >= 0 && err[idx] >= '0' && err[idx] <= '9') --idx;

        path = err.substr(0, idx+1);
        string fName = getFileName(path);

        lineNo = err.substr(idx+1, err.length()-idx);

        cout << fName << " " << lineNo << " " << iter->second << endl;
    }

    return 0;
}
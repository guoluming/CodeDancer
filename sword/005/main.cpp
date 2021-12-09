/*
剑指 Offer 05. 替换空格

请实现一个函数，把字符串 s 中的每个空格替换成"%20"。

 

示例 1：

输入：s = "We are happy."
输出："We%20are%20happy."
 

限制：

0 <= s 的长度 <= 10000

*/

#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
    string replaceSpace(string s)
    {
        int len = s.length();
        int index = 0;
        string obj;
        while (index < len)
        {
            int pos = s.find(' ', index);
            if (pos == string::npos)
            {
                obj += s.substr(index,len-pos);
                return obj;
            }
            if (pos != index)
            {
                obj += s.substr(index, pos - index);
            }

            obj += "%20";
            index = pos + 1;
        }

        return obj;
    }
};

int main()
{
    string srcObj("We are     happy.");

    string destObj = Solution().replaceSpace(srcObj);
    cout << destObj.c_str() << endl;
    return 0;
}
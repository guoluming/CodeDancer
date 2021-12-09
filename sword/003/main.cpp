/*
剑指 Offer 09. 用两个栈实现队列

用两个栈实现一个队列。队列的声明如下，请实现它的两个函数 appendTail 和 deleteHead ，分别完成在队列尾部插入整数和在队列头部删除整数的功能。(若队列中没有元素，deleteHead 操作返回 -1 )

 

示例 1：

输入：
["CQueue","appendTail","deleteHead","deleteHead"]
[[],[3],[],[]]
输出：[null,null,3,-1]
示例 2：

输入：
["CQueue","deleteHead","appendTail","appendTail","deleteHead","deleteHead"]
[[],[],[5],[2],[],[]]
输出：[null,-1,null,null,5,2]
提示：

1 <= values <= 10000
最多会对 appendTail、deleteHead 进行 10000 次调用

*/

#include <iostream>
#include <stack>
using namespace std;

class CQueue
{
public:
    CQueue()
    {
    }

    void appendTail(int value)
    {
        aStack.push(value);
    }

    int deleteHead()
    {
        if (aStack.empty() && bStack.empty())
        {
            return -1;
        }

        if (bStack.empty())
        {
            while (!aStack.empty())
            {
                int atop = aStack.top();
                aStack.pop();
                bStack.push(atop);
            }
        }
        int ret = bStack.top();
        bStack.pop();
        return ret;
    }

    bool empty()
    {
        if (aStack.empty() && bStack.empty())
        {
            return true;
        }
        else
            return false;
    }

    int peek()
    {
        if (aStack.empty() && bStack.empty())
        {
            return -1;
        }

        if (bStack.empty())
        {
            while (!aStack.empty())
            {
                int atop = aStack.top();
                aStack.pop();
                bStack.push(atop);
            }
        }
        int ret = bStack.top();
        return ret;
    }
private:
    stack<int> aStack;
    stack<int> bStack;
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */

int main()
{
    CQueue *obj = new CQueue();

    cout << "push data:" << endl;

    for (int i = 0; i < 5; i++)
    {
        obj->appendTail(i);
        cout << i << endl;
    }

    cout << "pop data:" << endl;

    for (int i = 0; i < 3; i++)
    {
        int value = obj->deleteHead();
        cout << value << endl;
    }

    cout << "push data:" << endl;

    for (int i = 11; i < 18; i++)
    {
        obj->appendTail(i);
        cout << i << endl;
    }

    cout << "pop data:" << endl;

    for (int i = 0; i < 7; i++)
    {
        int value = obj->deleteHead();
        cout << value << endl;
    }

    return 0;
}
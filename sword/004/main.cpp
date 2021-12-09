/*
两个队列实现一个栈
*/

#include <iostream>
#include <queue>
using namespace std;

class CStack
{
public:
    CStack()
    {
    }

    void appendTail(int value)
    {
        if (aQueue.empty() && bQueue.empty())
        {
            aQueue.push(value);
            return;
        }

        if (aQueue.empty())
        {
            bQueue.push(value);
        }
        else
        {
            aQueue.push(value);
        }

        return;
    }

    int deleteHead()
    {
        if (aQueue.empty() && bQueue.empty())
        {
            return -1;
        }
        int nFirst = 0;
        if (bQueue.empty())
        {
            while (!aQueue.empty())
            {
                nFirst = aQueue.front();
                aQueue.pop();
                if (aQueue.empty())
                {
                    return nFirst;
                }
                else
                {
                    bQueue.push(nFirst);
                }
            }
        }
        else
        {
            while (!bQueue.empty())
            {
                nFirst = bQueue.front();
                bQueue.pop();
                if (bQueue.empty())
                {
                    return nFirst;
                }
                else
                {
                    aQueue.push(nFirst);
                }
            }
        }

        return -1;
    }

private:
    queue<int> aQueue;
    queue<int> bQueue;
};

/**
 * Your CStack object will be instantiated and called as such:
 * CStack* obj = new CStack();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */

int main()
{
    CStack *obj = new CStack();

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

    for (int i = 0; i < 10; i++)
    {
        int value = obj->deleteHead();
        cout << value << endl;
    }

    return 0;
}
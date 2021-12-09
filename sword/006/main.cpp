/*
剑指 Offer 06. 从尾到头打印链表

输入一个链表的头节点，从尾到头反过来返回每个节点的值（用数组返回）。

示例 1：

输入：head = [1,3,2]
输出：[2,3,1]
 

限制：

0 <= 链表长度 <= 10000

*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:

    void processFunc(ListNode* node,vector<int>& vec)
    {
        if(node == NULL)
            return;
        processFunc(node->next,vec);

        vec.push_back(node->val);
    }

    vector<int> reversePrint(ListNode* head) {
        vector<int> destVec;

        processFunc(head,destVec);

        return destVec;
    }
};

int main()
{
    int val = 0;
    ListNode *pHeadNode = NULL;
    ListNode *preNode = NULL;
    while (++val < 10)
    {
        cout << "new val:" << val << endl;

        ListNode *pNode = new ListNode(val);

        if (preNode == NULL)
        {
            pHeadNode = pNode;
            preNode = pHeadNode;
            continue;
        }
        else
        {
            preNode->next = pNode;
        }

        preNode = pNode;
    }
    //反转打印
    vector<int> destObj = Solution().reversePrint(pHeadNode);
    for (int index : destObj)
    {
        cout << index << endl;
    }
    //回收资源
    ListNode *nextNode = pHeadNode;

    while (nextNode)
    {
        cout << "delete val:" << nextNode->val << endl;
        ListNode *tmpNode = nextNode->next;

        delete nextNode;

        nextNode = tmpNode;
    }

    return 0;
}
/*
206. 反转链表

示例 1：


输入：head = [1,2,3,4,5]
输出：[5,4,3,2,1]
示例 2：


输入：head = [1,2]
输出：[2,1]
示例 3：

输入：head = []
输出：[]
 

提示：

链表中节点的数目范围是 [0, 5000]
-5000 <= Node.val <= 5000
 

进阶：链表可以选用迭代或递归方式完成反转。你能否用两种方法解决这道题？

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

    ListNode* reverseList1(ListNode* head) {
        
        ListNode* reverseHead = nullptr;

        ListNode* pNode = head;
        ListNode* pre = nullptr;

        while(pNode)
        {
            ListNode* pNext = pNode->next;

            if(pNext == nullptr)
                reverseHead = pNode;

            pNode->next = pre;

            pre = pNode;
            pNode = pNext;

        }
        return reverseHead;
    }

    ListNode* reverseList(ListNode* head) {
        
        if(head->next == nullptr)
            return head;

        ListNode* last = reverseList(head->next);

        head->next->next = head;
        head->next = nullptr;

        cout << "head val:" << head->val << endl;
        cout << "last val:" << last->val << endl;
        return last; 
        
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
    //回收资源
    ListNode *nextNode = Solution().reverseList(pHeadNode);

    
    while (nextNode)
    {
        cout << "delete val:" << nextNode->val << endl;
        ListNode *tmpNode = nextNode->next;

        delete nextNode;

        nextNode = tmpNode;
    }

    return 0;
}
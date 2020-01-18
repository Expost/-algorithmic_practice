#include <stdio.h>
#include <map>
using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;

    ListNode(int x) :
        val(x), next(NULL) {
    }
};

ListNode* EntryNodeOfLoop(ListNode* pHead)
{
    map<void*, int> m;
    for (auto node = pHead; node != nullptr; node = node->next)
    {
        if (m[node] == 1)
        {
            return node;
        }

        m[node] = 1;
    }

    return nullptr;
}

// 以上为简单粗暴的方法，空间复杂度较高
// 参考讨论，主要使用快慢指针的方法
ListNode* EntryNodeOfLoop_1(ListNode* pHead)
{
    auto slow = pHead;
    auto fast = pHead;
    while (fast != nullptr && fast->next != nullptr)
    {
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow)
        {
            break;
        }
    }

    if (fast == nullptr || fast->next == nullptr)
    {
        return nullptr;
    }

    fast = pHead;
    while (fast != slow)
    {
        fast = fast->next;
        slow = slow->next;
    }
    
    return fast;
}


int main()
{
    ListNode* head = new struct ListNode(0);
    head->next = new struct ListNode(1);
    head->next->next = new struct ListNode(2);
    head->next->next->next = new struct ListNode(3);
    head->next->next->next->next = new struct ListNode(4);

    // 设置环节点
    head->next->next->next->next->next = head->next->next->next->next;
    auto node = EntryNodeOfLoop_1(head);

    if (node)
    {
        printf("%d\n", node->val);
    }
    else
    {
        printf("nullptr\n");
    }
    
    getchar();
    return 0;
}
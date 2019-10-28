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

ListNode* FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2) {
    map<ListNode*, int> m;
    for (; pHead1 != nullptr; pHead1 = pHead1->next)
    {
        m[pHead1] = 1;
    }

    for (; pHead2 != nullptr; pHead2 = pHead2->next)
    {
        if (m[pHead2] == 1)
        {
            return pHead2;
        }
    }

    return nullptr;
}

// 参考讨论实现，需要好好研究一下
ListNode* FindFirstCommonNode_1(ListNode* pHead1, ListNode* pHead2) {
    ListNode *p1 = pHead1;
    ListNode *p2 = pHead2;
    while (p1 != p2) {
        p1 = (p1 == NULL ? pHead2 : p1->next);
        p2 = (p2 == NULL ? pHead1 : p2->next);
    }
    return p1;
}

int main()
{
    ListNode* head1 = new struct ListNode(0);
    head1->next = new struct ListNode(1);
    head1->next->next = new struct ListNode(2);
    head1->next->next->next = new struct ListNode(3);
    head1->next->next->next->next = new struct ListNode(4);

    ListNode* head2 = new ListNode(10);
    head2->next = new struct ListNode(11);
    head2->next->next = new struct ListNode(12);
    head2->next->next->next = head1->next->next;

    auto ptr = FindFirstCommonNode_1(head1, head2);
    printf("%d\n", ptr->val);

    getchar();
    return 0;
}
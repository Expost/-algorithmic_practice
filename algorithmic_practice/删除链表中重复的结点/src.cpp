#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;

    ListNode(int x) :
        val(x), next(NULL) {
    }
};

ListNode* deleteDuplication(ListNode* pHead)
{
    return pHead;
}

int main()
{
    ListNode* head = new struct ListNode(1);
    head->next = new struct ListNode(2);
    head->next->next = new struct ListNode(3);
    head->next->next->next = new struct ListNode(3);
    head->next->next->next->next = new struct ListNode(4);
    head->next->next->next->next->next = new struct ListNode(4);
    head->next->next->next->next->next->next = new struct ListNode(5);

    auto node = deleteDuplication(head);
    while (node != nullptr)
    {
        printf("%d ", node->val);
        node = node->next;
    }

    getchar();
    return 0;
}
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
    auto new_head = pHead;
    if (pHead == nullptr)
        return pHead;

    auto node = pHead;
    while (node && node->next && node->val == node->next->val)
    {
        auto val = node->val;
        while (node->next && val == node->next->val)
        {
            node = node->next;
        }

        node = node->next;
        new_head = node;
    }

    auto pre = new_head;
    while (node && node->next != nullptr)
    {
        bool flag = false;
        while (node->next && node->val == node->next->val)
        {
            node->next = node->next->next;
            flag = true;
        }

        if (flag)
        {
            pre->next = node->next;
        }
        else
        {
            pre = node;
        }

        node = node->next;
    }

    return new_head;
}

int main()
{
    ListNode* head = new struct ListNode(1);
    head->next = new struct ListNode(1);
    head->next->next = new struct ListNode(1);
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

    printf("\n");

    ListNode* head1 = new struct ListNode(1);
    head1->next = new struct ListNode(1);
    head1->next->next = new struct ListNode(1);
    head1->next->next->next = new struct ListNode(2);
    head1->next->next->next->next = new struct ListNode(3);
    head1->next->next->next->next->next = new struct ListNode(3);
    head1->next->next->next->next->next->next = new struct ListNode(5);

    node = deleteDuplication(head1);
    while (node != nullptr)
    {
        printf("%d ", node->val);
        node = node->next;
    }

    getchar();
    return 0;
}
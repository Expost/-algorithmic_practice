#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};

// 以某个链表为基准，在其之上进行操作
ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
{
    ListNode* head = nullptr;
    ListNode* head1 = nullptr;
    ListNode* head2 = nullptr;

    if (pHead1 == nullptr)
    {
        return pHead2;
    }
    if (pHead2 == nullptr)
    {
        return pHead1;
    }

    if (pHead1->val < pHead2->val)
    {
        head = head1 = pHead1;
        head2 = pHead2;
    }
    else
    {
        head = head1 = pHead2;
        head2 = pHead1;
    }

    for (;head1->next != nullptr && head2 != nullptr;)
    {
        if (head2->val >= head1->val && head2->val < head1->next->val)
        {
            auto node1 = head1->next;
            auto node2 = head2->next;
            head1->next = head2;
            head1->next->next = node1;
            head2 = node2;
        }
        
        head1 = head1->next;
    }

    if (head1->next == nullptr)
    {
        head1->next = head2;
    }
    
    return head;
}

// 不以某个链表为基准，自己一开始感觉比较麻烦，在看了讨论后，发现也没那么麻烦，比上面的思路反而更清晰一些
ListNode* Merge1(ListNode* pHead1, ListNode* pHead2)
{
    if (pHead2 == nullptr)
    {
        return pHead1;
    }
    if (pHead1 == nullptr)
    {
        return pHead2;
    }

    ListNode* head = nullptr;
    ListNode* pos = nullptr;
    while (pHead1 != nullptr && pHead2 != nullptr)
    {
        if (pHead1->val < pHead2->val)
        {
            if (head == nullptr)
            {
                head = pos = pHead1;
            }
            else
            {
                pos->next = pHead1;
                pos = pos->next;
            }

            pHead1 = pHead1->next;
        }
        else
        {
            if (head == nullptr)
            {
                head = pos = pHead2;
            }
            else
            {
                pos->next = pHead2;
                pos = pos->next;
            }

            pHead2 = pHead2->next;
        }
    }

    if (pHead1 == nullptr)
    {
        pos->next = pHead2;
    }
    else 
    {
        pos->next = pHead1;
    }

    return head;
}

// 在讨论中还看到了递归的实现，完全没想到还能用递归。。。而且代码很简单
ListNode* Merge2(ListNode* pHead1, ListNode* pHead2)
{
    if (pHead1 == nullptr)
    {
        return pHead2;
    }
    if (pHead2 == nullptr)
    {
        return pHead1;
    }

    if (pHead1->val < pHead2->val)
    {
        pHead1->next = Merge2(pHead1->next, pHead2);
        return pHead1;
    }
    else
    {
        pHead2->next = Merge2(pHead1, pHead2->next);
        return pHead2;
    }
}

int main()
{
    ListNode* head = new struct ListNode(0);
    head->next = new struct ListNode(1);
    //head->next->next = new struct ListNode(2);
    //head->next->next->next = new struct ListNode(3);
    //head->next->next->next->next = new struct ListNode(4);

    ListNode* head1 = new struct ListNode(0);
    head1->next = new struct ListNode(3);
    head1->next->next = new struct ListNode(5);
    head1->next->next->next = new struct ListNode(10);
    head1->next->next->next->next = new struct ListNode(11);

    ListNode* merge_head = Merge1(head, head1);
    for (auto tmp = merge_head; tmp != nullptr; tmp = tmp->next)
    {
        printf("%d\n", tmp->val);
    }

    getchar();
    return 0;
}
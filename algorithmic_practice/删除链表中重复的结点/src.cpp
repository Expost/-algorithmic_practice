#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;

    ListNode(int x) :
        val(x), next(NULL) {
    }
};

// 未处理内存泄露问题，这点要注意
// 实际实现中可使用智能指针解决
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

// 主要需要处理两种情况，即链表头是重复结点的情况以及链表头不是但中间结点是重复结点的情况
// 上面的方式是先处理链表头是重复的，没有则不处理，之后处理链表中间的，整个过程比较繁琐
// 参考讨论，可以通过增加虚拟链表头结点的方式，将重复结点都转换为链表中间是重复节点的情况。
ListNode* deleteDuplication_1(ListNode* pHead)
{
    auto new_head = new ListNode(0x7fffffff);
    new_head->next = pHead;
    
    auto pre = new_head;
    // 这里的node指向的是下一个结点，因此出现new_head与pHead的值相同的情况
    auto node = new_head->next;
    while (node != nullptr && node->next != nullptr)
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

    return new_head->next;
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

    auto node = deleteDuplication_1(head);
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

    node = deleteDuplication_1(head1);
    while (node != nullptr)
    {
        printf("%d ", node->val);
        node = node->next;
    }

    getchar();
    return 0;
}
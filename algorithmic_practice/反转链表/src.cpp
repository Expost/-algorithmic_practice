#include <stdio.h>



struct ListNode {
    int val;
    struct ListNode *next;

    ListNode(int x) :
        val(x), next(NULL) {
    }
};

// 自己的递归实现，随后看了下别人的递归实现，感觉自己这代码真是垃圾😭
// 已经忘记了链表该如何反转了，知道的话，第一印象应该不会像我这样写
ListNode* g_reverse_head = nullptr;
ListNode* Reverse(ListNode* pHead)
{
    ListNode *node = nullptr;
    if (pHead->next != nullptr)
    {
        node = Reverse(pHead->next);
    }
    else
    {
        g_reverse_head = pHead;
        return pHead;
    }

    node->next = pHead;
    return pHead;
}

ListNode* ReverseList(ListNode* pHead) 
{
    if (pHead == nullptr)
    {
        return nullptr;
    }

    auto node = Reverse(pHead);
    node->next = nullptr;

    return g_reverse_head;
}


// 别人的递归实现
ListNode* ReverseList1(ListNode *pHead)
{
    if (pHead == nullptr || pHead->next == nullptr)
    {
        return pHead;
    }

    auto reverse_head = ReverseList1(pHead->next);
    pHead->next->next = pHead;
    pHead->next = nullptr;

    return reverse_head;
}

// 根据上面的递归程序也很容易写出对应的循环代码
ListNode* ReverseList2(ListNode *pHead)
{
    if (pHead == nullptr)
    {
        return nullptr;
    }

    ListNode* reverse_head = nullptr;
    ListNode* pre = nullptr;
    for (auto tmp = pHead; tmp != nullptr;)
    {
        auto next = tmp->next;
        if (next == nullptr)
        {
            reverse_head = tmp;
        }

        tmp->next = pre;
        pre = tmp;
        tmp = next;
    }

    return reverse_head;
}

int main()
{
    ListNode* head = new struct ListNode(0);
    head->next = new struct ListNode(1);
    head->next->next = new struct ListNode(2);
    head->next->next->next = new struct ListNode(3);
    head->next->next->next->next = new struct ListNode(4);

    ListNode *reverse_head = ReverseList2(head);
    for (auto tmp = reverse_head; tmp != nullptr; tmp = tmp->next)
    {
        printf("%d\n", tmp->val);
    }


    getchar();
    return 0;
}
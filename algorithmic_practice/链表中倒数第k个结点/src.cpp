#include <stdio.h>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;

    ListNode(int x) :
            val(x), next(NULL) {
    }
};

// 脑子笨，直接上vector了
ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) 
{
    vector<ListNode*> values;
    for (auto *ptr = pListHead; ptr != NULL; ptr = ptr->next)
    {
        values.push_back(ptr);
    }

    int count = values.size();
    if (k > count || k == 0)
    {
        return nullptr;
    }

    return values[count - k];
}

// 大佬的解法，确实很巧妙，自己还是想的太少了，直接将脑子中的思路写出来了，没有再细想
ListNode* FindKthToTail2(ListNode* pListHead, unsigned int k)
{
    auto ptr1 = pListHead;
    auto ptr2 = pListHead;
    unsigned int i = 0;
    for (; ptr1 != NULL; ptr1 = ptr1->next, i++)
    {
        if (i >= k)
        {
            ptr2 = ptr2->next;
        }
    }

    return i < k ? nullptr : ptr2;
}

int main()
{
    ListNode* head = new struct ListNode(0);
    head->next = new struct ListNode(1);
    head->next->next = new struct ListNode(2);
    head->next->next->next = new struct ListNode(3);
    head->next->next->next->next = new struct ListNode(4);

    auto ptr = FindKthToTail2(head, 1);
    if (ptr)
    {
        printf("value %d\n", ptr->val);
    }

    ptr = FindKthToTail2(head, 2);
    if (ptr)
    {
        printf("value %d\n", ptr->val);
    }

    ptr = FindKthToTail2(head, 3);
    if (ptr)
    {
        printf("value %d\n", ptr->val);
    }

    ptr = FindKthToTail2(head, 4);
    if (ptr)
    {
        printf("value %d\n", ptr->val);
    }

    ptr = FindKthToTail2(head, 5);
    if (ptr)
    {
        printf("value %d\n", ptr->val);
    }

    getchar();
    return 0;
}
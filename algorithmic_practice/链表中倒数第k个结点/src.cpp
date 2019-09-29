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

// ���ӱ���ֱ����vector��
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

// ���еĽⷨ��ȷʵ������Լ��������̫���ˣ�ֱ�ӽ������е�˼·д�����ˣ�û����ϸ��
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
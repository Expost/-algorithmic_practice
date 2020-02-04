#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;

    ListNode(int x) :
        val(x), next(NULL) {
    }
};

// δ�����ڴ�й¶���⣬���Ҫע��
// ʵ��ʵ���п�ʹ������ָ����
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

// ��Ҫ��Ҫ�������������������ͷ���ظ���������Լ�����ͷ���ǵ��м������ظ��������
// ����ķ�ʽ���ȴ�������ͷ���ظ��ģ�û���򲻴���֮���������м�ģ��������̱ȽϷ���
// �ο����ۣ�����ͨ��������������ͷ���ķ�ʽ�����ظ���㶼ת��Ϊ�����м����ظ��ڵ�������
ListNode* deleteDuplication_1(ListNode* pHead)
{
    auto new_head = new ListNode(0x7fffffff);
    new_head->next = pHead;
    
    auto pre = new_head;
    // �����nodeָ�������һ����㣬��˳���new_head��pHead��ֵ��ͬ�����
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
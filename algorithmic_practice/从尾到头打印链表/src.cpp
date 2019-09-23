
#include <stdio.h>
#include <vector>
#include <iostream>

using namespace std;
// ����һ�������������β��ͷ��˳�򷵻�һ��ArrayList��

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
            val(x), next(NULL) {
    }
};

// �Լ���ʵ�֣�������vector��inster���������ڲ��ڴ�����϶�
// ���Ŀɿ���ʹ�õݹ�ʵ�֣���ȻҲ�н���ջ��ʵ��
vector<int> printListFromTailToHead(ListNode* head) {
    vector<int> vec;

    ListNode *ptr = head;
    while (ptr != nullptr)
    {
        vec.insert(vec.begin(), ptr->val);
        ptr = ptr->next;
    }
    
    return vec;
}

// �ݹ�ʵ�֣����ڷ���ֵ��β��
vector<int> PrintListFromTailToHead(ListNode* head) {
    vector<int> vec;
    if (head == nullptr)
    {
        return vec;
    }

    auto tmp_vec = PrintListFromTailToHead(head->next);
    vec.insert(vec.end(), tmp_vec.begin(), tmp_vec.end());
    vec.push_back(head->val);
    return vec;
}

int main()
{
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new struct ListNode(3);
    head->next->next->next = new struct ListNode(4);
    head->next->next->next->next = new struct ListNode(5);

    auto vec = PrintListFromTailToHead(head);

    for (auto &itr : vec)
    {
        printf("val is %d\n", itr);
    }

    getchar();
    return 0;
}
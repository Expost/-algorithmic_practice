#include <stdio.h>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// �Լ�˼���������ַ�ʽ
// 1. ������ӳ�䵽�����У�������п��Ż���ţ�֮�������������
// 2. ʹ�ù鲢��������ӳ��
// ����ʱ��ʽ1������ӳ�䵽�����У����ÿ�������
ListNode* sortList(ListNode* head) {


    return nullptr;
}

int main() {
    auto head = new ListNode(4);
    head->next = new ListNode(2);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(3);

    auto ret = sortList(head);
    for (auto node = ret; node != nullptr;node = node->next) {
        printf("%d ", node->val);
    }

    printf("\n");

    getchar();
    return 0;
}
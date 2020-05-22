#include <stdio.h>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// 自己思考的有两种方式
// 1. 将链表映射到数组中，对其进行快排或堆排，之后再重组成链表
// 2. 使用归并排序，无需映射
// 下面时方式1，将其映射到数组中，采用快排排序
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
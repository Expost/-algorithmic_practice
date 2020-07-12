#include <stdio.h>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// 实现过于复杂
//ListNode* rotateRight(ListNode* head, int k) {
//    if (!head || !head->next)return head;
//    int count = 0;
//    for (auto node = head; node != nullptr; node = node->next) {
//        count++;
//    }
//
//    k = k % count;
//
//    auto first = head;
//    for (int i = 0; i < k; i++) {
//        if (first->next == nullptr) {
//            first = head;
//        }
//        else {
//            first = first->next;
//        }
//    }
//
//    auto sec = head;
//    while (first->next != nullptr) {
//        first = first->next;
//        sec = sec->next;
//    }
//
//    ListNode* new_head = nullptr;
//    if (sec->next == nullptr) {
//        new_head = head;
//    }
//    else {
//        new_head = sec->next;
//        sec->next = nullptr;
//        first->next = head;
//    }
//
//    return new_head;
//}

// 官方讨论，没想到
ListNode* rotateRight(ListNode* head, int k) {

}

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);

    auto ret = rotateRight(head, 2000000000);
    for (auto node = ret; node != nullptr; node = node->next) {
        printf("%d ", node->val);
    }
    printf("\n");

    head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    ret = rotateRight(head, 2);
    for (auto node = ret; node != nullptr; node = node->next) {
        printf("%d ", node->val);
    }
    printf("\n");

    head = new ListNode(0);
    head->next = new ListNode(1);
    head->next->next = new ListNode(2);
    ret = rotateRight(head, 4);
    for (auto node = ret; node != nullptr; node = node->next) {
        printf("%d ", node->val);
    }

    getchar();
    return 0;
}
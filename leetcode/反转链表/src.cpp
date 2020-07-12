#include <stdio.h>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}  
};

// µİ¹é
//ListNode* g_head = nullptr;
//ListNode* tmp_reverse(ListNode* head) {
//    if (!head)return nullptr;
//
//    ListNode *ret = tmp_reverse(head->next);
//    if (!ret) {
//        g_head = head;
//    }
//    else {
//        ret->next = head;
//    }
//
//    return head;
//}
//
//ListNode* reverseList(ListNode* head) {
//    if (!head)return nullptr;
//    ListNode* ret = tmp_reverse(head);
//    ret->next = nullptr;
//    return g_head;
//}

// µü´ú
ListNode* reverseList(ListNode* head) {
    if (!head || !head->next)return head;

    ListNode* prev_node = head;
    ListNode* node = head->next;
    for (; node != nullptr; ) {
        ListNode* next = node->next;
        node->next = prev_node;
        if (prev_node == head) prev_node->next = nullptr;
        prev_node = node;
        node = next;
    }

    return prev_node;
}

int main() {
    ListNode* head = nullptr;
    ListNode* ret = nullptr;

    head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    ret = reverseList(head);
    for (auto node = ret; node != nullptr; node = node->next) {
        printf("%d ", node->val);
    }

    getchar();
    return 0;
}
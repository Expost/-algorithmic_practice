#include <stdio.h>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode tmp_head(0);
    ListNode* head = &tmp_head;
    int in = 0;
    while (l1 != nullptr && l2 != nullptr) {
        int val = l1->val + l2->val + in;
        in = val / 10;
        int real_val = val % 10;
        head->next = new ListNode(real_val);
        head = head->next;
        l1 = l1->next;
        l2 = l2->next;
    }

    while (l1 != nullptr) {
        int val = l1->val + in;
        in = val / 10;
        int real_val = val % 10;
        head->next = new ListNode(real_val);
        head = head->next;
        l1 = l1->next;
    }


    while (l2 != nullptr) {
        int val = l2->val + in;
        in = val / 10;
        int real_val = val % 10;
        head->next = new ListNode(real_val);
        head = head->next;
        l2 = l2->next;
    }

    if (in != 0) {
        head->next = new ListNode(in);
    }

    return tmp_head.next;
}

int main() {
    ListNode* head1 = nullptr;
    ListNode* head2 = nullptr;
    ListNode* ret = nullptr;

    head1 = new ListNode(9);
    head1->next = new ListNode(9);
    head1->next->next = new ListNode(9);
    head2 = new ListNode(1);
    head2->next = new ListNode(1);
    head2->next->next = new ListNode(1);

    ret = addTwoNumbers(head1, head2);
    for (auto node = ret; node != nullptr; node = node->next) {
        printf("%d ", node->val);
    }

    getchar();
    return 0;
}
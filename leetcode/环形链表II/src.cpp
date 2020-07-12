#include <stdio.h>
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *detectCycle(ListNode *head) {
    auto slow = head;
    auto quick = head;

    while (quick != nullptr && quick->next != nullptr) {
        slow = slow->next;
        quick = quick->next->next;

        if (slow == quick)
            break;
    }

    if (!quick || !quick->next)return nullptr;

    quick = head;
    while (quick != slow) {
        quick = quick->next;
        slow = slow->next;
    }

    return quick;
}

int main() {

    ListNode* head = new ListNode(3);
    head->next = new ListNode(2);
    head->next->next = new ListNode(0);
    head->next->next->next = new ListNode(-4);
    head->next->next->next->next = head->next;

    auto ret = detectCycle(head);
    printf("%d\n", ret->val);

    head = new ListNode(1);
    head->next = new ListNode(2);
    //head->next->next = new ListNode(3);
    ret = detectCycle(head);
    printf("%d\n", ret->val);

    getchar();
    return 0;
}
#include <stdio.h>
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


bool hasCycle(ListNode *head) {
    if (!head || !head->next)return false; 

    auto slow = head->next;
    auto quick = head->next->next;
    while (slow != nullptr && quick != nullptr && quick->next != nullptr) {
        if (slow == quick) return true;
        
        slow = slow->next;
        quick = quick->next->next;
    }

    return false;
}

int main() {

    ListNode* head = new ListNode(3);
    head->next = new ListNode(2);
    head->next->next = new ListNode(0);
    head->next->next->next = new ListNode(-4);
    head->next->next->next->next = head->next;

    bool ret = hasCycle(head);
    printf("%d\n", ret);

    head = new ListNode(1);
    head->next = new ListNode(2);
    //head->next->next = new ListNode(3);
    ret = hasCycle(head);
    printf("%d\n", ret);

    getchar();
    return 0;
}
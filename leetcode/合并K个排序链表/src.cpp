#include <stdio.h>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// 暴力，时间最慢
//ListNode* mergeKLists(vector<ListNode*>& lists) {
//    ListNode tmp_node(0);
//    ListNode* head = &tmp_node;
//
//    while (true) {
//        int null_count = 0;
//        int min_index = 0;
//        int min_val = INT_MAX;
//        for (int i = 0; i < lists.size(); i++) {
//            if (lists[i] == nullptr) {
//                null_count++;
//                continue;
//            }
//
//            if (lists[i]->val < min_val) {
//                min_val = lists[i]->val;
//                min_index = i;
//            }
//        }
//
//        if (null_count == lists.size())break;
//
//        head->next = lists[min_index];
//        head = head->next;
//        lists[min_index] = lists[min_index]->next;
//    }
//
//    return tmp_node.next;
//}

int main() {
    vector<ListNode*> v;
    ListNode* h1 = new ListNode(1);
    h1->next = new ListNode(4);
    h1->next->next = new ListNode(5);
    ListNode* h2 = new ListNode(1);
    h2->next = new ListNode(3);
    h2->next->next = new ListNode(4);
    ListNode* h3 = new ListNode(2);
    h3->next = new ListNode(6);

    v = { h1, h2, h3 };
    ListNode* ret = mergeKLists(v);
    for (auto node = ret; node != nullptr; node = node->next) {
        printf("%d ", node->val);
    }

    getchar();
    return 0;
}
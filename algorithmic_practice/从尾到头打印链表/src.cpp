
#include <stdio.h>
#include <vector>
#include <iostream>

using namespace std;
// 输入一个链表，按链表从尾到头的顺序返回一个ArrayList。

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
            val(x), next(NULL) {
    }
};

// 自己的实现，利用了vector的inster方法，其内部内存操作较多
// 查阅可考虑使用递归实现，当然也有借助栈的实现
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

// 递归实现，基于返回值的尾插
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
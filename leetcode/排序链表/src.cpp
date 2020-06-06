#include <stdio.h>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// �Լ�˼���������ַ�ʽ�����з�ʽ1��ʱ�临�ӶȻ��пռ临�Ӷ��ǲ���������ģ�
// ��Ҳ����ʵ�֣���ϰ���źͶ��ŵ�ʵ��
// 1. ������ӳ�䵽�����У�������п��Ż���ţ�֮�������������
// 2. ʹ�ù鲢��������ӳ��

// �����Ƿ�ʽ1������ӳ�䵽�����У����ÿ�������
void quick_sort(vector<ListNode*> &v, int l, int r) {
    int left = l;
    int right = r;

    if (left >= right)return;
    ListNode* data = v[left];
    while (left < right) {
        while (left < right && v[right]->val > data->val)
            right--;
        
        if(left < right)
            v[left++] = v[right];
        
        while (left < right && v[left]->val < data->val)
            left++;

        if(left < right)
            v[right--] = v[left];
    }

    quick_sort(v, l, left - 1);
    quick_sort(v, left + 1, r);

    v[left] = data;
}

// ��ʽ1������ӳ�䵽�����У�ʹ�ö���
void adjust(vector<ListNode*> &v, int index, int count) {
    if (count <= 0) return;

    for (int node = index * 2 + 1; node < count; node = node * 2 + 1) {
        
        if (node + 1 < count && v[node + 1]->val > v[node]->val)
            node++;

        if (v[node]->val < v[index]->val) {
            break;
        }

        ListNode* tmp = v[index];
        v[index] = v[node];
        v[node] = tmp;
        index = node;
    }
}

void heap_sort(vector<ListNode*> &v) {
    if (v.empty())return;

    for (int i = v.size() / 2 - 1; i >= 0; i--) {
        adjust(v, i, v.size());
    }
    
    for (int i = v.size() - 1; i >= 0; i--) {
        ListNode* tmp = v[0];
        v[0] = v[i];
        v[i] = tmp;

        adjust(v, 0, i);
    }
}

//ListNode* sortList(ListNode* head) {
//    if (!head) return nullptr;
//    vector<ListNode*> v;
//    for (auto node = head;node != nullptr;node = node->next) {
//        v.push_back(node);
//    }
//
//    //quick_sort(v, 0, v.size() - 1);
//    heap_sort(v);
//
//    for (int i = 0; i < v.size();i++) {
//        if (i + 1 < v.size()) {
//            v[i]->next = v[i + 1];
//        }
//        else {
//            v[i]->next = nullptr;
//        }
//    }
//
//    return v[0];
//}


ListNode* merge_list(ListNode* first, ListNode* second) {
    if (first == nullptr)return second;
    if (second == nullptr)return first;

    ListNode* i = first;
    ListNode* j = second;
    ListNode tmp(0);
    ListNode* head = &tmp;
    while (i != nullptr && j != nullptr) {
        if (i->val < j->val) {
            head->next = i;
            i = i->next;
        }
        else {
            head->next = j;
            j = j->next;
        }
        
        head = head->next;
    }

    head->next = i == nullptr ? j : i;

    return tmp.next;
}

// ���Ը���鲢���򣬳�ʱ��ʵ�������⣬���������Լ�û�ж��֣����Ǳ����������ֿ���ʹ�ÿ���ָ�룬�Լ�����
//ListNode* sortList(ListNode* head) {
//    if (head == nullptr)return nullptr;
//
//    ListNode* second = head->next;
//    head->next = nullptr;
//
//    ListNode* s = sortList(second);
//    return merge_list(head, s);
//}

// ��Ϊ����ָ�룬����ʹ�ö��֣���ʱ����ɽ���ˣ��������Ŀռ临�Ӷ����ɺܸߣ�ԭ����������ʹ���˵ݹ�
// ��Ҫ�������Ϊ������ʽ
//ListNode* sortList(ListNode* head) {
//    if (!head || !head->next) return head;
//
//    ListNode* slow = head;
//    ListNode* fast = head->next;
//    while (fast && fast->next) {
//        slow = slow->next;
//        fast = fast->next->next;
//    }
//
//    ListNode* tmp = slow->next;
//    slow->next = nullptr;
//
//    ListNode* s = sortList(head);
//    ListNode* f = sortList(tmp);
//    return merge_list(s, f);
//}

// �ο����ۣ�������ʽʵ������

ListNode* cut(ListNode* head, int size) {
    while (--size && head) head = head->next;
    
    if (!head)return nullptr;

    ListNode* tmp = head->next;
    head->next = nullptr;
    return tmp;
}

ListNode* sortList(ListNode* head) {
    ListNode dummy_head(0);
    dummy_head.next = head;
    ListNode* tmp = head;
    int len = 0;
    while (tmp != nullptr) {
        tmp = tmp->next;
        len++;
    }

    for (int size = 1; size < len; size *= 2) {
        ListNode* curr = dummy_head.next;
        auto tail = &dummy_head;

        while (curr) {
            ListNode* left = curr;
            ListNode* right = cut(left, size);
            curr = cut(right, size);
            tail->next = merge_list(left, right);

            while (tail->next) {
                tail = tail->next;
            }
        }
    }

    return dummy_head.next;
}

int main() {
    ListNode* head = nullptr;
    ListNode* ret = nullptr;

    head = new ListNode(-1);
    head->next = new ListNode(5);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(0);
    ret = sortList(head);
    for (auto node = ret; node != nullptr; node = node->next) {
        printf("%d ", node->val);
    }

    printf("\n");


    head = new ListNode(4);
    head->next = new ListNode(2);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(3);

    ret = sortList(head);
    for (auto node = ret; node != nullptr ;node = node->next) {
        printf("%d ", node->val);
    }

    printf("\n");



    getchar();
    return 0;
}
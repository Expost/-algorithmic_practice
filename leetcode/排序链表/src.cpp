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


void adjust(vector<ListNode*> &v) {

}


void heap_sort(vector<ListNode*> &v) {

}



ListNode* sortList(ListNode* head) {
    if (!head) return nullptr;
    vector<ListNode*> v;
    for (auto node = head;node != nullptr;node = node->next) {
        v.push_back(node);
    }

    quick_sort(v, 0, v.size() - 1);

    for (int i = 0; i < v.size();i++) {
        if (i + 1 < v.size()) {
            v[i]->next = v[i + 1];
        }
        else {
            v[i]->next = nullptr;
        }
    }

    return v[0];
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
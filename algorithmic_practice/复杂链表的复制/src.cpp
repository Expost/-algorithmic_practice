#include <stdio.h>
#include <vector>
using namespace std;

struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};

// ͨ������vector�����������random��Ϣ
// ע��random�п���Ϊnull
RandomListNode* Clone(RandomListNode* pHead)
{
    vector<pair<RandomListNode*, RandomListNode*>> v0;
    vector<RandomListNode*> v1;

    RandomListNode head(0);
    RandomListNode* tmp_head = &head;
    for (; pHead != nullptr; pHead = pHead->next)
    {
        tmp_head->next = new struct RandomListNode(pHead->label);
        tmp_head = tmp_head->next;
        v1.push_back(tmp_head);
        v0.push_back({ pHead, pHead->random });
    }

    for (int i = 0; i < v1.size(); i++)
    {
        auto target = v0[i].second;
        int j = 0;
        bool found = false;
        for (; j < v0.size(); j++)
        {
            if (target == v0[j].first)
            {
                found = true;
                break;
            }
        }

        if (found)
        {
            v1[i]->random = v1[j];
        }
        // ��Ŀ˵������ڵ㣬��˿���ָ��������е������ڵ�
        // ��������û�ҵ����ֲ�Ϊ��ʱ����������������Լ��ϸ��жϲ�����һ���µĽڵ�
        else if(v0[i].first->random != nullptr)
        {
            v1[i]->random = new struct RandomListNode(v0[i].first->random->label);
        } 
    }

    return head.next;
}

// �鿴��������ۣ�ȷʵ�и��Ž⣬������Լ��޷��뵽��
// 3����
// 1. �Ѹ��ƵĽ��������ԭʼ�����ÿһ��Ӧ������
// 2. �Ѹ��ƵĽ���randomָ��ָ�򱻸��ƽ���randomָ�����һ�����
// 3. ��ֳ�������������λ��Ϊԭ����ż��λ��Ϊ��������
// ������1���ݹ鷨����һ�о���ţ�ƣ�����ϸ�����ִ��ˡ�����


int main()
{
    RandomListNode *head = new RandomListNode(0);
    head->next = new struct RandomListNode(1);
    head->next->next = new struct RandomListNode(2);
    head->random = head->next->next;
    head->next->random = head;
    head->next->next->random = new struct RandomListNode(3);

    auto clone_head = Clone(head);
    for (; clone_head != nullptr; clone_head = clone_head->next)
    {
        printf("%p %p %d\n", clone_head, clone_head->random, clone_head->label);
    }

    clone_head = Clone(nullptr);
    printf("%p\n", clone_head);

    getchar();
    return 0;
}
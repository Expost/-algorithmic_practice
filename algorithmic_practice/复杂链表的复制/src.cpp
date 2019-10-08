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

// 通过两个vector保存了链表的random信息
// 注意random有可能为null
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
        // 题目说是任意节点，因此可能指向非链表中的其他节点
        // 因此这里既没找到，又不为空时即满足该条件，所以加上该判断并复制一个新的节点
        else if(v0[i].first->random != nullptr)
        {
            v1[i]->random = new struct RandomListNode(v0[i].first->random->label);
        } 
    }

    return head.next;
}

// 查看了相关讨论，确实有更优解，这点是自己无法想到的
// 3步法
// 1. 把复制的结点链接在原始链表的每一对应结点后面
// 2. 把复制的结点的random指针指向被复制结点的random指针的下一个结点
// 3. 拆分成两个链表，奇数位置为原链表，偶数位置为复制链表
// 还看到1个递归法，第一感觉真牛逼，不过细看后发现错了。。。


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
#include <stdio.h>

struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :
        val(x), left(NULL), right(NULL), next(NULL) {
    }
};


// ������ʼû����ʲô��˼�������˸�һ���������ĸ��ڵ㣬����������н�㣬������������һ�����
//void GetNextNode(TreeLinkNode* root, TreeLinkNode*& pre)
//{
//    if (root == nullptr)
//    {
//        return;
//    }
//
//    GetNextNode(root->left, pre);
//    if (pre)
//    {
//        pre->next = root;
//    }
//    
//    pre = root;
//    GetNextNode(root->right, pre);
//}
//
//TreeLinkNode* GetNext(TreeLinkNode* pNode)
//{
//    TreeLinkNode *pre = nullptr;
//    GetNextNode(pNode, pre);
//    return pNode->next;
//}

// �ο����ۣ�ʵ������
TreeLinkNode* GetNext(TreeLinkNode* pNode)
{
    if (pNode == nullptr)
        return nullptr;

    if (pNode->right)
    {
        auto node = pNode->right;
        while (node->left)
        {
            node = node->left;
        }

        return node;
    }

    auto node = pNode;
    while (node->next)
    {
        if (node->next->left == node)
            return node->next;
        node = node->next;
    }

    return nullptr;
}

int main()
{
// ��������̬
//            1
//        /       \
//    2               3
//  /              /    \
//4               5       6
//  \                   /
//   7                 8

    TreeLinkNode *root = new TreeLinkNode(1);
    root->left = new struct TreeLinkNode(2);
    root->left->next = root;

    root->left->left = new struct TreeLinkNode(4);
    root->left->left->next = root->left;

    root->left->left->right = new struct TreeLinkNode(7);
    root->left->left->right->next = root->left->left;

    root->right = new struct TreeLinkNode(3);
    root->right->next = root;

    root->right->left = new struct TreeLinkNode(5);
    root->right->left->next = root->right;

    root->right->right = new struct TreeLinkNode(6);
    root->right->right->next = root->right;

    root->right->right->left = new struct TreeLinkNode(8);
    root->right->right->left->next = root->right->right;

    auto r = GetNext(root);
    if(r)
        printf("%d\n", r->val);

    getchar();
    return 0;
}
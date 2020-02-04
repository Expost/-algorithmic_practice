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


// 这道题最开始没明白什么意思，做成了给一个二叉树的根节点，中序遍历所有结点，并给出结点的下一个结点
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

// 参考讨论，实现如下
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
// 二叉树形态
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
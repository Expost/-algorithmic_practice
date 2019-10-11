#include <stdio.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
        val(x), left(NULL), right(NULL) {
    }
};

// �ʼֻ֪���õݹ飬��û��ʲô˼·�����ո��������ˡ���������Ȼ��϶���������ķ���
// ������һ��ѭ����ʵ���ǲ���
TreeNode* Convert(TreeNode* pRootOfTree)
{
    if (pRootOfTree == nullptr)
    {
        return nullptr;
    }

    auto left = Convert(pRootOfTree->left);
    auto right = Convert(pRootOfTree->right);
    if (left)
    {
        auto tmp = left;
        for (; tmp->right != nullptr; tmp = tmp->right);
        tmp->right = pRootOfTree;
        pRootOfTree->left = tmp;
    }

    pRootOfTree->right = right;
    if (right)
    {
        right->left = pRootOfTree;
    }

    return left != nullptr ? left : pRootOfTree;
}

// �ο����ۣ����˵�ʵ�֣�Ӧ����ʹ���������������
// ����ң�����һ����ʱ����ʱ��ָ��root����������ҵ�˳��
// ��ô�Ͳ������Լ���������ѭ�������һ�����ˡ�
TreeNode* real_head = nullptr;
void ConvertSub(TreeNode* root, TreeNode*& pre)
{
    if (root == nullptr)
    {
        return;
    }

    ConvertSub(root->left, pre);
    if (real_head == nullptr)
    {
        real_head = root;
    }

    root->left = pre;
    if (pre)
    {
        pre->right = root;
    }

    pre = root;
    ConvertSub(root->right, pre);
}

TreeNode* Convert_1(TreeNode* pRootOfTree)
{
    if (pRootOfTree == nullptr)
    {
        return nullptr;
    }

    TreeNode* pre = nullptr;
    ConvertSub(pRootOfTree, pre);
    
    return real_head;
}

int main()
{
// ��������̬
//           5 
//        /       \
//    4               7
//  /              /    \
//2              6       9
//  \                   /
//   3                 8
    TreeNode* root = new TreeNode(5);
    //root->left = new struct TreeNode(4);
    //root->left->left = new struct TreeNode(2);
    //root->left->left->right = new struct TreeNode(3);
    root->right = new struct TreeNode(7);
    root->right->left = new struct TreeNode(6);
    root->right->right = new struct TreeNode(9);
    root->right->right->left = new struct TreeNode(8);

    auto head = Convert_1(root);
    for (; head != nullptr; head = head->right)
    {
        printf("%d ", head->val);
        if (head->left)
        {
            printf("%d ", head->left->val);
        }

        printf("\n");
    }

    getchar();
    return 0;
}
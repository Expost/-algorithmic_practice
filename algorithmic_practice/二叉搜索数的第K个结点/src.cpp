#include <stdio.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
        val(x), left(NULL), right(NULL) {
    }
};

TreeNode* KthNode(TreeNode* pRoot, int k, int &index)
{
    if (pRoot == nullptr)
        return nullptr;

    auto left = KthNode(pRoot->left, k, index);
    if (left)
        return left;

    index++;
    if (index == k)
        return pRoot;
   
    auto right = KthNode(pRoot->right, k, index);
    if (right)
        return right;

    return nullptr;
}

TreeNode* KthNode(TreeNode* pRoot, int k)
{
    int index = 0;
    return KthNode(pRoot, k, index);
}

int main()
{
    // ¶ş²æÊ÷ĞÎÌ¬
    //           5 
    //        /       \
    //    4               7
    //  /              /    \
    //2              6       9
    //  \                   /
    //   3                 8
    TreeNode* root = new TreeNode(5);
    root->left = new struct TreeNode(4);
    root->left->left = new struct TreeNode(2);
    root->left->left->right = new struct TreeNode(3);
    root->right = new struct TreeNode(7);
    root->right->left = new struct TreeNode(6);
    root->right->right = new struct TreeNode(9);
    root->right->right->left = new struct TreeNode(8);

    auto node = KthNode(root, 8);
    if (node)
        printf("%d\n", node->val);

    getchar();
    return 0;
}
#include <stdio.h>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
        val(x), left(NULL), right(NULL) {
    }
};

// 使用递归的话将会很简单
void Mirror(TreeNode *pRoot) 
{
    if (pRoot == nullptr)
    {
        return;
    }

    TreeNode* tmp = pRoot->left;
    pRoot->left = pRoot->right;
    pRoot->right = tmp;
    Mirror(pRoot->left);
    Mirror(pRoot->right);
}

void print_tree(TreeNode* root)
{
    if (root == nullptr)
    {
        return;
    }

    printf("%d ", root->val);
    print_tree(root->left);
    print_tree(root->right);
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

    TreeNode *root = new TreeNode(1);
    root->left = new struct TreeNode(2);
    root->left->left = new struct TreeNode(4);
    root->left->left->right = new struct TreeNode(7);
    root->right = new struct TreeNode(3);
    root->right->left = new struct TreeNode(5);
    root->right->right = new struct TreeNode(6);
    root->right->right->left = new struct TreeNode(8);

    Mirror(root);

    print_tree(root);

    getchar();
    return 0;
}
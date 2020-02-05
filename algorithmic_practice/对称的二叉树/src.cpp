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

bool isSymmetrical(TreeNode* left, TreeNode* right)
{
    if (left && right)
    {
        return left->val == right->val &&
            isSymmetrical(left->left, right->right) &&
            isSymmetrical(left->right, right->left);
    }
    else if (left == nullptr && right == nullptr)
    {
        return true;
    }
    else
        return false;
}

bool isSymmetrical(TreeNode* pRoot)
{
    if (pRoot == nullptr)
        return true;

    return isSymmetrical(pRoot->left, pRoot->right);
}

int main()
{
    // 二叉树形态1
    //            1
    //        /       \
    //    2               3
    //  /              /    \
    //4               5       6
    //  \                   /
    //   7                 8

    TreeNode *root1 = new TreeNode(1);
    root1->left = new struct TreeNode(2);
    root1->left->left = new struct TreeNode(4);
    root1->left->left->right = new struct TreeNode(7);
    root1->right = new struct TreeNode(3);
    root1->right->left = new struct TreeNode(5);
    root1->right->right = new struct TreeNode(6);
    root1->right->right->left = new struct TreeNode(8);
    auto ret1 = isSymmetrical(root1);
    printf("%d\n", ret1);

    // 二叉树形态2
    //            1
    //        /       \
    //    2               2
    //  /  \            /    \
    //4     5          5       4
    //  \                   /
    //   7                 7

    TreeNode *root2 = new TreeNode(1);
    root2->left = new struct TreeNode(2);
    root2->left->left = new struct TreeNode(4);
    root2->left->left->right = new struct TreeNode(7);
    root2->left->right = new struct TreeNode(5);
    root2->right = new struct TreeNode(2);
    root2->right->left = new struct TreeNode(5);
    root2->right->right = new struct TreeNode(4);
    root2->right->right->left = new struct TreeNode(7);
    auto ret2 = isSymmetrical(root2);
    printf("%d\n", ret2);

    getchar();
    return 0;
}
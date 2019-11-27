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

void GetDepth(TreeNode* root, int depth, int &most_depth)
{
    if (root == nullptr)
    {
        return;
    }

    GetDepth(root->left, depth + 1, most_depth);
    GetDepth(root->right, depth + 1, most_depth);

    if (most_depth < depth)
        most_depth = depth;
}

int TreeDepth(TreeNode* pRoot)
{
    int depth = 0;
    GetDepth(pRoot, 1, depth);
    return depth;
}

// 看了讨论，上面的实现还是麻烦了些，唉😒
// 可以改成下面这样子
int TreeDepth_1(TreeNode* pRoot)
{
    if (pRoot == nullptr)
    {
        return 0;
    }

    int left = TreeDepth_1(pRoot->left);
    int right = TreeDepth_1(pRoot->right);
    return (left > right ? left : right) + 1;
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

    int depth = TreeDepth_1(root);
    printf("%d\n", depth);

    getchar();
    return 0;
}
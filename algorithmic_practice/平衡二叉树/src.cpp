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

int GetDepth(TreeNode* root, bool& ret)
{
    if (root == nullptr)
    {
        return 0;
    }

    int r1 = GetDepth(root->left, ret);
    int r2 = GetDepth(root->right,ret);

    ret = ret ? abs(r1 - r2) <= 1 : false;
    return (r1 > r2 ? r1 : r2) + 1;
}

bool IsBalanced_Solution(TreeNode* pRoot) {
    bool ret = true;
    GetDepth(pRoot, ret);
    return ret;
}

// 看了下讨论，上面的代码即使发现树不平衡，但还是遍历了所有的节点
// 因此还是可以优化下，发现不平衡后立马返回

int GetDepth_1(TreeNode* root, bool& ret)
{
    if (root == nullptr)
    {
        return 0;
    }

    int r1 = GetDepth_1(root->left, ret);
    if (r1 == -1) return -1;
    int r2 = GetDepth_1(root->right, ret);
    if (r2 == -1) return -1;

    ret = ret ? abs(r1 - r2) <= 1 : false;
    return ret ? ((r1 > r2 ? r1 : r2) + 1) : -1;
}

bool IsBalanced_Solution_1(TreeNode* pRoot) {
    bool ret = true;
    GetDepth_1(pRoot, ret);
    return ret;
}

int main()
{
    // 二叉树形态
    //            1
    //        /       \
    //    2               3
    //  /  \            /    \
    //4     5          5       6
    //  \                   /
    //   7                 8

    TreeNode *root = new TreeNode(1);
    root->left = new struct TreeNode(2);
    root->left->left = new struct TreeNode(4);
    //root->left->right = new struct TreeNode(5);
    root->left->left->right = new struct TreeNode(7);
    root->right = new struct TreeNode(3);
    root->right->left = new struct TreeNode(5);
    root->right->right = new struct TreeNode(6);
    root->right->right->left = new struct TreeNode(8);

    int depth = IsBalanced_Solution_1(root);
    printf("%d\n", depth);

    getchar();
    return 0;
}
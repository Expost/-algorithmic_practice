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

int main()
{
    // ¶þ²æÊ÷ÐÎÌ¬
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
    root->left->right = new struct TreeNode(5);
    root->left->left->right = new struct TreeNode(7);
    root->right = new struct TreeNode(3);
    root->right->left = new struct TreeNode(5);
    root->right->right = new struct TreeNode(6);
    root->right->right->left = new struct TreeNode(8);

    int depth = IsBalanced_Solution(root);
    printf("%d\n", depth);

    getchar();
    return 0;
}
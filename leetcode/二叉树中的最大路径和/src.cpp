#include <stdio.h>
#include <stdint.h>
#include <limits.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 这道题思路倒是好想，只是调试程序以及情况考虑不完全导致提交次数过多
//int maxPath(TreeNode* root, int &max_value) {
//    if (root == nullptr) return INT_MIN;
//
//    int left_value = INT_MIN;
//    int right_value = INT_MIN;
//
//    left_value = maxPath(root->left, max_value);
//    int root_value = root->val;    
//    right_value = maxPath(root->right, max_value);
//
//    int left_root_right = root_value;
//    int right_root = root_value;
//    int left_root = root_value;
//
//    if (left_value != INT_MIN && right_value != INT_MIN)
//        left_root_right += left_value + right_value;
//
//    if (left_value != INT_MIN)
//        left_root += left_value;
//    if (right_value != INT_MIN)
//        right_root += right_value;
//
//    max_value = max(max_value, root_value);
//    max_value = max(max_value, left_root);
//    max_value = max(max_value, right_root);
//    max_value = max(max_value, left_root_right);
//
//    return max(left_root, max(root_value, right_root));
//}
//
//int maxPathSum(TreeNode* root) {
//    int max_value = INT_MIN;
//    maxPath(root, max_value);
//    return max_value;
//}

// 在看了相关的题解后，发现自己实现的太复杂了
// 在自己的实现中考虑了负数，实际上可以完全把负数排除掉，这样程序将会简单很多

int maxPath(TreeNode* root, int &max_value){
    if (root == nullptr) return 0;
    int left = maxPath(root->left, max_value);
    int right = maxPath(root->right, max_value);

    // 这里使用max排除掉负数
    int left_root_right = root->val + max(0, left) + max(0, right);
    int ret = root->val + max(0, max(left, right));
    max_value = max(max_value, max(left_root_right, ret));
    return ret;
}

int maxPathSum(TreeNode* root) {
    int max_value = INT_MIN;
    maxPath(root, max_value);
    return max_value;
}

int main() {
    int value = 0;
    TreeNode* root = nullptr;

    root = new TreeNode(-10);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    value = maxPathSum(root);
    printf("%d\n", value);

    root = new TreeNode(-3);
    value = maxPathSum(root);
    printf("%d\n", value);

    root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    value = maxPathSum(root);
    printf("%d\n", value);

    root = new TreeNode(1);
    root->left = new TreeNode(-2);
    root->left->left = new TreeNode(1);
    root->left->left->left = new TreeNode(-1);
    root->left->right = new TreeNode(3);

    root->right = new TreeNode(-3);
    root->right->left = new TreeNode(-2);
    value = maxPathSum(root);
    printf("%d\n", value);

    getchar();
    return 0;
}
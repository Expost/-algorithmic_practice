#include <stdio.h>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// 初步想法是中序遍历
// 以下实现稍微复杂一些
//bool dfs(TreeNode* root, int &cur, int k, int &val) {
//    if (!root) return false;
//    
//    if (dfs(root->left, cur, k, val))return true;
//    if (++cur == k) {
//        val = root->val;
//        return true;
//    }
//
//    if (dfs(root->right, cur, k, val))return true;
//
//    return false;
//}

// 优化一个参数的使用
bool dfs(TreeNode* root, int &k, int &val) {
    if (!root) return false;

    if (dfs(root->left, k, val))return true;
    if (--k == 0) {
        val = root->val;
        return true;
    }

    if (dfs(root->right, k, val))return true;

    return false;
}


int kthSmallest(TreeNode* root, int k) {
    int val = 0;
    dfs(root, k, val);
    return val;
}

int main() {
    TreeNode* root = nullptr;
    int ret = 0;

    root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->left->right = new TreeNode(2);
    root->right = new TreeNode(4);
    ret = kthSmallest(root, 2);
    printf("%d\n", ret);

    root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->left->left = new TreeNode(2);
    root->left->left->left = new TreeNode(1);
    root->left->right = new TreeNode(4);
    root->right = new TreeNode(6);
    ret = kthSmallest(root, 5);
    printf("%d\n", ret);

    getchar();
    return 0;
}
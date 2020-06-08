#include <stdio.h>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// 这道题也是简单，对树使用深度优先遍历即可
void dfs(TreeNode* root, int cur, int &depth) {
    if (!root)return;
    if (root->left)
        dfs(root->left, cur + 1, depth);
    
    if (cur > depth) depth = cur;
    
    if (root->right)
        dfs(root->right, cur + 1, depth);
}

int maxDepth(TreeNode* root) {
    int depth = 0;
    dfs(root, 1, depth);
    return depth;
}

int main() {
    TreeNode* root = nullptr;
    int ret = 0;

    root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    //root->right->left = new TreeNode(7);
    //root->right->right = new TreeNode(15);
    
    ret = maxDepth(root);
    printf("%d\n", ret);


    getchar();
    return 0;
}
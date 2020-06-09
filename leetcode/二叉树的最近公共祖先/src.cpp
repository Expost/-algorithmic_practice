#include <stdio.h>
#include <list>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool dfs(TreeNode* root, TreeNode* p, TreeNode* q, list<pair<TreeNode*, bool>> &s, TreeNode*& f) {
    if (!root)return false;

    s.push_back({ root, false });
    if (root->val == p->val || root->val == q->val) {
        if (s.front().second) {
            for (auto itr = s.rbegin(); itr != s.rend(); itr++) {
                if (itr->second) {
                    f = itr->first;
                    return true;
                }
            }
        }
        else {
            for (auto &itr : s) {
                itr.second = true;
            }
        }
    }

    if (dfs(root->left, p, q, s, f))return true;
    if (dfs(root->right, p, q, s, f)) return true;

    s.pop_back();

    return false;
}


TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (!root || !p || !q)return nullptr;
    TreeNode* f = nullptr;
    list<pair<TreeNode*, bool>> s;
    dfs(root, p, q, s, f);
    return f;
}

int main() {
    TreeNode* root = nullptr;
    TreeNode* ret = nullptr;

    root = new TreeNode(6);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(4);
    root->left->right->left = new TreeNode(3);
    root->left->right->right = new TreeNode(5);
    root->right = new TreeNode(8);
    root->right->left = new TreeNode(7);
    root->right->right = new TreeNode(9);

    ret = lowestCommonAncestor(root, root->left, root->left->right);
    printf("%d\n", ret->val);


    getchar();
    return 0;
}
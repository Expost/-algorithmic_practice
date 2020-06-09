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

// �������
// �������������������ԣ����p��q����ֵ��һ���ȵ�ǰ�ڵ�ֵ��һ���ȵ�ǰ�ڵ�С����ô��ǰ�ڵ���������������
// ���p��q���ȵ�ǰ�ڵ�С����ô�Ե�ǰ�ڵ�����������еݹ鴦��
// ���p��q���ȵ�ǰ�ڵ����ô�Ե�ǰ�ڵ�����������еݹ鴦��
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (!root || !p || !q)return nullptr;

    if ((p->val <= root->val && q->val >= root->val) ||
        (p->val >= root->val && q->val <= root->val)) {
        return root;
    }

    TreeNode* tmp = nullptr;
    if (p->val <= root->val && q->val <= root->val) {
        tmp = lowestCommonAncestor(root->left, p, q);
        if (tmp) return tmp;
    }
    if (p->val >= root->val && q->val >= root->val) {
        tmp = lowestCommonAncestor(root->right, p, q);
        return tmp;
    }

    return nullptr;
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

    ret = lowestCommonAncestor(root, root->left, root->right);
    printf("%d\n", ret->val);


    getchar();
    return 0;
}
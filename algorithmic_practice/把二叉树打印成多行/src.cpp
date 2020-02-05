#include <stdio.h>
#include <vector>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
        val(x), left(NULL), right(NULL) {
    }
};

// 这个比按之字形那个还要简单些
vector<vector<int> > Print(TreeNode* pRoot)
{
    vector<TreeNode*> s;
    vector<vector<int>> vv;

    if (!pRoot)
        return vv;

    s.push_back(pRoot);
    while (!s.empty())
    {
        vector<TreeNode*> tmp_s;
        vector<int> v;
        tmp_s.swap(s);

        for (auto &node : tmp_s)
        {
            if(node == nullptr)
                continue;

            v.push_back(node->val);
            s.push_back(node->left);
            s.push_back(node->right);
        }

        if (!v.empty())
            vv.push_back(v);
    }

    return vv;
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

    TreeNode *root = new TreeNode(1);
    root->left = new struct TreeNode(2);
    root->left->left = new struct TreeNode(4);
    root->left->left->right = new struct TreeNode(7);
    root->right = new struct TreeNode(3);
    root->right->left = new struct TreeNode(5);
    root->right->right = new struct TreeNode(6);
    root->right->right->left = new struct TreeNode(8);
    auto ret = Print(root);
    for (auto &v : ret)
    {
        for (auto& value : v)
        {
            printf("%d ", value);
        }

        printf("\n");
    }

    getchar();
    return 0;
}
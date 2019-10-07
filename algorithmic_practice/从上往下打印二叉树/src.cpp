#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
        val(x), left(NULL), right(NULL) {
    }
};

// 借助了一个队列以进行广度优先遍历
// 看了下讨论的代码，发现自己用了两层循序，似乎是没有必要的
// 借助队列，使用一层循环即可，智障了
vector<int> PrintFromTopToBottom(TreeNode* root) 
{
    vector<int> v;
    if (root == nullptr)
    {
        return v;
    }
    
    vector<TreeNode*> tv = { root };
    while (!tv.empty())
    {
        vector<TreeNode*> tmp_v;
        tmp_v.swap(tv);
        for (auto &ptr : tmp_v)
        {
            v.push_back(ptr->val);
            if(ptr->left)
                tv.push_back(ptr->left);
            if(ptr->right)
                tv.push_back(ptr->right);
        }
    }

    return v;
}

// 修改后使用一层循环的代码
vector<int> PrintFromTopToBottom_1(TreeNode* root)
{
    vector<int> v;
    if (root == nullptr)
    {
        return v;
    }

    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty())
    {
        auto ptr = q.front();
        q.pop();
        v.push_back(ptr->val);
        if (ptr->left)
            q.push(ptr->left);
        if (ptr->right)
            q.push(ptr->right);
    }

    return v;
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

    vector<int> v = PrintFromTopToBottom(root);
    for (auto &itr : v)
    {
        printf("%d\n", itr);
    }

    getchar();
    return 0;
}
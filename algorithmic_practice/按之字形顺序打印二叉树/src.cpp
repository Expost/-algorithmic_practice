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

vector<vector<int> > Print(TreeNode* pRoot) 
{
    stack<TreeNode*> s;
    vector<vector<int>> vv;
    bool flag = true;

    if (!pRoot)
        return vv;

    s.push(pRoot);
    while (!s.empty())
    {
        stack<TreeNode*> tmp_s;
        vector<int> v;
        tmp_s.swap(s);

        while (!tmp_s.empty())
        {
            auto node = tmp_s.top();
            tmp_s.pop();
            if(node == nullptr)
                continue;

            v.push_back(node->val);
            if (!flag)
            {
                s.push(node->right);
                s.push(node->left);
            }
            else
            {
                s.push(node->left);
                s.push(node->right);
            }
        }
        
        flag = !flag;
        if(!v.empty())
            vv.push_back(v);
    }
    
    return vv;
}

int main()
{
    // ¶þ²æÊ÷ÐÎÌ¬1
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
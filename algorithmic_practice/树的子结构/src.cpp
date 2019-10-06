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

// 两个树分别通过先序遍历一遍并存到vector中，之后判断另一个vector是否是另外一个vector的子vector
// 感觉转成vector比较容易进行比较判断，直接两个树进行判断的话就比较麻烦😒
void get_tree_values(TreeNode* root, vector<int> &values)
{
    if (root == nullptr)
    {
        return;
    }

    values.push_back(root->val);
    get_tree_values(root->left, values);
    get_tree_values(root->right, values);
}

bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
{
    vector<int> root;
    vector<int> child;
    get_tree_values(pRoot1, root);
    get_tree_values(pRoot2, child);

    int root_count = root.size();
    int child_count = child.size();
    if (child_count > root_count || child_count == 0)
    {
        return false;
    }

    for (int i = 0; i <= root_count - child_count; i++)
    {
        bool ret = true;
        for (int j = 0; j < child_count; j++)
        {
            if (child[j] != root[i + j])
            {
                ret = false;
                break;
            }
        }

        if (ret == true)
        {
            return true;
        }
    }

    return false;
}


// 别人的递归判断方法
bool isSubTree(TreeNode* pRoot1, TreeNode* pRoot2)
{
    // 1完了但2没完，所以为假
    if (pRoot1 == nullptr && pRoot2 != nullptr)
    {
        return false;
    }

    // 2完了说明2完全匹配了，否则早就返回了
    // 至于空树并非所有树的子集这点在hasSubTree中已经被判断了
    if (pRoot2 == nullptr)
    {
        return true;
    }
    
    if (pRoot1->val == pRoot2->val)
    {
        return isSubTree(pRoot1->left, pRoot2->left) && 
               isSubTree(pRoot1->right, pRoot2->right);
    }

    return false;
}

bool hasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
{
    if (pRoot1 == nullptr || pRoot2 == nullptr)
    {
        return false;
    }
    
    return isSubTree(pRoot1, pRoot2) ||
        hasSubtree(pRoot1->left, pRoot2) ||
        hasSubtree(pRoot1->right, pRoot2);
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

    TreeNode* child1 = new TreeNode(2);
    child1->left = new struct TreeNode(4);
    child1->left->right = new struct TreeNode(7);

    TreeNode* child2 = new TreeNode(3);
    child2->left = new struct TreeNode(5);
    child2->right = new struct TreeNode(6);
    child2->right->left = new struct TreeNode(8);

    TreeNode* child3 = new TreeNode(3);
    child3->left = new struct TreeNode(5);
    child3->right = new struct TreeNode(6);
    child3->right->left = new struct TreeNode(7);

    bool ret = false;
    ret = hasSubtree(root, child1);
    printf("%d\n", ret);
    ret = hasSubtree(root, child2);
    printf("%d\n", ret);
    ret = hasSubtree(root, child3);
    printf("%d\n", ret);
    ret = hasSubtree(root, nullptr);
    printf("%d\n", ret);

    getchar();
    return 0;
}
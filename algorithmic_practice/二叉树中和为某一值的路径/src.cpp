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

// �����������ͺܼ򵥣����������Ҫ��������򣬵�ǰ��ʵ�־ͺ��鷳
void find(TreeNode* root, vector<int> v, vector<vector<int>> &vv, int cv, int expect)
{
    if (root == nullptr)
    {
        return ;
    }

    v.push_back(root->val);
    cv += root->val;

    find(root->right, v, vv, cv, expect);
    find(root->left, v, vv, cv, expect);

    if (root->left == nullptr && root->right == nullptr && cv == expect)
    {
        bool inserted = false;
        for (auto itr = vv.begin(); itr != vv.end(); itr++)
        {
            if (v.size() > itr->size())
            {
                vv.insert(itr, std::move(v));
                inserted = true;
                break;
            }
        }

        if (!inserted)
        {
            vv.push_back(std::move(v));
        }
    }
}

vector<vector<int>> FindPath(TreeNode* root, int expectNumber) 
{
    vector<int> v;
    vector<vector<int>> vv;
    find(root, v, vv, 0, expectNumber);
    return vv;
}

// �ο����˵����ۣ�ʵ�����£�����ʹ��javaʵ�֣������ΪCPP��
// ��ʵ�ʾ�main�����������������䲢û�п����������⣬�����ָպ�ͨ����ţ�͵Ĳ���
// ����ţ�͵�������main�н�����nroot����ͬʱȡ���Լ������е����򣬻ᷢ���Լ�����Ľ���Ƕ���ǰ
// ������Ĵ���պó���ǰ����ȷʵ˵��ţ�͵��������ǲ�ȫ
vector<vector<int>> vv;
vector<int> v;
vector<vector<int>> FindPath_1(TreeNode* root, int expectNumber)
{
    if (root == nullptr)
    {
        return vv;
    }

    v.push_back(root->val);
    expectNumber -= root->val;
    if (expectNumber == 0 && root->left == nullptr && root->right == nullptr)
    {
        vv.emplace_back(v);
    }

    FindPath_1(root->left, expectNumber);
    FindPath_1(root->right, expectNumber);
    
    if(!v.empty())
        v.erase(v.end() - 1);

    return vv;
}

int main()
{
// ��������̬
//            1
//        /       \
//    2               3
//  /   \           /    \
//4      15        5       6
//  \             /      /
//   7          1       8
//              /
//             8

    TreeNode *root = new TreeNode(1);
    root->left = new struct TreeNode(2);
    root->left->right = new struct TreeNode(15);
    //root->left->right->right = new struct TreeNode(1);
    root->left->left = new struct TreeNode(4);
    root->left->left->right = new struct TreeNode(7);
    root->right = new struct TreeNode(3);
    root->right->left = new struct TreeNode(5);
    root->right->left->left = new struct TreeNode(1);
    root->right->left->left->left = new struct TreeNode(8);
    root->right->right = new struct TreeNode(6);
    root->right->right->left = new struct TreeNode(8);

    TreeNode* nroot = new TreeNode(10);
    nroot->left = new struct TreeNode(5);
    nroot->right = new struct TreeNode(12);
    nroot->left->left = new struct TreeNode(4);
    nroot->left->right = new struct TreeNode(7);

    auto vv = FindPath(root, 18);
    for (auto &itr : vv)
    {
        for (auto &i : itr)
        {
            printf("%d ", i);
        }

        printf("\n");
    }

    printf("\n");
    vv = FindPath_1(root, 18);
    for (auto &itr : vv)
    {
        for (auto &i : itr)
        {
            printf("%d ", i);
        }

        printf("\n");
    }

    getchar();
    return 0;
}
#include <stdio.h>
#include <vector>
#include <string>
#include <sstream>
using namespace std;
#pragma warning(disable:4996)

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
        val(x), left(NULL), right(NULL) {
    }
};

char* Serialize(TreeNode *root) 
{
    std::string s;
    if (root == nullptr)
    {
        s += "|";
    }
    else
    {
        vector<pair<int, TreeNode*>> v;
        v.push_back(pair<int, TreeNode*>(0, root));
        while (!v.empty())
        {
            vector<pair<int, TreeNode*>> tmp_v;
            stringstream ss;
            tmp_v.swap(v);

            for (int i = 0; i < tmp_v.size(); i++)
            {
                auto num = tmp_v[i].first;
                auto tree = tmp_v[i].second;

                ss << num;
                ss << "-";
                ss << tree->val;
                if(i != tmp_v.size() - 1)
                    ss << ",";
                
                if(tree->left)
                    v.push_back(pair<int, TreeNode*>(num * 2, tree->left));
                if(tree->right)
                    v.push_back(pair<int, TreeNode*>(num * 2 + 1, tree->right));
            }

            s += ss.str();
            s += "|";
        }
    }

    char *buf = new char[s.size() + 1];
    memset(buf, 0, s.size() + 1);
    strncpy(buf, s.c_str(), s.size());
    return buf;
}

int get_num(char *&str)
{
    stringstream ss(str);
    int value = 0;
    ss >> value;
    while (*str >= '0' && *str <= '9') str++;
    return value;
}

bool eat(char *&str, char flag)
{
    bool ret = false;
    if (*str == flag)
    {
        ret = true;
        str++;
    }
    
    return ret;
}

TreeNode* Deserialize(char *str)
{
    if (*str == '|')
        return nullptr;

    TreeNode* root = nullptr;
    vector<pair<int, TreeNode*>> v;
    while (*str != 0)
    {
        vector<pair<int, TreeNode*>> vv;
        vv.swap(v);
        while (*str != '|')
        {
            int num = get_num(str);
            eat(str, '-');
            int value = get_num(str);
         
            auto node = new TreeNode(value);
            v.push_back(pair<int, TreeNode*>(num, node));


            if (root == nullptr)
            {
                root = node;    
            }
            else
            {
                for (auto &n : vv)
                {
                    if (n.first * 2 == num)
                    {
                        n.second->left = node;
                    }
                    else if (n.first * 2 + 1 == num)
                    {
                        n.second->right = node;
                    }
                }
            }

            if (*str == ',')
                str++;
        }

        str++;
    }

    return root;
}

// 辅助打印函数
void helper_print(TreeNode *root)
{
    if (root == nullptr)
        return;

    printf("%d ", root->val);
    helper_print(root->left);
    helper_print(root->right);
}

// 以上实现很复杂，生成的字符串格式为： 0-1|0-2,1-3|0-4,2-5,3-6|1-7,6-8|
// 采用了层序遍历，每一层由'|'分割，每个结点由','分割，每个结点由两部分组成，由'-'分割
// 前半部分为结点在这一层中从左起始的序号，第二部分为结点的值
// 参考讨论，果然还是自己太low，实现如下：
// 直接前序遍历，对于null指针使用特殊值存储即可（比如说明中的#）

void dfs(TreeNode* root, vector<int> &buf)
{
    if (!root)
        buf.push_back(0x23333);
    else
    {
        buf.push_back(root->val);
        dfs(root->left, buf);
        dfs(root->right, buf);
    }
}

TreeNode* dfs2(int*& buf)
{
    if (*buf == 0x23333)
    {
        buf++;
        return nullptr;
    }

    auto res = new TreeNode(*buf);
    buf++;
    res->left = dfs2(buf);
    res->right = dfs2(buf);
    return res;
}

char* Serialize_1(TreeNode *root) {
    vector<int> v;
    dfs(root, v);
    int *res = new int[v.size()];
    for (int i = 0; i < v.size(); i++)
        res[i] = v[i];
    return (char*)res;
}

TreeNode* Deserialize_1(char *str)
{
    int *p = (int*)str;
    return dfs2(p);
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

    TreeNode* root1 = nullptr;
    auto str = Serialize(root);
    printf("%s\n", str);
    auto new_root = Deserialize(str);
    helper_print(new_root);

    getchar();
    return 0;
}
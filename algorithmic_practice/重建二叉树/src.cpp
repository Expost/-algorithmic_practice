#include <iostream>
#include <vector>

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int g_pre_index = 0;
int get_pos(const vector<int> &vin, int value)
{
    for (int i = 0; i < vin.size(); i++)
    {
        if (vin[i] == value)
        {
            return i;
        }
    }

    return -1;
}

// 这里用了太多临时变量，将vector改为数组指针，并传递index会节省较多拷贝时间和空间。
// 看了下相关的讨论，大体实现差不多。
// 需要举一反三思考一下只给后序、中序遍历的结果该如何重建二叉树。
TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin) 
{
    if (vin.size() == 0)
    {
        return nullptr;
    }

    int val0 = pre[g_pre_index++];
    TreeNode *head = new TreeNode(val0);
    int pos0 = get_pos(vin, val0);
    
    vector<int> tmp_vin0(vin.begin(), vin.begin() + pos0);
    head->left = reConstructBinaryTree(pre, tmp_vin0);

    vector<int> tmp_vin1(vin.begin() + pos0 + 1, vin.end());
    head->right = reConstructBinaryTree(pre, tmp_vin1);

    return head;
}

// 后续遍历+中序遍历的重建，逻辑与前序遍历差不多，注意顺序是先右再左，与正常的遍历顺序相一致
TreeNode* ReConstructBinaryTree(vector<int> end, vector<int> vin)
{
    static int g_end_index = end.size() - 1;
    if (vin.size() == 0)
    {
        return nullptr;
    }

    int val0 = end[g_end_index--];
    TreeNode *head = new TreeNode(val0);
    int pos0 = get_pos(vin, val0);
    
    vector<int> tmp_vin1(vin.begin() + pos0 + 1, vin.end());
    head->right = ReConstructBinaryTree(end, tmp_vin1);

    vector<int> tmp_vin0(vin.begin(), vin.begin() + pos0);
    head->left = ReConstructBinaryTree(end, tmp_vin0);

    return head;
}

// 前序遍历：根左右
// 中序遍历：左根右
// 后续遍历：左右根

int main()
{
        // 二叉树形态
        //            1
        //        /       \
        //    2               3
        //  /              /    \
        //4               5       6
        //   \                   /
        //    7               8

    vector<int> pre = { 1,2,4,7,3,5,6,8 };
    vector<int> vin = { 4,7,2,1,5,3,8,6 };
    vector<int> end = { 7,4,2,5,8,6,3,1 };

    //TreeNode* tree = reConstructBinaryTree(pre, vin);
    TreeNode* tree = ReConstructBinaryTree(end, vin);
    printf("%d\n", tree->val);
    
    return 0;
}
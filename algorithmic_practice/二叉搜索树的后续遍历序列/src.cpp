#include <stdio.h>
#include <vector>

using namespace std;

// 该题需要搞明白二叉搜索树的定义及特点
// 用了vector的insert方法，复杂度太高
bool VerifySquenceOfBST(vector<int> sequence) 
{
    if (sequence.empty())
    {
        return false;
    }

    int count = sequence.size();
    int root_val = sequence[count - 1];
    int i = count - 2;
    vector<int> right, left;
    for (; i >= 0 && sequence[i] > root_val; i--)
    {
        right.insert(right.begin(), sequence[i]);
    }
    
    for (; i >= 0 && sequence[i] < root_val; i--)
    {
        left.insert(left.begin(), sequence[i]);
    }

    bool ret1 = (right.size() + left.size() == count - 1);
    bool ret2 = right.empty() ? true : VerifySquenceOfBST(right);
    bool ret3 = left.empty() ? true : VerifySquenceOfBST(left);

    return ret1 && ret2 && ret3;
}


// 借助别的函数实现递归，不再只依赖默认函数接口
bool judge(const vector<int> &sequence, int l, int r)
{
    int count = r - l + 1;
    if (count == 0)
    {
        return true;
    }

    int root_val = sequence[r];
    int i = r - 1;
    int cal_count = 0;
    for (; i >= l && sequence[i] > root_val; i--)
        cal_count++;
    for (int j = i; j >= l && sequence[j] < root_val; j--)
        cal_count++;

    if (cal_count != count - 1)
        return false;

    return judge(sequence, l, i) && judge(sequence, i + 1, r - 1);
}

bool VerifySquenceOfBST_1(vector<int> sequence)
{
    if (sequence.empty())
    {
        return false;
    }

    return judge(sequence, 0, sequence.size() - 1);
}


int main()
{
// 二叉树形态
//           5 
//        /       \
//    4               7
//  /              /    \
//2              6       9
//  \                   /
//   3                 8
// 其后续遍历序列为：3, 2, 4, 6, 8, 9, 7, 5
// 最后一个值为根，剩下的值可以分为两段，一段均大于根，其为右子树，另一段均小于根，其为左子树
// 且这两个子树均符合上面的特征，符合递归的特征。

    vector<int> v = { 3, 2, 4, 6, 8, 9, 7, 5 };
    printf("%d\n", VerifySquenceOfBST_1(v));

    getchar();
    return 0;
}
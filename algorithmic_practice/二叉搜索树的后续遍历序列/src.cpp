#include <stdio.h>
#include <vector>

using namespace std;

// ������Ҫ�����׶����������Ķ��弰�ص�
// ����vector��insert���������Ӷ�̫��
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


// ������ĺ���ʵ�ֵݹ飬����ֻ����Ĭ�Ϻ����ӿ�
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
// ��������̬
//           5 
//        /       \
//    4               7
//  /              /    \
//2              6       9
//  \                   /
//   3                 8
// �������������Ϊ��3, 2, 4, 6, 8, 9, 7, 5
// ���һ��ֵΪ����ʣ�µ�ֵ���Է�Ϊ���Σ�һ�ξ����ڸ�����Ϊ����������һ�ξ�С�ڸ�����Ϊ������
// ��������������������������������ϵݹ��������

    vector<int> v = { 3, 2, 4, 6, 8, 9, 7, 5 };
    printf("%d\n", VerifySquenceOfBST_1(v));

    getchar();
    return 0;
}
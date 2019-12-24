#include <stdio.h>
#include <vector>
using namespace std;

int cal(const vector<int>& A, int pos)
{
    int v = 1;
    for (int i = 0; i < A.size(); i++)
    {
        if (i != pos)
            v *= A[i];
    }

    return v;
}
vector<int> multiply(const vector<int>& A) 
{
    vector<int> v;
    v.resize(A.size());
    for (int i = 0; i < A.size(); i++)
    {
        v[i] = cal(A, i);
    }

    return v;
}

// 实在是没有想到好的方法，只能用复杂度最高的方式了
// 参考讨论发现这个上下三角的方法不错
vector<int> multiply_1(const vector<int>& A)
{
    auto len = A.size();
    vector<int> v(len);
    if (len != 0)
    {
        v[0] = 1;
        for (int i = 1; i < len; i++)
        {
            v[i] = v[i - 1] * A[i - 1];
        }
        int tmp = 1;
        for (int j = len - 2; j >= 0; j--)
        {
            tmp *= A[j + 1];
            v[j] *= tmp;
        }
    }

    return v;
}

int main()
{
    vector<int> v = { 1,2,3,4,5 };
    auto vv = multiply_1(v);
    for (auto &i : vv)
    {
        printf("%d ", i);
    }

    getchar();
    return 0;
}
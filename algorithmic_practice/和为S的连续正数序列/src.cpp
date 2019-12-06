#include <vector>
#include <stdio.h>
using namespace std;

vector<vector<int> > FindContinuousSequence(int sum) {
    int count = sum / 2 + 1;
    vector<vector<int>> vv;
    for (int i = 1; i <= count; i++)
    {
        int tmp_sum = 0;
        vector<int> v;
        for (int j = i;; j++)
        {
            tmp_sum += j;
            v.push_back(j);
            if (tmp_sum == sum && v.size() != 1)
            {
                vv.push_back(std::move(v));
            }
            if (tmp_sum > sum)
                break;
        }
    }

    return vv;
}

// ���ϴ��뱩����٣���Ȼ�ǳ�����
// �����������Ƚ�ţ�ƣ�ע�������nΪ���еĳ���
vector<vector<int> > FindContinuousSequence_1(int sum) {
    vector<vector<int>> vv;
    for (int n = sqrt(2 * sum); n >= 2; n--)
    {
        if (((n & 1) == 1) && (sum %n == 0) || ((sum % n) * 2 == n))
        {
            vector<int> v;
            // �����kΪ���еĵ�һ�����֣�k + n - 1��Ϊ���һ�����֣�֮��ʹ�õȲ����й�ʽ����
            for (int j = 0, k = (sum / n) - (n - 1) / 2; j < n; j++, k++)
            {
                v.push_back(k);
            }

            vv.push_back(std::move(v));
        }
    }

    return vv;
}

int main()
{
    auto vv = FindContinuousSequence_1(100000000000000);
    
    for (auto &v : vv)
    {
        for (auto &i : v)
        {
            printf("%d ", i);
        }

        printf("\n");
    }

    getchar();
    return 0;
}
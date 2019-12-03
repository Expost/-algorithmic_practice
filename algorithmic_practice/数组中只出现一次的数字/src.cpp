#include <stdio.h>
#include <vector>
#include <map>
#include <unordered_map>
using namespace std;

void FindNumsAppearOnce(vector<int> data, int* num1, int *num2) {
    unordered_map<int, uint8_t> m;
    for (auto &itr : data)
    {
        if (m[itr] == 0)
        {
            m[itr] += 1;
        }
        else
        {
            m[itr] -= 1;
        }
    }

    vector<int> v;
    for (auto &itr : m)
    {
        if (itr.second == 1)
            v.push_back(itr.first);
    }

    *num1 = v[0];
    *num2 = v[1];
}

// �������ַ����Ƚ�low���Ƚϼ򵥴ֱ�
// �ο������ۣ��������ǲ������ķ�ʽ����Ȼ�ǳ���ʶ��
void FindNumsAppearOnce_1(vector<int> data, int* num1, int *num2) {
    int v = 0;
    for (auto &itr : data)
    {
        v ^= itr;
    }

    int pos = 0;
    for (uint32_t i = 0; i < 32; i++)
    {
        if (((v >> i) & 1) == 1)
        {
            pos = i;
        }
    }

    vector<int> data1;
    vector<int> data2;
    for (auto &itr : data)
    {
        if (((itr >> pos) & 1) == 1)
            data1.push_back(itr);
        else
            data2.push_back(itr);
    }

    *num1 = 0;
    for (auto &itr : data1)
        *num1 ^= itr;

    *num2 = 0;
    for (auto &itr : data2)
        *num2 ^= itr;
}


int main()
{
    vector<int> v = { 1,1,2,3,3,4,4,5,5,6,6,7,8,8,9,9 };
    int v1, v2;
    FindNumsAppearOnce_1(v, &v1, &v2);
    printf("%d %d\n", v1, v2);

    getchar();
    return 0;
}
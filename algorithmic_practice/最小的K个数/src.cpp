#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

// ֱ��ʹ�ÿ⺯�������������
// ���о���Ӧ���ǿ�������ģ��Լ����д�˸����Ʋ�������Ĵ���
vector<int> GetLeastNumbers_Solution(vector<int> input, int k) 
{
    vector<int> v;
    if (input.empty() || k > input.size())
    {
        return v;
    }

    for (auto &i : input)
    {
        bool inserted = false;
        for (auto itr = v.begin(); itr != v.end(); itr++)
        {
            if (i < *itr)
            {
                v.insert(itr, i);
                inserted = true;
                break;
            }
        }

        if (!inserted)
        {
            v.push_back(i);
        }
    }

    vector<int> tmp(v.begin(), v.begin() + k);
    return tmp;
}

// ���������ۣ�����ǿ�����������㷨��
// �п��ţ����ŵȣ��ô˻��Ḵϰ�������㷨

int main()
{
    vector<int> v = { 4,5,1,6,2,7,3,8 };
    auto vv = GetLeastNumbers_Solution(v, 8);

    for (auto &i : vv)
    {
        printf("%d ", i);
    }

    getchar();
    return 0;
}
#include <stdio.h>
#include <list>
#include <vector>
using namespace std;

int LastRemaining_Solution(int n, int m)
{
    if (n < 1)
        return -1;

    list<int> l;
    for (int i = 0; i < n; i++)
    {
        l.push_back(i);
    }

    int count = 0;
    auto itr = l.begin();
    while (l.size() > 1)
    {
        if (itr == l.end())
            itr = l.begin();

        if (count == m - 1)
        {
            auto next = ++itr;
            l.erase(--itr);
            itr = next;
            count = 0;
        }
        else
        {
            itr++;
            count++;
        }
    }

    return l.front();
}

// ������Լ��õ�������Ϊ�о���ָ����Ԫ��ɾ���󣬺����ٱ���ʱԪ�ػ�Խ��Խ�٣�Ч�ʻ����
// ��������飬Ҳɾ������ô���Ӷȸߣ�����ñ�ǣ���ô����ʼֵ�Ƚϴ󣬺���ֻʣһ������ʱ��
// �����Ĵ���̫��
// �����ۻ���һ������ķ�������javaд�ģ��о�ͦ�ã������ƺ�����C++֮������Լ�������
// C++�ĵ��������±껹��һ��������vector���ǿ���ʵ��

int LastRemaining_Solution_1(int n, int m)
{
    vector<int> l;
    for (int i = 0; i < n; i++)
    {
        l.push_back(i);
    }

    int bt = 0;
    while (l.size() > 1)
    {
        bt = (bt + m - 1) % l.size();
        l.erase(l.begin() + bt);
    }

    return l.size() == 1 ? l.front() : -1;
}

// �����ᵽ��Լɪ�����⻹��Ҫ�ٿ�һ��

int main()
{
    int i = LastRemaining_Solution_1(5, 3);
    printf("%d\n", i);

    getchar();
    return 0;
}
#include <stdio.h>
#include <list>
using namespace std;

list<int> l;

void Insert(int num)
{
    if (l.empty())
        l.push_back(num);
    else
    {
        auto itr = l.begin();
        bool flag = false;
        for (; itr != l.end(); itr++)
        {
            if (num > *itr)
                continue;
            else
            {
                l.insert(itr, num);
                flag = true;
                break;
            }
        }

        if (!flag)
            l.push_back(num);
    }
}

double GetMedian()
{
    int count = l.size();
    auto itr = l.begin();
    if (count % 2 == 0)
    {
        auto index = count / 2 - 1;
        for (int i = 0; i < index; i++) itr++;
        double v1 = *itr++;
        double v2 = *itr;
        return (v1 + v2) / 2;
    }
    else
    {
        auto index = (count - 1) / 2;
        for (int i = 0; i < index; i++) itr++;
        return *itr;
    }
}

// 参考讨论是需要使用大小堆，这块内容还需要复习，暂存

int main()
{
    double v = 0;
    Insert(0);
    Insert(1);
    v = GetMedian(); printf("%f\n", v);

    Insert(100);
    v = GetMedian(); printf("%f\n", v);

    Insert(200);
    v = GetMedian(); printf("%f\n", v);

    Insert(5);
    v = GetMedian(); printf("%f\n", v);

    getchar();
    return 0;
}
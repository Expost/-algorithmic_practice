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

// 这道题自己用的链表，因为感觉将指定的元素删除后，后面再遍历时元素会越来越少，效率会更好
// 如果用数组，也删除，那么复杂度高，如果用标记，那么当起始值比较大，后面只剩一两个人时，
// 遍历的次数太多
// 看讨论还有一个链表的方法，用java写的，感觉挺好，不过似乎换成C++之后就像自己那样了
// C++的迭代器与下标还不一样，换成vector倒是可以实现

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

// 至于提到的约瑟夫环问题还需要再看一下

int main()
{
    int i = LastRemaining_Solution_1(5, 3);
    printf("%d\n", i);

    getchar();
    return 0;
}
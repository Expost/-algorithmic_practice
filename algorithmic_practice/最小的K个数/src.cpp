#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

// 直接使用库函数排序输出即可
// 但感觉不应该是考察这个的，自己随便写了个类似插入排序的代码
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

// 看了下讨论，真的是考察各类排序算法的
// 有快排，堆排等，趁此机会复习下排序算法

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
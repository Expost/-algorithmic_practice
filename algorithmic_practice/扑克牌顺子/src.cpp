#include <stdio.h>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

bool IsContinuous(vector<int> numbers) 
{
    if (numbers.size() != 5)
    {
        return false;
    }

    sort(numbers.begin(), numbers.end());
    auto last_pos = numbers.size() - 1;
    auto last_value = numbers[last_pos];
    int zero_count = 0;
    int sec_count = 0;
    for (int i = last_pos - 1; i >= 0; i--)
    {
        if (numbers[i] == 0)
        {
            zero_count++;
            continue;
        }

        auto diff = last_value - numbers[i];
        if (diff >= 2 && diff <= 4)
        {
            sec_count += diff - 1;
        }
        else if (diff == 1)
        {
        }
        else
        {
            return false;
        }

        last_value = numbers[i];
    }

    return zero_count >= sec_count;
}

// 参考讨论看到是，最大值减最小值要<5，同时除0外没有重复数字。这个在上面程序实现后有过一点想法，但感觉与自己的想不多，后来发现
// 若按照这个方式则不用排序，而自己的方法还要排序，复杂度高了

bool IsContinuous_1(vector<int> numbers)
{
    if (numbers.size() != 5)
    {
        return false;
    }

    map<int, int> m;
    int max = -1;
    int min = 14;
    for (int i = 0; i < numbers.size(); i++)
    {
        if (numbers[i] == 0)
        {
            continue;
        }

        if (m[numbers[i]] == 1)
            return false;

        m[numbers[i]] = 1;
        if (numbers[i] > max)
        {
            max = numbers[i];
        }

        if (numbers[i] < min)
        {
            min = numbers[i];
        }

        if (max - min >= 5) return false;
    }

    return true;
}


int main()
{
    vector<int> v = { 1,0,0,1,0 };
    auto ret = IsContinuous_1(v);
    printf("%d\n", ret);

    getchar();
    return 0;
}
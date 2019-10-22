#include <stdio.h>
#include <vector>
using namespace  std;

// 大致有印象是动态规划，不过实在是忘记了，只能暴力搜索了😢
int FindGreatestSumOfSubArray(vector<int> array) 
{
    if (array.empty())
    {
        return 0;
    }

    int max_value = array[0];
    for (int i = 0; i < array.size(); i++)
    {
        int tmp_max_value = 0;
        for (int j = i; j < array.size(); j++)
        {
            tmp_max_value += array[j];
            
            if (tmp_max_value > max_value)
            {
                max_value = tmp_max_value;
            }
        }
    }

    return max_value;
}

// 动态规划算法
int FindGreatestSumOfSubArray_1(vector<int> array)
{
    if (array.empty())
    {
        return 0;
    }

    int sum = array[0];
    int tmp_sum = sum;
    for (int i = 1; i < array.size(); i++)
    {
        tmp_sum = (tmp_sum + array[i] > array[i]) ? tmp_sum + array[i] : array[i];
        sum = (tmp_sum > sum) ? tmp_sum : sum;
    }

    return sum;
}



int main()
{
    vector<int> v = { 1,-2,3,10,-4,7,2,-5 };
    int max_value = FindGreatestSumOfSubArray(v);
    printf("%d\n", max_value);

    max_value = FindGreatestSumOfSubArray_1(v);
    printf("%d\n", max_value);

    getchar();
    return 0;
}
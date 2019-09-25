#include <stdio.h>


// 一只青蛙一次可以跳上1级台阶，也可以跳上2级……它也可以跳上n级。求该青蛙跳上一个n级的台阶总共有多少种跳法。

// 画个图
// 1阶1种
// 2阶2种
// 3阶4种
// 4阶8种
// 在之前的基础上，很容易的推出
// f(n) = f(n-1) + f(n-2) + f(n-3) + ... + f(0)
// 所以实现如下
int jumpFloorII(int number)
{
    int *cache = new int[number + 1];

    cache[0] = 1;
    cache[1] = 1;
    cache[2] = 2;

    for (int i = 3; i <= number; i++)
    {
        cache[i] = 0;
        for(int j = 0;j < i;j++)
        {
            cache[i] += cache[j];
        }
    }

    return cache[number];
}


int main()
{
    int count = 0;
    count = jumpFloorII(3);
    printf("count is %d\n", count);

    count = jumpFloorII(5);
    printf("count is %d\n", count);

    getchar();
    return 0;
}
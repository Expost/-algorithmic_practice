#include <stdio.h>


//一只青蛙一次可以跳上1级台阶，也可以跳上2级。求该青蛙跳上一个n级的台阶总共有多少种跳法（先后次序不同算不同的结果）。
// 自己画个图算一下的话
// 1阶1种方法
// 2阶2种方法
// 3阶3种方法
// 4阶5种方法
// 5阶8种方法
// 通过规律的来看这算是一个斐波那契数列，因此程序如下
// 对于规律的解释是：假设现在6个台阶，我们可以从第5跳一步到6，
// 这样的话有多少种方案跳到5就有多少种方案跳到6，
// 另外我们也可以从4跳两步跳到6，跳到4有多少种方案的话，就有多少种方案跳到6
// 所以f(6) = f(5) + f(4)
int jumpFloor(int number) 
{
    int *cache = new int[number + 1];
    
    cache[1] = 1;
    cache[2] = 2;

    for (int i = 3; i <= number; i++)
    {
        cache[i] = cache[i - 1] + cache[i - 2];
    }

    return cache[number];
}

int main()
{
    int count = jumpFloor(5);
    printf("count is %d\n", count);

    getchar();

    return 0;
}
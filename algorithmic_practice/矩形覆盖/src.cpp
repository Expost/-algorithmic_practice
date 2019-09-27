#include <stdio.h>

// 我们可以用2*1的小矩形横着或者竖着去覆盖更大的矩形。
// 请问用n个2*1的小矩形无重叠地覆盖一个2*n的大矩形，总共有多少种方法？

// 该问题实际上与青蛙跳台阶是同一个问题
// 参考这个规律：假设现在6个台阶，我们可以从第5跳一步到6，
// 这样的话有多少种方案跳到5就有多少种方案跳到6，
// 另外我们也可以从4跳两步跳到6，跳到4有多少种方案的话，就有多少种方案跳到6
int rectCover(int number) {
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
    int count = rectCover(5);
    printf("count is %d\n", count);
    getchar();
    return 0;
}
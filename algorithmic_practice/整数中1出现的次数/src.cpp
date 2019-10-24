#include <stdio.h>

int NumberOf1Between1AndN_Solution(int n)
{
    int count = 0;
    for (int i = 1000000000; i != 0; i /= 10)
    {
        if (i > n)
        {
            continue;
        }

        int x = n / i;
        if (x > 1)
        {
            count = count + i + x * (i / 10);
        }
        else
        {
            int y = n % i + 1;
            count += y + x * (i / 10);
        }

        n = n % i;
    }

    return count;
}

int main()
{
    //int i = 130 % 100;
    //printf("%d\n", i);
    int v = NumberOf1Between1AndN_Solution(10000);
    printf("%d\n", v);

    getchar();
    return 0;
}
#include <stdio.h>
#include <vector>

using namespace std;


// ���ư汾
int Fibonacci(int n) 
{
    int *cache = new int[n + 1];
    cache[0] = 0;
    cache[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        cache[i] = cache[i - 1] + cache[i - 2];
    }

    return cache[n];
}

// ������ʱ������
int Fibonacci1(int n)
{
    if (n == 0)
    {
        return 0;
    }

    int val0 = 0;
    int val1 = 1;
    int val = 1;
    for (int i = 1; i < n; i++)
    {
        val = val0 + val1;
        val0 = val1;
        val1 = val;
    }

    return val;
}

// β�ݹ�汾
int tmp_fibonacci(int n, int v1, int v2)
{
    if (n == 0) return v1;
    if (n == 1) return v2;

    return tmp_fibonacci(n - 1, v2, v1 + v2);
}

int Fibonacci2(int n)
{
    return tmp_fibonacci(n, 0, 1);
}

int main()
{
    int value = Fibonacci2(2);
    printf("value is %d\n", value);

    getchar();

    return 0;
}

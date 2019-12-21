#include <stdio.h>
#include <string.h>

bool duplicate(int numbers[], int length, int* duplication) 
{
    char *m = new char[length];
    memset(m, 0, length);
    for (int i = 0; i < length; i++)
    {
        int v = numbers[i];
        if (m[v] != 0)
        {
            *duplication = v;
            return true;
        }
        else
        {
            m[v] = 1;
        }
    }

    return false;
}

// 参考了讨论的答案，实际上可以不用额外申请一个数组的
// 实现方式如下
bool duplicate_1(int numbers[], int length, int* duplication)
{
    for (int i = 0; i < length; i++)
    {
        int v = numbers[i] % length;
        if (numbers[v] < length)
        {
            numbers[v] += length;
        }
        else
        {
            *duplication = v;
            return true;
        }
    }

    return false;
}

int main()
{
    int v[] = { 2,3,1,0,2,5,3 };
    int d = 0;
    bool ret = duplicate_1(v, sizeof(v), &d);
    printf("%d %d\n", ret, d);

    getchar();
    return 0;
}
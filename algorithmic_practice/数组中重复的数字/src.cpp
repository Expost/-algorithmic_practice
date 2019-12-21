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

// 

int main()
{
    int v[] = { 2,3,1,0,2,5,3 };
    int d = 0;
    bool ret = duplicate(v, 2, &d);
    printf("%d %d\n", ret, d);

    getchar();
    return 0;
}
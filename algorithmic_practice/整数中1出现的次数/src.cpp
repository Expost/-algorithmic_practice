#include <stdio.h>

//int NumberOf1Between1AndN_Solution(int n)
//{
//    int count = 0;
//    for (int i = 1000000000; i != 0; i /= 10)
//    {
//        if (i > n)
//        {
//            continue;
//        }
//
//        int x = n / i;
//        if (x > 1)
//        {
//            count = count + i + x * (i / 10);
//        }
//        else
//        {
//            int y = n % i + 1;
//            count += y + x * (i / 10);
//        }
//
//        n = n % i;
//    }
//
//    return count;
//}

// 知道有规律，但试了一下没试出来，先暴力找到正确结果，再根据正确结果找规律
int NumberOf1Between1AndN_Solution(int n)
{
    int count = 0;
    for (int value = 1; value <= n; value++)
    {
        int tmp_value = value;
        int tmp_count = 0;
        while (tmp_value != 0)
        {
            int x = tmp_value % 10;
            if (x == 1)
            {
                count++;
                tmp_count++;
            }

            tmp_value /= 10;
        }

        if (tmp_count != 0)
        {
            printf("%d %d %d\n", value, tmp_count, count);
        }
    }

    return count;
}

int main()
{
    //int i = 130 % 100;
    //printf("%d\n", i);
    int v = NumberOf1Between1AndN_Solution(10000);
    printf("\n\n%d\n", v);

    getchar();
    return 0;
}
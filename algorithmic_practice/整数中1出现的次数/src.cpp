#include <stdio.h>

int NumberOf1Between1AndN_Solution_1(int n);
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
            printf("%d %d %d\n", value, count, NumberOf1Between1AndN_Solution_1(value));
        }
    }

    return count;
}

// 根据上面的暴力查找结果开始考虑规律
// 考虑将一个数分为3个部分，
// 比如314这个数，以4为基准，其左部分为31，右部分为0；
// 以十位1为基准，其左部分为3，其右部分为4；
// 以百位3为基准，左部分为0，右部分为14
// 分别以个十百为基准遍历
// 对个位4来说，其左部分为31，那么它有31次机会为1，再加上4大于1，所以额外加上1，即 1 + 31，右部分为0不考虑；
// 对十位1来说，其做部分为3，那么他有3次机会为1，但其在十位上，因此要3 * 10，因为每次它为1时，个位上的数将会走10次，
// 又由于它为1，所以还要看个位，个位是4，即其有5次机会为1（0，1，2，3，4），那么要在加上5，即总的数量为 3 * 10 + 5；
// 对百位3来说，其左部分为0，不考虑，自身为3，且其在百位上，所以有1 * 100次机会为1
// 那么总的数量为： 1 + 31 + 3 * 10 + 5 + 100 = 167

// 归纳规律为：
// 对某一位来说，其1的数量为其左部分值乘以该位的进制，如果该位为1，那么要再加上右部分数的值+1，如果该位大于1，
// 那么再加上该位的进制
// 实现代码如下：
int NumberOf1Between1AndN_Solution_1(int n)
{
    int count = 0;
    for (int i = 1; i <= n; i *= 10)
    {
        // xcy
        int x = n / (i * 10);
        int c = n % (i * 10) / i;
        int y = n % i;

        count += x * i;
        if (c > 1)
        {
            count += i;
        }
        else if (c == 1)
        {
            count += y + 1;
        }
    }

    return count;
}


int main()
{
    int v = NumberOf1Between1AndN_Solution(10001);
    printf("\n\n%d\n", v);

    getchar();
    return 0;
}
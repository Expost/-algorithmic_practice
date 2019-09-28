#include <stdio.h>
#include <math.h>

// 最开始没有考虑到次方为负数的情况
// 另外，这种实现估计依旧不合格，需要使用快速幂（自己完全忘记了这玩意）
// 自己净是写点不合格的算法😂，看来算法基础很薄弱啊
double Power(double base, int exponent) {
    int exp = abs(exponent);
    double value = 1.0;
    
    for (int i = 0; i < exp; i++)
    {
        value *= base;
    }
    
    return exponent > 0 ? value : (1 / value);
}

// 使用快速幂的方法，参考：https://cloud.tencent.com/developer/article/1164715
// 3 ^ 19 = 3 * 3 * 3 * … * 3
// 直接乘要做18次乘法。但事实上可以这样做，先求出3的2^k次幂：
// 3 ^ 2 = 3 * 3
// 3 ^ 4 = (3 ^ 2) * (3 ^ 2)
// 3 ^ 8 = (3 ^ 4) * (3 ^ 4)
// 3 ^ 16 = (3 ^ 8) * (3 ^ 8)
// 再相乘：
// 3 ^ 19 = 3 ^ (16 + 2 + 1) = (3 ^ 16) * (3 ^ 2) * 3
// 
// 这样只要做7次乘法就可以得到结果：
// 3 ^ 2 一次，
// 3 ^ 4 一次，
// 3 ^ 8 一次，
// 3 ^ 16 一次，
// 乘四次后得到了3 ^ 16
// 3 ^ 2 一次，
// (3 ^ 2) * 3 一次，
// 再乘以(3 ^ 16) 一次，
// 所以乘了7次得到结果。
// 
// 如果幂更大的话，节省的乘法次数更多（但有可能放不下）。
// 即使加上一些辅助的存储和运算，也比直接乘高效得多。
// 
// 我们发现，把19转为2进制数：10011，其各位就是要乘的数。
double pow(double base, int exponent)
{
    int exp = abs(exponent);
    double value = 1.0;
    while (exp > 0)
    {
        if (exp & 1)
        {
            value *= base;
        }

        exp >>= 1;
        base *= base;
    }

    return exponent > 0 ? value : (1 / value);
}

int main()
{
    double value = pow(1.1, 0);
    printf("vlaue is %f\n", value);
    value = Power(1.1, 1);
    printf("vlaue is %f\n", value);
    value = Power(1.1, 2);
    printf("vlaue is %f\n", value);
    value = pow(3, 99);
    printf("vlaue is %f\n", value);
    value = pow(2, -3);
    printf("vlaue is %f\n", value);

    getchar();
    return 0;
}
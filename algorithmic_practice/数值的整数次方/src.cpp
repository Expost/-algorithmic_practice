#include <stdio.h>

double Power(double base, int exponent) {
    double value = 1;
    if (exponent >= 0)
    {
        for (int i = 0; i < exponent; i++)
        {
            value *= base;
        }
    }
    else
    {
        for (int i = -1; i >= exponent; i--)
        {
            value /= base;
        }
    }

    return value;
}

int main()
{
    double value = Power(1.1, 0);
    printf("vlaue is %f\n", value);
    value = Power(1.1, 1);
    printf("vlaue is %f\n", value);
    value = Power(1.1, 2);
    printf("vlaue is %f\n", value);
    value = Power(2, -3);
    printf("vlaue is %f\n", value);

    getchar();
    return 0;
}
#include <stdio.h>
#include <string>
using namespace std;

int StrToInt(string str) {
    int64_t value = 0;
    int len = str.size();
    int carry = 1;
    for (int i = len - 1; i >= 0; i--)
    {
        char c = str[i];
        if (c >= '0' && c <= '9')
        {
            value = value + (c - '0') * carry;
        }
        else if (c == '-')
        {
            value = -1 * value;
        }
        else if (c == '+')
        {
        }
        else
        {
            return 0;
        }

        carry *= 10;
    }

    int min = 0x80000000;
    int max = 0x7fffffff;
    if (value > max || value < min)
        return 0;

    return value;
}

// 参考了下评论，自己这个是逆序算的，正序更加符合认知，下面是改为正序后的代码
int StrToInt_1(string str) {
    if (str.empty())
        return 0;

    int64_t value = 0;
    int len = str.size();
    int flag = str[0] == '-' ? -1 : 1;
    int i = (str[0] == '-' || str[0] == '+') ? 1 : 0;
    for (; i < len; i++)
    {
        char c = str[i];
        if (c >= '0' && c <= '9')
        {
            value = value * 10 + (c - '0');
        }
        else
        {
            return 0;
        }
    }

    value = value * flag;
    int min = 0x80000000;
    int max = 0x7fffffff;
    if (value > max || value < min)
        return 0;

    return value;
}


int main()
{
    int value = StrToInt_1("+2147483647");
    printf("%d\n", value);
    getchar();
    return 0;
}
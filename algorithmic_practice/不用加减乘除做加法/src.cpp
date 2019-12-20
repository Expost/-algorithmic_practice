#include <stdio.h>

// �Լ������ŵļ����֪ʶģ���˼ӷ�����
int Add(int num1, int num2)
{
    int sum = 0;
    int carry = 0;
    for (unsigned i = 1; i != 0; i <<= 1)
    {
        if ((num1 & i) == i && (num2 & i) == i && (carry & i) == i)
        {
            sum = sum | i;
            carry = carry | (i << 1);
        }
        else if (((num1 & i) == i && (num2 & i) == i) ||
            ((num1 & i) == i && (carry &i) == i) ||
            ((num2 & i) == i && (carry & i) == i))
        {
            carry = carry | (i << 1);
        }
        else if ((num1 & i) == i || (num2 & i) == i || (carry & i) == i)
        {
            sum = sum | i;
        }    
    }

    return sum;
}

// �������ۣ���Ȼ�Լ��Ǹ����������������֪ʶ������
// �������൱�ڲ���λ�ļӷ����������������һλ�õ���λֵ
// ֮��ѭ����ֱ��û�н�λΪֹ
int Add_1(int num1, int num2)
{
    while (num2 != 0) 
    {
        int temp = num1 ^ num2;
        num2 = (num1&num2) << 1;
        num1 = temp;
    }

    return num1;
}

int main()
{
    auto sum = Add_1(1, -100);
    printf("%d\n", sum);

    getchar();
    return 0;
}
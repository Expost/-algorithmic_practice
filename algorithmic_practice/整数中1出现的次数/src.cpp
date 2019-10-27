#include <stdio.h>

int NumberOf1Between1AndN_Solution_1(int n);
// ֪���й��ɣ�������һ��û�Գ������ȱ����ҵ���ȷ������ٸ�����ȷ����ҹ���
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

// ��������ı������ҽ����ʼ���ǹ���
// ���ǽ�һ������Ϊ3�����֣�
// ����314���������4Ϊ��׼�����󲿷�Ϊ31���Ҳ���Ϊ0��
// ��ʮλ1Ϊ��׼�����󲿷�Ϊ3�����Ҳ���Ϊ4��
// �԰�λ3Ϊ��׼���󲿷�Ϊ0���Ҳ���Ϊ14
// �ֱ��Ը�ʮ��Ϊ��׼����
// �Ը�λ4��˵�����󲿷�Ϊ31����ô����31�λ���Ϊ1���ټ���4����1�����Զ������1���� 1 + 31���Ҳ���Ϊ0�����ǣ�
// ��ʮλ1��˵����������Ϊ3����ô����3�λ���Ϊ1��������ʮλ�ϣ����Ҫ3 * 10����Ϊÿ����Ϊ1ʱ����λ�ϵ���������10�Σ�
// ��������Ϊ1�����Ի�Ҫ����λ����λ��4��������5�λ���Ϊ1��0��1��2��3��4������ôҪ�ڼ���5�����ܵ�����Ϊ 3 * 10 + 5��
// �԰�λ3��˵�����󲿷�Ϊ0�������ǣ�����Ϊ3�������ڰ�λ�ϣ�������1 * 100�λ���Ϊ1
// ��ô�ܵ�����Ϊ�� 1 + 31 + 3 * 10 + 5 + 100 = 167

// ���ɹ���Ϊ��
// ��ĳһλ��˵����1������Ϊ���󲿷�ֵ���Ը�λ�Ľ��ƣ������λΪ1����ôҪ�ټ����Ҳ�������ֵ+1�������λ����1��
// ��ô�ټ��ϸ�λ�Ľ���
// ʵ�ִ������£�
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
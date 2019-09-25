#include <stdio.h>


// һֻ����һ�ο�������1��̨�ף�Ҳ��������2��������Ҳ��������n���������������һ��n����̨���ܹ��ж�����������

// ����ͼ
// 1��1��
// 2��2��
// 3��4��
// 4��8��
// ��֮ǰ�Ļ����ϣ������׵��Ƴ�
// f(n) = f(n-1) + f(n-2) + f(n-3) + ... + f(0)
// ����ʵ������
int jumpFloorII(int number)
{
    int *cache = new int[number + 1];

    cache[0] = 1;
    cache[1] = 1;
    cache[2] = 2;

    for (int i = 3; i <= number; i++)
    {
        cache[i] = 0;
        for(int j = 0;j < i;j++)
        {
            cache[i] += cache[j];
        }
    }

    return cache[number];
}


int main()
{
    int count = 0;
    count = jumpFloorII(3);
    printf("count is %d\n", count);

    count = jumpFloorII(5);
    printf("count is %d\n", count);

    getchar();
    return 0;
}
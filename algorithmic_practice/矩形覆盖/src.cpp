#include <stdio.h>

// ���ǿ�����2*1��С���κ��Ż�������ȥ���Ǹ���ľ��Ρ�
// ������n��2*1��С�������ص��ظ���һ��2*n�Ĵ���Σ��ܹ��ж����ַ�����

// ������ʵ������������̨����ͬһ������
// �ο�������ɣ���������6��̨�ף����ǿ��Դӵ�5��һ����6��
// �����Ļ��ж����ַ�������5���ж����ַ�������6��
// ��������Ҳ���Դ�4����������6������4�ж����ַ����Ļ������ж����ַ�������6
int rectCover(int number) {
    int *cache = new int[number + 1];

    cache[1] = 1;
    cache[2] = 2;

    for (int i = 3; i <= number; i++)
    {
        cache[i] = cache[i - 1] + cache[i - 2];
    }

    return cache[number];
}

int main()
{
    int count = rectCover(5);
    printf("count is %d\n", count);
    getchar();
    return 0;
}
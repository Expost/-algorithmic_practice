#include <stdio.h>

// ��Ϊ�����������жϣ�����ʼ��ѭ���ӵķ�ʽ���ų���
// ��Ϊ��Ҫͨ����ʽ��������������ʽ��Ҫʹ�ó˷�������û�취���
// ����û�취�����۴���
// ����󣬸о��ܼ�,Ȼ���Լ������벻������ͨ�����߼��ķ�ʽ��Ϊ��ֹ�����������Ϳ��Եݹ������
int Sum_Solution(int n) {
    int vv = n;
    vv && (vv += Sum_Solution(n - 1));
    return vv;
}

int main()
{
    auto value = Sum_Solution(100);
    printf("%d\n", value);

    getchar();
    return 0;
}
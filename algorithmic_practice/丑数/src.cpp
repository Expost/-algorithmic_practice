#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

// �������㣬���Ӷ�̫�󣬳�ʱ
bool is_ugly_num(int v)
{
    for (int tmp = v % 2; tmp == 0; v /= 2, tmp = v % 2);
    for (int tmp = v % 3; tmp == 0; v /= 3, tmp = v % 3);
    for (int tmp = v % 5; tmp == 0; v /= 5, tmp = v % 5);

    return v == 1;
}

int GetUglyNumber_Solution(int index) 
{
    int v = 0;
    int count = 0;
    do 
    {
        v++;
        if (is_ugly_num(v))
            count++;

    } while (count != index);

    return v;
}

// �ο�����ʵ�ִ�������
int GetUglyNumber_Solution_1(int index)
{
    if (index < 7) return index;
    //p2��p3��p5�ֱ�Ϊ�������е�ָ�룬newNumΪ�Ӷ���ͷѡ��������С��
    int p2 = 0, p3 = 0, p5 = 0, newNum = 1;
    vector<int> arr;
    arr.push_back(newNum);
    while (arr.size() < index) {
        //ѡ����������ͷ��С����
        newNum = min(arr[p2] * 2, min(arr[p3] * 3, arr[p5] * 5));
        //������if�п��ܽ���һ�����߶��������������������ͷ��С�����ж�������
        if (arr[p2] * 2 == newNum) p2++;
        if (arr[p3] * 3 == newNum) p3++;
        if (arr[p5] * 5 == newNum) p5++;
        arr.push_back(newNum);
    }
    return newNum;
}



int main()
{
    printf("%d\n", GetUglyNumber_Solution_1(7));
    getchar();
    return 0;
}

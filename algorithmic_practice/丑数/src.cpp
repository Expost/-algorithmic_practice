#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

// 暴力计算，复杂度太大，超时
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

// 参考讨论实现代码如下
int GetUglyNumber_Solution_1(int index)
{
    if (index < 7) return index;
    //p2，p3，p5分别为三个队列的指针，newNum为从队列头选出来的最小数
    int p2 = 0, p3 = 0, p5 = 0, newNum = 1;
    vector<int> arr;
    arr.push_back(newNum);
    while (arr.size() < index) {
        //选出三个队列头最小的数
        newNum = min(arr[p2] * 2, min(arr[p3] * 3, arr[p5] * 5));
        //这三个if有可能进入一个或者多个，进入多个是三个队列头最小的数有多个的情况
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

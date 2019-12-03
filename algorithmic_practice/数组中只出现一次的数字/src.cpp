#include <stdio.h>
#include <vector>
#include <map>
#include <unordered_map>
using namespace std;

void FindNumsAppearOnce(vector<int> data, int* num1, int *num2) {
    unordered_map<int, uint8_t> m;
    for (auto &itr : data)
    {
        if (m[itr] == 0)
        {
            m[itr] += 1;
        }
        else
        {
            m[itr] -= 1;
        }
    }

    vector<int> v;
    for (auto &itr : m)
    {
        if (itr.second == 1)
            v.push_back(itr.first);
    }

    *num1 = v[0];
    *num2 = v[1];
}

// 上面这种方法比较low，比较简单粗暴
// 参考了讨论，技术流是采用异或的方式，果然是长见识了
void FindNumsAppearOnce_1(vector<int> data, int* num1, int *num2) {
    int v = 0;
    for (auto &itr : data)
    {
        v ^= itr;
    }



}


int main()
{
    vector<int> v = { 1,1,2,3,3,4,4,5,5,6,6,7,8,8,9,9 };
    int v1, v2;
    FindNumsAppearOnce(v, &v1, &v2);
    printf("%d %d\n", v1, v2);

    getchar();
    return 0;
}
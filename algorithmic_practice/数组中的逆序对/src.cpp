#include <stdio.h>
#include <vector>
#include <list>
using namespace std;

// ����ʵ�ֳ�ʱ������ 
int InversePairs(vector<int> data) {
    int count = 0;
    list<pair<int, int>> l;
    for (int i = 0; i < data.size(); i++)
    {
        bool inserted = false;
        auto itr = l.begin();
        for (; itr != l.end(); itr++)
        {
            if (itr->first > data[i])
            {
                count += itr->second;
            }
            else if (itr->first == data[i])
            {
                itr->second++;
                inserted = true;
                break;
            }
            else
            {
                break;
            }
        }

        if (!inserted)
        {
            l.insert(itr, pair<int, int>(data[i], 1));
        }
    }

    return count % 1000000007;
}

// �ο����ۣ�����ʵ��Ϊ�鲢���򣬿��ǵ��Լ�������鲢���������ʱ���ã����˽�鲢��������о�

int main()
{
    // 1, 2, 3, 7, 0, 4, 5, 2, 1
    //vector<int> v = { 1,2,3,4,5,6,7,0 };
    vector<int> v = { 1, 2, 3, 7, 0, 4, 5, 2, 1 };
    printf("%d\n", InversePairs(v));

    getchar();
    return 0;
}
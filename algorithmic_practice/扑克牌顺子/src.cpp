#include <stdio.h>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

bool IsContinuous(vector<int> numbers) 
{
    if (numbers.size() != 5)
    {
        return false;
    }

    sort(numbers.begin(), numbers.end());
    auto last_pos = numbers.size() - 1;
    auto last_value = numbers[last_pos];
    int zero_count = 0;
    int sec_count = 0;
    for (int i = last_pos - 1; i >= 0; i--)
    {
        if (numbers[i] == 0)
        {
            zero_count++;
            continue;
        }

        auto diff = last_value - numbers[i];
        if (diff >= 2 && diff <= 4)
        {
            sec_count += diff - 1;
        }
        else if (diff == 1)
        {
        }
        else
        {
            return false;
        }

        last_value = numbers[i];
    }

    return zero_count >= sec_count;
}

// �ο����ۿ����ǣ����ֵ����СֵҪ<5��ͬʱ��0��û���ظ����֡�������������ʵ�ֺ��й�һ���뷨�����о����Լ����벻�࣬��������
// �����������ʽ�������򣬶��Լ��ķ�����Ҫ���򣬸��Ӷȸ���

bool IsContinuous_1(vector<int> numbers)
{
    if (numbers.size() != 5)
    {
        return false;
    }

    map<int, int> m;
    int max = -1;
    int min = 14;
    for (int i = 0; i < numbers.size(); i++)
    {
        if (numbers[i] == 0)
        {
            continue;
        }

        if (m[numbers[i]] == 1)
            return false;

        m[numbers[i]] = 1;
        if (numbers[i] > max)
        {
            max = numbers[i];
        }

        if (numbers[i] < min)
        {
            min = numbers[i];
        }

        if (max - min >= 5) return false;
    }

    return true;
}


int main()
{
    vector<int> v = { 1,0,0,1,0 };
    auto ret = IsContinuous_1(v);
    printf("%d\n", ret);

    getchar();
    return 0;
}
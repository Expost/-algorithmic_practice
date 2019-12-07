#include <stdio.h>
#include <vector>
using namespace std;

bool BinarySearch(const vector<int> &array, int value)
{
    int vec_size = array.size();
    if (vec_size == 0)
    {
        return false;
    }

    int pos = (vec_size) / 2;
    if (array[pos] > value)
    {
        vector<int> new_array(array.begin(), array.begin() + pos);
        return BinarySearch(new_array, value);
    }
    else if (array[pos] < value)
    {
        vector<int> new_array(array.begin() + pos + 1, array.end());
        return BinarySearch(new_array, value);
    }
    else
    {
        return true;
    }
}

// ��С���������ÿ��ֵ���ö��ֲ�һ���Ƿ��з��Ͻ������һ����ֵ
vector<int> FindNumbersWithSum(vector<int> array, int sum) {
    vector<int> v;
    for (auto &itr : array)
    {
        if (itr >= sum)
        {
            break;
        }

        int remain = sum - itr;
        if (BinarySearch(array, remain))
        {
            v.push_back(itr);
            v.push_back(remain);
            break;
        }
    }

    return v;
}

// ��������������Ӧ�ò���������Ƶķ���
vector<int> FindNumbersWithSum_1(vector<int> array, int sum) {
    vector<int> v;
    int n = array.size();
    int i = 0, j = n - 1;
    while (i < j)
    {
        if (array[i] + array[j] == sum)
        {
            v.push_back(array[i]);
            v.push_back(array[j]);
            break;
        }

        while (i < j && array[i] + array[j] > sum)j--;
        while (i < j && array[i] + array[j] < sum)i++;
    }

    return v;
}



int main()
{
    vector<int> v = { 1,2,3,4,5,6,7,8,9,10 };
    vector<int> res = FindNumbersWithSum_1(v, 10);
    for (auto &itr : res)
    {
        printf("%d\n", itr);
    }

    getchar();
    return 0;
}
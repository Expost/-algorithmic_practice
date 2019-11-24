#include <stdio.h>
#include <vector>
using namespace std;

// 思路，二分查找
int BinarySearch(const vector<int> &array, int value)
{
    int vec_size = array.size();
    if (vec_size == 0)
    {
        return -1;
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
        return pos;
    }
}

int GetNumberOfK(vector<int> data, int k) 
{
    int ret = BinarySearch(data, k);
    if (ret == -1)
    {
        return 0;
    }

    int count = 1;
    for (int i = 1; ; i++)
    {
        bool find = false;
        if (ret + i < data.size() && data[ret + i] == k)
        {
            find = true;
            count++;
        }

        if (ret - 1 > 0 && data[ret - i] == k)
        {
            find = true;
            count++;
        }

        if (!find)
            break;
    }

    return count;
}

// 别人的答案，二分查找可以直接得到结果，不用像自己的那么麻烦

int BinSearch(const vector<int> &data, double num)
{
    int left = 0;
    int right = data.size() - 1;
    while (left <= right)
    {
        int mid = (right - left) / 2 + left;
        if (data[mid] < num)
            left = mid + 1;
        else if (data[mid] > num)
            right = mid - 1;
    }

    return left;
}

int GetNumberOfK_2(vector<int> data, int k)
{
    return BinSearch(data, k + 0.5) - BinSearch(data, k - 0.5);
}

int main()
{
    vector<int> v = { 1,2,3,4,4,5,6,7 };
    int count = GetNumberOfK_2(v, 4);
    printf("%d\n", count);

    getchar();
    return 0;
}
#include <stdio.h>
#include <vector>

using namespace std;

// 两次遍历，空间浪费较多
void reOrderArray(vector<int> &array) 
{
    int count = array.size();
    vector<int> odd;
    vector<int> even;

    for (int i = 0; i < count; i++)
    {
        if (array[i] & 1)
        {
            odd.push_back(array[i]);
        }
        else
        {
            even.push_back(array[i]);
        }
    }

    int odd_count = odd.size();
    for (int i = 0; i < count; i++)
    {
        if (i < odd_count)
        {
            array[i] = odd[i];
        }
        else
        {
            array[i] = even[i - odd_count];
        }
    }
}

// 前偶后奇相互交换，类似冒泡排序
void ReOrderArray(vector<int> &array)
{
    int count = array.size();
    for (int i = 0; i < count; i++)
    {
        for (int j = count - 1; j > i; j--)
        {
            if ((array[j - 1] & 1) == 0 && (array[j] & 1) == 1)
            {
                int tmp = array[j - 1];
                array[j - 1] = array[j];
                array[j] = tmp;
            }
        }
    }
}

int main()
{
    vector<int> array = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    ReOrderArray(array);

    for (auto &itr : array)
    {
        printf("%d\n", itr);
    }

    printf("================\n");
    vector<int> array1 = { 2,4,6,1,3,5,7 };
    ReOrderArray(array1);
    for (auto &itr : array1)
    {
        printf("%d\n", itr);
    }

    getchar();
    return 0;
}
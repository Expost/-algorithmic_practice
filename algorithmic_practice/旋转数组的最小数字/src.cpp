#include <stdio.h>
#include <vector>

using namespace std;

// { 1,2,3,4,5 }  ->  {3, 4, 5, 1, 2}

// 这基本上算是遍历了，肯定不过关的
int minNumberInRotateArray(vector<int> rotateArray) 
{
    if (rotateArray.empty())
    {
        return 0;
    }

    int value = rotateArray[0];
    for (auto &itr : rotateArray)
    {
        if (itr < value)
        {
            return itr;
        }

        value = itr;
    }

    return value;
}

// 网上查了下，需要使用二分进行查找
// 自己尝试实现如下，但经测试发现还不如上面的遍历😓
int BinarySearch(const vector<int> &array)
{
    int vec_size = array.size();
    if (vec_size == 0)
    {
        return -1;
    }

    int pos = (vec_size) / 2;
    if (pos >= 1 && array[pos - 1] > array[pos])
    {
        return array[pos];
    }
    if (pos <= vec_size - 2 && array[pos] > array[pos + 1])
    {
        return array[pos + 1];
    }


    vector<int> new_array0(array.begin(), array.begin() + pos);
    int value0 = BinarySearch(new_array0);

    vector<int> new_array1(array.begin() + pos + 1, array.end());
    int value1 = BinarySearch(new_array1);

    return value0 > value1 ? value0 : value1;
}

int MinNumberInRotateArray(vector<int> rotateArray)
{
    if (rotateArray.empty())
    {
        return 0;
    }

    int value = BinarySearch(rotateArray);
    if (value == -1)
    {
        return rotateArray[0];
    }

    return value;
}

// 查看相关讨论，比较好的实现如下
int OtherminNumberInRotateArray(vector<int> rotateArray) {
    int low = 0; int high = rotateArray.size() - 1;
    while (low < high) {
        int mid = low + (high - low) / 2;
        if (rotateArray[mid] > rotateArray[high]) {
            low = mid + 1;
        }
        else if (rotateArray[mid] == rotateArray[high]) {
            high = high - 1;
        }
        else {
            high = mid;
        }
    }

    return rotateArray[low];
}



int main()
{
    //vector<int> array = { 3, 4, 5, 6, 7 ,1, 2 };
    vector<int> array = { 7, 1 , 2, 3, 4, 5, 6, 7};
    int value = OtherminNumberInRotateArray(array);

    printf("value is %d\n", value);

    getchar();
    return 0;
}
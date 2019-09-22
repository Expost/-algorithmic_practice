#include <iostream>
#include <vector>

using namespace std;

// ��ά����Ĳ���
// �Լ���ʵ��
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
    else if(array[pos] < value)
    {
        vector<int> new_array(array.begin() + pos + 1, array.end());
        return BinarySearch(new_array, value);
    }
    else
    {
        return true;
    }
}

bool Find(int target, vector <vector<int>> array)
{
    if (array.empty())
    {
        return false;
    }

    for (auto &itr : array)
    {
        if (BinarySearch(itr, target))
        {
            return true;
        }
    }

    return false;
}

// ���˵�ʵ��
/* ˼·
* ����������ģ������½��������������ֵݼ����������ֵ�����
* ��˴����½ǿ�ʼ���ң���Ҫ�������ֱ����½����ִ�ʱ������
* Ҫ�������ֱ����½�����Сʱ������
*/
bool FindByOther(int target, vector<vector<int> > array)
{
    int rowCount = array.size();
    int colCount = array[0].size();

    for (int i = rowCount - 1, j = 0; i >= 0 && j < colCount;)
    {
        if (target == array[i][j])
            return true;
        if (target < array[i][j])
        {
            i--;
            continue;
        }
        if (target > array[i][j])
        {
            j++;
            continue;
        }
    }

    return false;
}


int main()
{
    vector<int> array0 = { 1, 4, 7, 10};
    vector<int> array1 = { 2, 5, 10, 20 };
    vector<int> array2 = { 3, 6, 20, 30 };
    vector<int> array3 = { 4, 20, 21, 50 };
    vector<vector<int>> array = { array0, array1, array2, array3 };

    bool ret = false;
    
    ret = FindByOther(1, array);
    printf("res is %d\n", ret);

    ret = FindByOther(4, array);
    printf("res is %d\n", ret);

    ret = FindByOther(10, array);
    printf("res is %d\n", ret);

    ret = FindByOther(5, array);
    printf("res is %d\n", ret);

    ret = FindByOther(6, array);
    printf("res is %d\n", ret);

    ret = FindByOther(20, array);
    printf("res is %d\n", ret);

    ret = FindByOther(21, array);
    printf("res is %d\n", ret);

    ret = FindByOther(30, array);
    printf("res is %d\n", ret);

    ret = FindByOther(50, array);
    printf("res is %d\n", ret);

    ret = FindByOther(100, array);
    printf("res is %d\n", ret);

    ret = FindByOther(23, array);
    printf("res is %d\n", ret);

    getchar();
    return 0;
}
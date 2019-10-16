#include <stdio.h>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

// 直接用map😢，不过倒是知道肯定不是这样考察的
int MoreThanHalfNum_Solution(vector<int> numbers) {
    map<int, int> m;
    for (auto &i : numbers)
    {
        m[i] += 1;
    }

    int count = numbers.size() / 2;
    for (auto iter = m.begin(); iter != m.end(); iter++)
    {
        if (iter->second > count)
        {
            return iter->first;
        }
    }

    return 0;
}

// 上面程序可以优化成这样子
int MoreThanHalfNum_Solution_1(vector<int> numbers) {
    map<int, int> m;
    int count = numbers.size() / 2;
    for (auto &i : numbers)
    {
        m[i] += 1;
        if (m[i] > count)
        {
            return i;
        }
    }

    return 0;
}


// 参考讨论，思路1
// 排序后，数组中间的那个数字就是对应的数
int MoreThanHalfNum_Solution_2(vector<int> numbers)
{
    // 因为用到了sort，时间复杂度O(NlogN)，并非最优
    if (numbers.empty()) return 0;

    sort(numbers.begin(), numbers.end()); // 排序，取数组中间那个数
    int middle = numbers[numbers.size() / 2];

    int count = 0; // 出现次数
    for (int i = 0; i < numbers.size(); ++i)
    {
        if (numbers[i] == middle) ++count;
    }

    return (count > numbers.size() / 2) ? middle : 0;
}


// 思路二：如果有符合条件的数字，则它出现的次数比其他所有数字出现的次数和还要多。
// 在遍历数组时保存两个值：一是数组中一个数字，一是次数。遍历下一个数字时，
// 若它与之前保存的数字相同，则次数加1，否则次数减1；若次数为0，则保存下一个数字，
// 并将次数置为1。遍历结束后，所保存的数字即为所求。然后再判断它是否符合条件即可。
//2,1,2,3,2
int MoreThanHalfNum_Solution_3(vector<int> numbers)
{
    if (numbers.empty())
    {
        return 0;
    }

    int res = numbers[0];
    int count = 1;
    for (int i = 1; i < numbers.size(); i++)
    {
        if (count == 0)
        {
            res = numbers[i];
            count = 1;
        }
        else if (numbers[i] == res)
        {
            count++;
        }
        else
        {
            count--;
        }
    }

    count = 0;
    for (auto &i : numbers)
    {
        if (i == res)
        {
            count++;
        }
    }

    return (count > numbers.size() / 2) ? res : 0;
}

int main()
{
    vector<int> v = { 1,2,3,2,2,2,5,4,2 };
    int i = MoreThanHalfNum_Solution_3(v);
    printf("%d\n", i);

    getchar();
    return 0;
}
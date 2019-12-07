#include <vector>
#include <stdio.h>
using namespace std;

vector<vector<int> > FindContinuousSequence(int sum) {
    int count = sum / 2 + 1;
    vector<vector<int>> vv;
    for (int i = 1; i <= count; i++)
    {
        int tmp_sum = 0;
        vector<int> v;
        for (int j = i;; j++)
        {
            tmp_sum += j;
            v.push_back(j);
            if (tmp_sum == sum && v.size() != 1)
            {
                vv.push_back(std::move(v));
            }
            if (tmp_sum > sum)
                break;
        }
    }

    return vv;
}

// 以上代码暴力穷举，复杂度很高,看了网上的讨论，都用到了等差数列的计算方法，然而自己竟然累加😥
// 然而自己毕业后就都把这些东西还给老师了。。。。

// 下面这种方法也是使用的比较多的，称为双指针方法
vector<vector<int> > FindContinuousSequence_1(int sum) {
    vector<vector<int>> vv;
    int plow = 1, phigh = 2;
    while (phigh > plow)
    {
        int cur = (phigh + plow) * (phigh - plow + 1) / 2;
        if (cur == sum) {
            vector<int> v;
            for (int i = plow; i <= phigh; i++) {
                v.push_back(i);
            }
            vv.push_back(std::move(v));
            plow++;
        }
        else if (cur < sum) {
            phigh++;
        }
        else {
            plow++;
        }
    }

    return vv;
}

// 下面这个代码比较牛逼，注意这里的n为序列的长度
// 详细的说明可以在牛客网上看到：https://www.nowcoder.com/questionTerminal/c451a3fd84b64cb19485dad758a55ebe
vector<vector<int> > FindContinuousSequence_2(int sum) {
    vector<vector<int>> vv;
    for (int n = sqrt(2 * sum); n >= 2; n--)
    {
        if (((n & 1) == 1) && (sum %n == 0) || ((sum % n) * 2 == n))
        {
            vector<int> v;
            // 这里的k为序列的第一个数字，k + n - 1即为最后一个数字，之后使用等差数列公式逆推
            for (int j = 0, k = (sum / n) - (n - 1) / 2; j < n; j++, k++)
            {
                v.push_back(k);
            }

            vv.push_back(std::move(v));
        }
    }

    return vv;
}

int main()
{
    auto vv = FindContinuousSequence(100000000000000);
    
    for (auto &v : vv)
    {
        for (auto &i : v)
        {
            printf("%d ", i);
        }

        printf("\n");
    }

    getchar();
    return 0;
}
#include <stdio.h>
#include <string>
#include <vector>
using namespace std;
#pragma warning(disable:4996)


// 在字典序上纠结了很久。。。。
// 自己的思路是，对于字符串abc，
// 以a为起始，剩下的bc共有bc、cb两种方式，与a连起来则是abc、acb
// 以b为基准，剩下的ac共有ac、ca两种方式，与b连起来则是bac、bca
// 以c为基准，剩下的ab共有ab、ba两种方式，与c连起来则是cab、cba
// 在a起始时，对剩下的bc来说，其又可以
// 以b为基准，剩下的c只有一种方式，那么便是bc
// 以c为基准，剩下的b只有一种方式，那么便是cb
// 以b起始时，对剩下的ac来说，同理
// 由此可见这正好是一个递归

// 在参考别人的程序后，发现自己完全可以用swap交换代替
// 不过似乎这样erase以及insert的方式似乎更加好理解，暂这样保留吧
vector<string> Permutation(string str) 
{
    vector<string> v;
    if (str.size() == 0)
    {
        return v;
    }
    else if (str.size() == 1)
    {
        v.push_back(str);
    }
    else {
        for (int i = 0; i < str.size(); i++)
        {
            char c = str[i];
            string tmp_str = str;
            tmp_str.erase(tmp_str.begin() + i);
            auto tv = Permutation(tmp_str);

            for (auto &s : tv)
            {
                auto tmp_s = s;
                tmp_s.insert(tmp_s.begin(), c);
                if (find(v.begin(), v.end(), tmp_s) == v.end())
                {
                    v.push_back(tmp_s);
                }
            }
        }
    }

    return v;
}

// 参考别人的实现
// 发现其实现与自己的思路相差不多
// 整个思路是，给一个字符串，abc，
// 以a为基准，bc共有bc、cb两种方式，
// 以b为基准，ac共有ac、ca两种方式，
// 以c为基准，ab共有ab、ba两种排列方式
void swap(char &fir, char &sec)
{
    char temp = fir;
    fir = sec;
    sec = temp;
}

void PermutationHelper(string str, vector<string> &result, int begin)
{
    if (begin == str.size() - 1)
    {
        printf("%s\n", str.c_str());
        if (find(result.begin(), result.end(), str) == result.end())
        {
            result.push_back(str);
        }
    }
    else
    {
        for (int i = begin; i < str.size(); i++)
        {
            swap(str[i], str[begin]);
            PermutationHelper(str, result, begin + 1);
            swap(str[i], str[begin]);
        }
    }
}

vector<string> Permutation_1(string str)
{
    vector<string> v;
    if (!str.empty())
    {
        PermutationHelper(str, v, 0);
    }

    return v;
}

int main()
{
    string str = "abc";
    auto v = Permutation_1(str);
    for (auto &s : v)
    {
        printf("%s\n", s.c_str());
    }

    getchar();
    return 0;
}
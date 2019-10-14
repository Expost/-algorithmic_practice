#include <stdio.h>
#include <string>
#include <vector>
using namespace std;
#pragma warning(disable:4996)


void push(vector<string> &v, string &s)
{
    for (auto &ss : v)
    {
        if (s == ss)
        {
            return;
        }
    }

    v.push_back(s);
}

// 在字典序上纠结了很久。。。。
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
                push(v, tmp_s);
            }
        }
    }

    return v;
}

// 参考别人的实现
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
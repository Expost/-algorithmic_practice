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

int main()
{
    string str = "abc";
    auto v = Permutation(str);
    for (auto &s : v)
    {
        printf("%s\n", s.c_str());
    }

    getchar();
    return 0;
}
#include <stdio.h>
#include <string>
#include <vector>
using namespace std;
//#pragma warning(disable:4996)

// C++最开始写不出来，主要因为没有处理好空格，用Python的话就几行😂
//def ReverseSentence(self, s) :
//    l = s.split(" ")
//    l.reverse()
//    return " ".join(l)

std::vector<std::string> split(const std::string& value, char separator)
{
    std::vector<std::string> result;
    std::string::size_type p = 0;
    std::string::size_type q;
    while ((q = value.find(separator, p)) != std::string::npos)
    {
        result.emplace_back(value, p, q - p);
        p = q + 1;
    }
    result.emplace_back(value, p);
    return result;
}

string ReverseSentence(string str) {
    string s;
    if (str.empty())
        return s;
    
    vector<string> v = split(str, ' ');
    reverse(v.begin(), v.end());
    if (v.empty())
        return s;
    s += v[0];
    for (auto i = 1; i < v.size(); i++)
    {
        s = s + " " + v[i];
    }
    
    return s;
}

// 下面是参考讨论的解法
string ReverseSentence_1(string str) {
    string res = "";
    string tmp = "";

    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == ' ')
        {
            res = " " + tmp + res;
            tmp = "";
        }
        else
        {
            tmp += str[i];
        }
    }

    if (tmp.size() > 0)
    {
        res = tmp + res;
    }

    return res;
}


int main()
{
    string str = "student. a am I";
    //string str = "";
    //string str = "  ";
    auto s = ReverseSentence_1(str);
    printf("\"%s\"\n", s.c_str());

    getchar();
    return 0;
}
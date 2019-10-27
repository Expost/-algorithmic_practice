#include <stdio.h>
#include <string>
#include <map>
#include <list>
using namespace std;

// 用了map和list，比较蛋疼一些
int FirstNotRepeatingChar(string str) 
{
    map<char, int> m;
    list<pair<char, int>> l;
    for (int i = 0; i < str.size(); i++)
    {
        char c = str[i];
        if (m[c] == 0)
        {
            m[c]++;
            l.push_back(pair<char, int>(c, i));
        }
        else
        {
            for (auto itr = l.begin(); itr != l.end(); itr++)
            {
                if (itr->first == c)
                {
                    l.erase(itr);
                    break;
                }
            }
        }
    }

    if (l.empty())
    {
        return -1;
    }
    else
    {
        return l.front().second;
    }
}

// 别人的代码
int FirstNotRepeatingChar_1(string str)
{
    map<char, int> m;
    for (int i = 0; i < str.size(); i++)
    {
        m[str[i]]++;
    }

    for (int i = 0; i < str.size(); i++)
    {
        if (m[str[i]] == 1)
        {
            return i;
        }
    }

    return -1;
}

int main()
{
    string s = "aabpdfeawfeabawefpawfedwa";
    printf("%d\n", FirstNotRepeatingChar(s));

    getchar();
    return 0;
}
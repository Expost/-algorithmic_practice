#include <stdio.h>
#include <vector>
#include <string>
#include <tuple>
using namespace std;

bool equal(char s, char p)
{
    if (s != 0)
    {
        if (p == '.')
            return true;
        if (p == s)
            return true;

        return false;
    }
        
    return false;
}

bool match(char* str, char* pattern)
{
    while (*pattern != 0)
    {
        if (*(pattern + 1) != 0 && *(pattern + 1) == '*')
        {
            int pos = 0;
            for (; equal(*(str + pos), *pattern); pos++)
            {
                if (match(str + pos + 1, pattern + 2))
                {
                    return true;
                }
            }

            str += pos ? pos - 1 : pos;
            pattern += 2;
        }
        else
        {
            if (!equal(*str, *pattern))
            {
                return false;
            }

            str++;
            pattern++;
        }
    }

    return *str == 0;
}


int main()
{
    vector<tuple<string, string, bool>> testcase { {"", ".*", true},
                                              {"aaa", "a.a", true},
                                              {"aaa", "ab*ac*a", true},
                                              {"bbbba", ".*a*a", true} };
    for (auto &p : testcase)
    {
        bool b = match(&(get<0>(p))[0], &(get<1>(p))[0]);
        printf("%d %d\n", b, get<2>(p));
    }

    getchar();
    return 0;
}
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
    int str_pos = 0;
    int pat_pos = 0;
    while (*(pattern + pat_pos) != 0)
    {
        if (*(pat_pos + pattern + 1) != 0 && *(pat_pos + pattern + 1) == '*')
        {
            bool equaled = false;
            while (equal(*(str_pos + str), *(pattern + pat_pos)))
            {
                //printf("%s %s\n", str + str_pos + 1, pattern + pat_pos + 2);
                if (match(str + str_pos + 1, pattern + pat_pos + 2))
                {
                    return true;
                }

                str_pos++;
                equaled = true;
            }

            if (equaled)
            {
                str_pos--;
            }
            
            pat_pos += 2;
        }
        else
        {
            if (!equal(*(str + str_pos), *(pat_pos + pattern)))
            {
                return false;
            }

            str_pos++;
            pat_pos++;
        }
    }

    return *(str + str_pos) == 0;
}


int main()
{
    vector<tuple<string, string, bool>> testcase = { {"", ".*", true},
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
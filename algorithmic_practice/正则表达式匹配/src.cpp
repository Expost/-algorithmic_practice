#include <stdio.h>

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
            while (equal(*(str_pos + str), *(pattern + pat_pos)))
            {
                if (match(str + str_pos + 1, pattern + pat_pos + 2))
                {
                    return true;
                }

                str_pos++;
                if (str_pos == 4)
                {
                    printf("hh");
                }
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
    char str[] = "bbbba";
    //char str[] = "aaa";
    //char pattern[] = "a.a";
    //char pattern[] = "ab*ac*a";
    //char pattern[] = "ab*a";
    char pattern[] = ".*a*a";
    //char pattern[] = ".*";
    //char pattern[] = "a*a";

    bool b = match(str, pattern);
    printf("%d\n", b);

    getchar();
    return 0;
}
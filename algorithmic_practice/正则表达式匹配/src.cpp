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

// ƥ��'.'�ǳ��򵥣�����ƥ��'*'ʱ����һЩ�ӣ�����Ĵ���Ϊ��'*'�����˺þ�
// �������۵Ĵ��룬�����Լ���ʵ��ȫ�õݹ�����ˣ�����Ĵ������˵ݹ��ѭ����
// ����������ȫ�ݹ�ͳһ
// �ο����۴��룬����ĳɵݹ�ʵ��

bool match_1(char* str, char* pattern)
{
    if (*pattern == 0 && *str == 0) 
        return true;
    if (*pattern == 0 && *str != 0) 
        return false;

    if (*(pattern + 1) == '*')
    {
        if (equal(*str, *pattern))
        {
            return match_1(str, pattern + 2) || //< ƥ��0��
                   match_1(str + 1, pattern);   //< ƥ��1������
        }
        // ƥ��0��
        else
        {
            return match_1(str, pattern + 2);
        }
    }
    else
    {
        if (equal(*str, *pattern))
            return match_1(str + 1, pattern + 1);
        else
            return false;
    }
}

int main()
{
    vector<tuple<string, string, bool>> testcase { {"", ".*", true},
                                              {"aaa", "a.a", true},
                                              {"aaa", "ab*ac*a", true},
                                              {"bbbba", ".*a*a", true} };
    for (auto &p : testcase)
    {
        bool b = match_1(&(get<0>(p))[0], &(get<1>(p))[0]);
        printf("%d %d\n", b, get<2>(p));
    }

    getchar();
    return 0;
}
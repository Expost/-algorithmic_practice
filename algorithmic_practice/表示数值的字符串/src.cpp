#include <stdio.h>
#include <string>
#include <vector>
using namespace std;

bool isNumeric(char* string)
{
    if (string == nullptr)
    {
        return false;
    }

    if (*string == '+' || *string == '-')   string++;

    while (*string >= '0' && *string <= '9') string++;
    if (*string == '.') string++;
    while (*string >= '0' && *string <= '9') string++;

    if (*string == 'E' || *string == 'e')
    {
        string++;
        if (*string == 0)
            return false;
        else if (*string == '+' || *string == '-') 
            string++;

        while (*string >= '0' && *string <= '9') string++;

        if (*string != 0)
            return false;
        else
            return true;
    }
    else if (*string == 0)
        return true;
    else
        return false;

    return true;
}

int main()
{
    vector<string> testdata{ "+100", "5e2", "-123", "-1E-16", "3.1415926", "123.45e+6" };
    for (auto &itr : testdata)
    {
        printf("%d\n", isNumeric(&itr[0]));
    }

    printf("========================\n");
    vector<string> invalid_data{ "12e","1a3.14","1.2.3","+-5", "12e+4.3" };
    for (auto &itr : invalid_data)
    {
        printf("%d\n", isNumeric(&itr[0]));
    }

    getchar();
    return 0;
}
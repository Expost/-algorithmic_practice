#include <stdio.h>
#include <string>
#include <vector>
using namespace std;

bool isNumeric(char* string)
{
    return true;
}

int main()
{
    vector<string> testdata{ "+100", "5e2", "-123", "-1E-16", "3.1415926" };
    for (auto &itr : testdata)
    {
        printf("%d\n", isNumeric(&itr[0]));
    }


    getchar();
    return 0;
}
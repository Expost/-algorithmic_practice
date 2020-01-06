#include <stdio.h>
#include <string>
#include <vector>
using namespace std;

enum state
{
    START = 1,
    SIGN = 2,
    NUM = 4, 
    FLOAT = 8,
    E = 16,
    DOT = 32,
};

bool isNumeric(char* string)
{
    if (string == nullptr)
    {
        return false;
    }

    int s = START;
    if (*string == '+' || *string == '-')
    {
        string++;
    }



    //vector<state> v;
    //while (*string != 0)
    //{
    //    if (*string == '+' || *string == '-')
    //    {
    //        v.push_back(SIGN);
    //    }
    //    else if (*string >= '0' && *string <= '9')
    //    {
    //        v.push_back(NUM);
    //    }
    //    else if (*string == 'e' || *string == 'E')
    //    {
    //        v.push_back(E);
    //    }
    //    else if (*string == '.')
    //    {
    //        v.push_back(DOT);
    //    }
    //    else
    //        return false;
    //}


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
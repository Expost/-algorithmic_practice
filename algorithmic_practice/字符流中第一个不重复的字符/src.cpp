#include <stdio.h>
#include <vector>
#include <unordered_map>
using namespace std;

vector<char> v;
unordered_map<char, int> m;

void Insert(char ch)
{
    m[ch] += 1;
    v.push_back(ch);
}
//return the first appearence once char in current stringstream
char FirstAppearingOnce()
{
    for (auto &i : v)
    {
        if (m[i] == 1)
            return i;
    }
    
    return '#';
}

// 参考讨论，下面是稍微优化一些的代码
// 只会添加一次字符，避免大量重复的字符重复添加，降低后面的循环复杂度

void Insert_1(char ch)
{
    m[ch] += 1;
    if(m[ch] == 1)
        v.push_back(ch);
}

//return the first appearence once char in current stringstream
char FirstAppearingOnce_1()
{
    for (auto &i : v)
    {
        if (m[i] == 1)
            return i;
    }

    return '#';
}


int main()
{
    string s = "google";
    for (auto &i : s)
    {
        Insert_1(i);
    }

    char c = FirstAppearingOnce_1();
    printf("%c\n", c);

    return 0;
}
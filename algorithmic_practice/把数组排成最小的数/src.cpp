#include <stdio.h>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// 这道题傻逼了，想了好久不知道该怎么做，不想暴力拼接了
// 最终无奈看讨论了
// 自定义一个比较大小的函数，比较两个字符串s1, s2大小的时候，先将它们拼接起来，比较s1+s2,和s2+s1哪个大，
// 如果s1+s2大，那说明s2应该放前面，所以按这个规则，s2就应该排在s1前面。
bool cmp(int v1, int v2)
{
    string s1 = to_string(v1) + to_string(v2);
    string s2 = to_string(v2) + to_string(v1);
    return s1 < s2;
}

string PrintMinNumber(vector<int> numbers) 
{
    string str;
    sort(numbers.begin(), numbers.end(), cmp);
    for (auto &n : numbers)
    {
        str += to_string(n);
    }

    return str;
}

int main()
{
    vector<int> v = { 3, 32, 321 };
    string str = PrintMinNumber(v);
    printf("%s\n", str.c_str());
    
    getchar();
    return 0;
}
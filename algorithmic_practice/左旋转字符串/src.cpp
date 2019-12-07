#include <stdio.h>
#include <string>
using namespace std;

string LeftRotateString(string str, int n) {
    string res;
    size_t str_len = str.size();
    res.resize(str_len);
    n = n % str_len;
    for (int i = 0; i < str_len; i++)
    {
        int new_pos = (i - n) >= 0 ? (i - n) : i - n + str_len;
        res[new_pos] = str[i];
    }

    return res;
}

// 看了讨论，说这道题考的是反转字符串，但感觉自己的实现也挺好的😊
// 三重反转
string LeftRotateString_1(string str, int n) {
    string s = str;
    reverse(s.begin(), s.end());
    reverse(s.begin(), s.begin() + s.size() - n);
    reverse(s.begin() + s.size() - n, s.end());
   
    return s;
}

// 这里还有另外一种比较好的实现
string LeftRotateString_2(string str, int n) {
    int str_len = str.size();
    if (str_len == 0) return "";
    n = n % str_len;
    str += str;
    return str.substr(n, str_len);
}

int main()
{
    string str = "123456789";
    string res = LeftRotateString_2(str, 1);
    printf("%s\n", res.c_str());

    getchar();
    return 0;
}
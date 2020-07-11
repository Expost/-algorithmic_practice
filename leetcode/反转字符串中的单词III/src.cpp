#include <stdio.h>
#include <string>
#include <vector>
using namespace std;

void reverseString(string& s, int i, int j) {
    while (i < j) {
        char tmp = s[i];
        s[i] = s[j];
        s[j] = tmp;
        i++;
        j--;
    }
}

string reverseWords(string s) {
    for (int i = 0; i < s.size(); ) {
        int blank = i;
        while (blank < s.size() && s[blank] != ' ')blank++;
        reverseString(s, i, blank - 1);
        i = blank + 1;
    }

    return s;
}

int main() {
    string s, ret;
   
    s = "Let's take LeetCode contest";
    ret = reverseWords(s);
    printf("%s\n", ret.c_str());



    getchar();
    return 0;
}
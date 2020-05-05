#include <stdio.h>
#include <string>
using namespace std;

int longestSubstring(string s, int k) {
    return 0;

}


int main() {
    string s;
    int ret = 0;

    s = "aaabb";
    ret = longestSubstring(s, 3);
    printf("%d\n", ret);

    s = "ababbc";
    ret = longestSubstring(s, 2);
    printf("%d\n", ret);

    getchar();
    return 0;
}
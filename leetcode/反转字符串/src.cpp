#include <stdio.h>
#include <vector>
using namespace std;

void reverseString(vector<char>& s) {
    int i = 0;
    int j = s.size() - 1;
    while (i < j) {
        char tmp = s[i];
        s[i] = s[j];
        s[j] = tmp;
        i++;
        j--;
    }
}

int main() {
    vector<char> v;

    v = { 'h','e','l','l','o' };
    reverseString(v);
    for (auto &itr : v) {
        printf("%c ", itr);
    }

    printf("\n");
    v = { 'H','a','n','n','a','h' };
    reverseString(v);
    for (auto &itr : v) {
        printf("%c ", itr);
    }

    getchar();
    return 0;
}
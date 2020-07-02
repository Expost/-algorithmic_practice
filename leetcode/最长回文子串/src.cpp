#include <stdio.h>
#include <string>
#include <vector>
using namespace std;

string palindrome(string &s, int i, int j) {
    
    while (i >= 0 && j < s.length() && s[i] == s[j]) {
        i--;
        j++;
    }

    return s.substr(i + 1, j - i - 1);
}

//string longestPalindrome(string s) {
//    string ret;
//    for (int i = 0; i < s.length(); i++) {
//        string a = palindrome(s, i, i);
//        string b = palindrome(s, i, i + 1);
//        if (a.length() > ret.length()) ret = a;
//        if (b.length() > ret.length()) ret = b;
//    }
//
//    return ret;
//}

// 动态规划算法
string longestPalindrome(string s) {
    int n = s.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        dp[i][i] = 1;
    }

    int max_len = 1;
    int start_pos = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 1; j < i; j++) {
            if (s[i] == s[j]) {
                if (dp[i + 1][j - 1] == 1) {
                    dp[i][j] = 1;
                    if (j - i + 1 > max_len) {
                        max_len = j - i + 1;
                        start_pos = i;
                    }
                }
                else if (j - i == 1) {
                    dp[i][j] = 1;
                    if (j - i + 1> max_len) {
                        max_len = j - i + 1;
                        start_pos = i;
                    }
                }
            }
        }
    }

    return s.substr(start_pos, max_len);
}

int main() {
    string s;
    string ret;


    ret = longestPalindrome("abccba");
    printf("%s\n", ret.c_str());

    ret = longestPalindrome("abcda");
    printf("%s\n", ret.c_str());

    ret = longestPalindrome("cbbd");
    printf("%s\n", ret.c_str());

    ret = longestPalindrome("bb");
    printf("%s\n", ret.c_str());

    ret = longestPalindrome("babad");
    printf("%s\n", ret.c_str());

    ret = longestPalindrome("ababcdefg");
    printf("%s\n", ret.c_str());




    getchar();
    return 0;
}
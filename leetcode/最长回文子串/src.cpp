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

string longestPalindrome(string s) {
    int n = s.size();
    vector<vector<int>> dp(n, vector<int>(n));
    string ans;
    for (int l = 0; l < n; ++l) {
        for (int i = 0; i + l < n; ++i) {
            int j = i + l;
            if (l == 0) {
                dp[i][j] = 1;
            }
            else if (l == 1) {
                dp[i][j] = (s[i] == s[j]);
            }
            else {
                dp[i][j] = (s[i] == s[j] && dp[i + 1][j - 1]);
            }
            if (dp[i][j] && l + 1 > ans.size()) {
                ans = s.substr(i, l + 1);
            }
        }
    }
    return ans;
}

int main() {
    string s;
    string ret;

    ret = longestPalindrome("babad");
    printf("%s\n", ret.c_str());

    ret = longestPalindrome("ababcdefg");
    printf("%s\n", ret.c_str());

    ret = longestPalindrome("abccba");
    printf("%s\n", ret.c_str());

    getchar();
    return 0;
}
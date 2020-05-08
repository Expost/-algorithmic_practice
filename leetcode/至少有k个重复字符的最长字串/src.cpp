#include <stdio.h>
#include <string>
#include <vector>
#include <map>
using namespace std;

#define max(a, b) (((a) > (b)) ? (a) : (b))


// 以下实现错误，做不出来
//int longestSubstring(string s, int k) {
//    int str_len = s.size();
//    int loggest = 0;
//    vector<vector<map<int, vector<char>>>> vv(str_len, vector<map<int, vector<char>>>(str_len));
//
//    for (int i = 0; i < str_len;i++) {
//        for (int j = i;j < str_len;j++) {
//            char c = s[j];
//            if (i == j) {
//                vv[i][j][1].push_back(c);
//            }
//            else {
//                for (auto &itr : vv[i][j - 1]) {
//                    auto iitr = itr.second.begin();
//                    for (;iitr != itr.second.end();iitr++) {
//                        if (*iitr == c) {
//                            itr.second.erase(iitr);
//                            vv[i][j][itr.first + 1].push_back(c);
//                            break;
//                        }
//                    }
//                }
//
//                vv[i][j].insert(vv[i][j - 1].begin(), vv[i][j - 1].end());
//                for (auto &itr : vv[i][j]) {
//                    if (!itr.second.empty() && itr.first >= k){
//                        loggest = max(loggest, j - i + 1);
//                    }
//                }
//            }
//        }
//    }
//
//    return loggest;
//}

// 参考讨论，实现如下，还需要再好好想想
int count(const char* chars, int k, int p1, int p2){
    if (p2 - p1 + 1 < k)return 0;
    vector<int> v(26);
    for (int i = p1;i <= p2;i++)
        v[chars[i] - 'a']++;

    while (p2 - p1 + 1 >= k && v[chars[p1] - 'a'] < k)
        p1++;
    while (p2 - p1 + 1 >= k &&v[chars[p2] - 'a'] < k)
        p2--;

    if (p2 - p1 + 1 < k)return 0;

    for (int i = p1;i <= p2;i++) {
        if (v[chars[i] - 'a'] < k) {
            return max(count(chars, k, p1, i - 1), count(chars, k, i + 1, p2));
        }
    }

    return p2 - p1 + 1;
}

int longestSubstring(string s, int k) {
    int len = s.size();
    if (len == 0 || len < k) return 0;
    if (k < 2) return len;

    return count(s.c_str(), k, 0, len - 1);
}

int main() {
    string s;
    int ret = 0;

    s = "ababbc";
    ret = longestSubstring(s, 2);
    printf("%d\n", ret);

    s = "aaabb";
    ret = longestSubstring(s, 3);
    printf("%d\n", ret);



    getchar();
    return 0;
}
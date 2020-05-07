#include <stdio.h>
#include <string>
#include <vector>
#include <map>
using namespace std;

#define max(a, b) (((a) > (b)) ? (a) : (b))

int longestSubstring(string s, int k) {
    int str_len = s.size();
    int loggest = 0;
    vector<vector<map<int, vector<char>>>> vv(str_len, vector<map<int, vector<char>>>(str_len));

    for (int i = 0; i < str_len;i++) {
        for (int j = i;j < str_len;j++) {
            char c = s[j];
            if (i == j) {
                vv[i][j][1].push_back(c);
            }
            else {
                for (auto &itr : vv[i][j - 1]) {
                    auto iitr = itr.second.begin();
                    for (;iitr != itr.second.end();iitr++) {
                        if (*iitr == c) {
                            itr.second.erase(iitr);
                            vv[i][j][itr.first + 1].push_back(c);
                            break;
                        }
                    }
                }

                if (!vv[i][j].empty())
                {
                    for (auto &itr : vv[i][j]) {
                        if (!itr.second.empty() && itr.first >= k){
                            loggest = max(loggest, j - i + 1);
                        }
                    }
                    
                }
            }
        }
    }

    return loggest;

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
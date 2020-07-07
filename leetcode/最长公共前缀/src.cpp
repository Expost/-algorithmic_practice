#include <stdio.h>
#include <vector>
#include <string>

using namespace std;

string longestCommonPrefix(vector<string>& strs) {
    string s;
    if (strs.empty())return s;
    for(int index = 0;;index++) {
        char c = 0;
        for (int i = 0; i < strs.size(); i++) {
            if (index >= strs[i].size())
                return s;
            if (i == 0)
                c = strs[i][index];
            else {
                if (strs[i][index] != c)
                    return s;
            }
        }
        s += c;
    }

    return s;
}

int main() {
    vector<string> strs;
    string ret;

    strs = { "flower", "flow", "flight" };
    ret = longestCommonPrefix(strs);
    printf("%s\n", ret.c_str());

    strs = { "dog", "racecar", "car" };
    ret = longestCommonPrefix(strs);
    printf("%s\n", ret.c_str());

    getchar();
    return 0;
}
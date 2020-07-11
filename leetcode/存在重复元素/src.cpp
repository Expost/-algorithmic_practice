#include <stdio.h>
#include <vector>
#include <unordered_set>
using namespace std;

bool containsDuplicate(vector<int>& nums) {
    unordered_set<int> s;
    for (auto &itr : nums) {
        if (s.find(itr) != s.end()) {
            return true;
        }

        s.insert(itr);
    }

    return false;
}

int main() {
    vector<int> v;
    bool ret;

    v = { 1,2,3,1 };
    ret = containsDuplicate(v);
    printf("%d\n", ret);

    v = { 1,2,3,4 };
    ret = containsDuplicate(v);
    printf("%d\n", ret);

    v = { 1,1,1,3,3,4,3,2,4,2 };
    ret = containsDuplicate(v);
    printf("%d\n", ret);

    getchar();
    return 0;
}
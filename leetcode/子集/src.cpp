#include <stdio.h>
#include <vector>

using namespace std;

// 回溯，复杂度太高，而且重复值太多，且需要判重
vector<vector<int>> recurse(vector<int> &nums) {
    vector<vector<int>> vv;

    for (int i = 0; i < nums.size(); i++) {
        vector<int> copy(nums);
        copy.erase(copy.begin() + i);
        vv.emplace_back(copy);
        auto ret = recurse(copy);
        vv.insert(vv.begin(), ret.begin(), ret.end());
    }

    return vv;
}

vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> vv;
    vv = recurse(nums);
    return vv;
}

int main() {
    vector<int> v;
    vector<vector<int>> ret;

    v = { 1, 2, 3, 4, 5, 6, 7 };
    ret = subsets(v);
    for (auto &itr : ret) {
        for (auto &sub : itr) {
            printf("%d ", sub);
        }

        printf("\n");
    }

    getchar();
    return 0;
}
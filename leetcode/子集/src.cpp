#include <stdio.h>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

// 回溯，复杂度太高，而且重复值太多，且需要判重
//vector<vector<int>> recurse(vector<int> &nums) {
//    vector<vector<int>> vv;
//
//    for (int i = 0; i < nums.size(); i++) {
//        vector<int> copy(nums);
//        copy.erase(copy.begin() + i);
//        vv.emplace_back(copy);
//        auto ret = recurse(copy);
//        vv.insert(vv.begin(), ret.begin(), ret.end());
//    }
//
//    return vv;
//}
//
//vector<vector<int>> subsets(vector<int>& nums) {
//    vector<vector<int>> vv;
//    vv = recurse(nums);
//    return vv;
//}

// 看了讨论，发现自己上面的回溯实现实在是太烂了
void recurse(vector<int> &nums, int pos, vector<int> track, vector<vector<int>> &vv) {
    vv.push_back(track);
    for (int i = pos; i < nums.size(); i++) {
        track.push_back(nums[i]);
        recurse(nums, i + 1, track, vv);
        track.pop_back();
    }
}

vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> vv;
    vector<int> v;
    recurse(nums, 0, v, vv);
    return vv;
}


int main() {
    vector<int> v;
    vector<vector<int>> ret;

    v = { 1, 2, 3 };
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
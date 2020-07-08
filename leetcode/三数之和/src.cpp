#include <stdio.h>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

// 暴力，搞不定，发现难点在去重这里
//vector<vector<int>> threeSum(vector<int>& nums) {
//    map<int, bool> m;
//
//    vector<vector<int>> vv;
//    for (int i = 0;i < nums.size();i++) {
//        for (int j = i + 1;j < nums.size();j++) {
//            for (int k = j + 1;k < nums.size();k++) {
//                int x = nums[i] * nums[i] + nums[j] * nums[j] + nums[k] * nums[k];
//                //printf("%d %d %d -> %d\n", nums[i], nums[j], nums[k], x);
//                if (nums[i] + nums[j] + nums[k] == 0 && m.find(x) == m.end()) {
//                    vv.push_back({ nums[i], nums[j], nums[k] });
//                    m[x] = true;
//                }
//            }
//        }
//    }
//
//    return vv;
//}

// 尝试想了什么递归、动态规划等鬼方法，最终发现竟然真的是暴力上的一点优化
vector<vector<int>> threeSum(vector<int> &nums) {
    int n = nums.size();
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;
    for (int i = 0; i < n; i++) {
        if (i > 0 && nums[i] == nums[i - 1]) {
            continue;
        }

        int k = n - 1;
        int target = -nums[i];
        for (int j = i + 1; j < n; j++) {
            if (j > i + 1 && nums[j] == nums[j - 1]) {
                continue;
            }

            while (j < k && nums[j] + nums[k] > target) {
                k--;
            }

            if (j == k)
                break;

            if (nums[j] + nums[k] == target) {
                ans.push_back({ nums[i], nums[j], nums[k] });
            }
        }
    }

    return ans;
}


int main() {
    vector<int> v;
    vector<vector<int>> vv;

    v = { -4,-2,-2,-2,0,1,2,2,2,3,3,4,4,6,6 };
    vv = threeSum(v);
    for (auto &itr : vv) {
        for (auto &i : itr) {
            printf("%d ", i);
        }

        printf("\n");
    }


    //v = { -1, 0, 1, 2, -1, -4 };
    //vv = threeSum(v);
    //for (auto &itr : vv) {
    //    for (auto &i : itr) {
    //        printf("%d ", i);
    //    }

    //    printf("\n");
    //}


    getchar();
    return 0;
}
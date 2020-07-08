#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

// 暴力，超时倒没超时
//int threeSumClosest(vector<int>& nums, int target) {    
//    int64_t closest_target = INT_MAX;
//    for (int i = 0;i < nums.size();i++) {
//        for (int j = i + 1;j < nums.size();j++) {
//            for (int k = j + 1;k < nums.size();k++) {
//                int v = nums[i] + nums[j] + nums[k];
//                if (abs(target - v) < abs(target - closest_target)) {
//                    closest_target = v;
//                }
//            }
//        }
//    }
//    
//    return closest_target;
//}

// 排序
int threeSumClosest(vector<int> &nums, int target) {
    int n = nums.size();
    sort(nums.begin(), nums.end());
    int64_t closest_target = INT_MAX;
    for (int i = 0; i < n; i++) {
        if (i > 0 && nums[i] == nums[i - 1]) {
            continue;
        }

        int j = i + 1;
        int k = n - 1;
        while (j < k) {
            int v = nums[i] + nums[j] + nums[k];
            if (abs(target - v) < abs(target - closest_target)) {
                closest_target = v;
            }
            if (v < target) {
                int j0 = j + 1;
                while (j0 < k && nums[j0] == nums[i]) {
                    j0++;
                }
                j = j0;
            }
            else {
                int k0 = k - 1;
                while (j < k0 && nums[k0] == nums[k]) {
                    --k0;
                }
                k = k0;
            }
        }
    }

    return closest_target;
}

int main() {
    vector<int> v;
    int ret;

    v = { -1,2,1,-4 };
    ret = threeSumClosest(v, 1);
    printf("%d\n", ret);



    getchar();
    return 0;
}
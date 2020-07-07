#include <stdio.h>
#include <vector>
#include <map>
using namespace std;

// ±©Á¦
vector<vector<int>> threeSum(vector<int>& nums) {
    map<int, bool> m;

    vector<vector<int>> vv;
    for (int i = 0;i < nums.size();i++) {
        for (int j = i + 1;j < nums.size();j++) {
            for (int k = j + 1;k < nums.size();k++) {
                int x = nums[i] * nums[i] + nums[j] * nums[j] + nums[k] * nums[k];
                printf("%d %d %d -> %d\n", nums[i], nums[j], nums[k], x);
                if (nums[i] + nums[j] + nums[k] == 0 && m.find(x) == m.end()) {
                    vv.push_back({ nums[i], nums[j], nums[k] });
                    m[x] = true;
                }
            }
        }
    }

    return vv;
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
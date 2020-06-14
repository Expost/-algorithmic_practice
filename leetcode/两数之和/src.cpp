#include <stdio.h>
#include <vector>
#include <unordered_map>
using namespace std;

// 第一想法，双层遍历
//vector<int> twoSum(vector<int>& nums, int target) {
//    vector<int> v;
//    for (int i = 0; i < nums.size(); i++) {
//        for (int j = i + 1; j < nums.size(); j++) {
//            if (nums[i] + nums[j] == target) {
//                v.push_back(i);
//                v.push_back(j);
//                return v;
//            }
//        }
//    }
//
//    return v;
//}

// 借助hash表，一次遍历
vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> m;
    vector<int> v;
    for (int i = 0; i < nums.size(); i++) {
        int sub_val = target - nums[i];
        if (m.find(sub_val) != m.end()) {
            v.push_back(m[sub_val]);
            v.push_back(i);
            return v;
        }
        else {
            m[nums[i]] = i;
        }
    }

    return v;
}

int main() {
    vector<int> v;
    vector<int> ret;
    v = { 2, 7, 11, 15 };
    ret = twoSum(v, 9);
    printf("%d %d\n", ret[0], ret[1]);



    getchar();
    return 0;
}
#include <stdio.h>
#include <vector>

using namespace std;

// 空间复杂度为O(1)
// 如果取消注释，那么空间复杂度为O(N)
vector<int> productExceptSelf(vector<int>& nums) {
    //vector<int> tangle1(nums.size());
    vector<int> ret(nums.size());
    int num = 1;
    for (int i = 0; i < nums.size();i++) {
        ret[i] = num;
        num *= nums[i];
    }
    
    num = 1;
    for (int i = nums.size() - 1;i >= 0;i--) {
        //tangle1[i] = num;
        ret[i] = ret[i] * num;
        num *= nums[i];
    }

    return ret;
}

int main() {
    vector<int> v;
    vector<int> ret;

    v = { 1,2,3,4 };
    ret = productExceptSelf(v);
    for (auto &itr : ret) {
        printf("%d ", itr);
    }

    getchar();
    return 0;
}
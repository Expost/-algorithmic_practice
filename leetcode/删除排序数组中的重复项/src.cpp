#include <stdio.h>
#include <vector>

using namespace std;

int removeDuplicates(vector<int>& nums) {
    if (nums.empty())return 0;

    int cur = 1;
    for (int i = cur;i < nums.size();) {
        while (i < nums.size() && nums[i] == nums[cur - 1]) { i++; }
        if (i == nums.size()) {
            break;
        }
        else {
            nums[cur] = nums[i];
            cur++;i++;
        }
    }

    return cur;
}

int main() {
    vector<int> v;
    int ret;

    v = { 1,1,1,1,1,1,1,1,1,2,2,2,2 };
    ret = removeDuplicates(v);
    for (int i = 0;i < ret;i++) {
        printf("%d ", v[i]);
    }
    printf("\n");

    v = { 0,0,1,1,1,2,2,3,3,4 };
    ret = removeDuplicates(v);
    for (int i = 0;i < ret;i++) {
        printf("%d ", v[i]);
    }
    printf("\n");


    getchar();
    return 0;
}
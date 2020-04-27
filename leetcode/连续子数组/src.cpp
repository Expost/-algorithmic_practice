#include <stdio.h>
#include <vector>
using namespace std;

#define max(a, b) (((a) > (b)) ? (a) : (b))

int maxSubArray(vector<int>& nums) {
    if (nums.empty()) return 0;
    
    int *data = new int[nums.size()];
    data[0] = nums[0];

    for (int i = 1; i < nums.size(); i++) {
        data[i] = max(data[i - 1], max(data[i - 1] + nums[i], nums[i]));
    }

    return data[nums.size() - 1];
}

int main() {
    vector<int> v = { -2, 1, -3, 4, -1, 2, 1, -5, 4 };
    int val = 0;
    
    val = maxSubArray(v);
    printf("val is %d\n", val);

    getchar();
    return 0;
}
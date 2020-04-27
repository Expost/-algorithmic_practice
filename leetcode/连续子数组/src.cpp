#include <stdio.h>
#include <vector>
using namespace std;

#define max(a, b) (((a) > (b)) ? (a) : (b))

// 垃圾实现，超时，复杂度太高
//int maxSubArray(vector<int>& nums) {
//    if (nums.empty()) return 0;
//    
//    int **data = new int*[nums.size()];
//    for (int i = 0; i < nums.size(); i++) {
//        data[i] = new int[nums.size()];
//        memset(data[i], 0, sizeof(int) * nums.size());
//    }
//
//    int max_num = data[0][0] = nums[0];
//    for (int i = 1; i < nums.size(); i++) {
//        for (int j = 0; j <= i; j++) {
//            data[i][j] = data[i - 1][j] + nums[i];
//            max_num = max(max_num, data[i][j]);
//        }        
//    }
//
//    return max_num;
//}

// 这是最初的实现，但执行有问题，后来看了讨论，发现需要稍微改下
int maxSubArray(vector<int>& nums) {
    if (nums.empty()) return 0;

    int *data = new int[nums.size()];
    int max_data = data[0] = nums[0];
    for (int i = 1; i < nums.size(); i++) {
        data[i] = max(data[i - 1] + nums[i], nums[i]);
        max_data = max(data[i], max_data);
    }

    return max_data;
}


int main() {
    vector<int> v = { -2, 1, -3, 4, -1, 2, 1, -5, 4 };
    int val = 0;
    
    val = maxSubArray(v);
    printf("val is %d\n", val);

    getchar();
    return 0;
}
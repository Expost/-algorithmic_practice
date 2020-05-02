#include <stdio.h>
#include <vector>
using namespace std;

#define max(a, b) (((a) > (b)) ? (a) : (b))

// 经过之前几道题的训练，这道题倒是自己做出来了
// 下面是最基本的想法，当然从空间角度来说，
// 当前状态只与前一个状态有关，因此空间可以节省，这点就不赘述了
//int rob(vector<int>& nums) {
//    int count = nums.size();
//    if (count == 0)return 0;
//    int (*dp)[2] = new int[count][2];
//    dp[0][0] = 0;
//    dp[0][1] = nums[0];
//    for (int i = 1; i < count; i++) {
//        dp[i][0] = max(dp[i - 1][1], dp[i - 1][0]);
//        dp[i][1] = dp[i - 1][0] + nums[i];
//    }
//
//    return max(dp[count - 1][0], dp[count - 1][1]);
//}

// 看了题解，自己实现中的状态是细分了的，实际上再优化一下
// 优化后的状态转移方程为：f[i] = max{ f[i - 1], f[i - 2] + A[i]}，解释如下
// 这里只有一个状态，即天数，而偷与不偷这个状态隐藏在状态转移方程之中。函数的值为当天偷的的最大价值
// 那么我当天偷的最大价值是啥呢？就是昨天偷与今天偷这两个的最大值，昨天偷，说明今天不偷，
// 昨天偷的最大价值就是f[i - 1]，今天偷，昨天肯定不偷，那今天偷的价值就是 f[i - 2] + A[i]，
// 这里面是f[i - 2]的价值，说明是按照前天的价值计算的
// 这样，最终的结果就是f[i]，代码实现如下：

int rob(vector<int>& nums) {
    int count = nums.size();
    if (count == 0)return 0;
    int *dp = new int[count];
    dp[0] = nums[0];
    for (int i = 1; i < count; i++) {        
        if (i == 1) {
            dp[1] = max(dp[0], nums[1]);
            continue;
        }

        dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
    }

    return dp[count - 1];
}
int main() {
    vector<int> v = { 2,7,9,3,1 };
    int ret = 0;
    ret = rob(v);
    printf("ret is %d\n", ret);
    v = { 2,1,1,2 };
    ret = rob(v);
    printf("ret is %d\n", ret);

    getchar();
    return 0;
}
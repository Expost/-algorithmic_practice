#include <stdio.h>
#include <vector>
using namespace std;

#define max(a, b) (((a) > (b)) ? (a) : (b))

// 参考网上的文章，实现如下
int maxProfit(vector<int>& prices) {
    if (prices.empty()) return 0;

    int(*dp)[2] = new int[prices.size()][2];
    dp[0][0] = 0;
    dp[0][1] = -prices[0];

    for (int i = 1; i < prices.size(); i++) {
        dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
        dp[i][1] = max(-prices[i], dp[i - 1][1]);
    }

    return dp[prices.size() - 1][0];
}

// 上面的方式中，可以发现状态转移方程中只使用了前一天的数据，
// 因此可以只使用2个变量存储起来，是的空间效率为O(1)，实现如下
//int maxProfit(vector<int>& prices) {
//    if (prices.empty()) return 0;
//
//    int a = 0;
//    int b = -prices[0];
//    for (int i = 1; i < prices.size(); i++) {
//        a = max(a, b + prices[i]);
//        b = max(-prices[i], b);
//    }
//
//    return a;
//}

int main() {
    int ret = 0;
    vector<int> v1 = { 7,1,5,3,6,4 };
    vector<int> v2 = { 7,6,4,3,1 };
    
    ret = maxProfit(v1);
    printf("ret is %d\n", ret);

    ret = maxProfit(v2);
    printf("ret is %d\n", ret);
    return 0;
}
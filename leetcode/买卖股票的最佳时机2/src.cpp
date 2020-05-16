#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int maxProfit(vector<int>& prices) {
    if (prices.empty()) return 0;
    vector<vector<int>> dp(prices.size(), vector<int>(2));
    dp[0][0] = 0;
    dp[0][1] = -prices[0];
    
    for (int i = 1; i < prices.size(); i++) {
        dp[i][1] = max(dp[i - 1][0] - prices[i], dp[i - 1][1]);
        
        dp[i][0] = max(dp[i - 1][0], prices[i] + dp[i - 1][1]);
    }

    return dp[prices.size() - 1][0];
}

int main() {
    vector<int> v;
    int ret = 0;

    v = { 7, 1, 5, 3, 6, 4 };
    ret = maxProfit(v);
    printf("%d\n", ret);

    v = { 1, 2, 3, 4, 5 };
    ret = maxProfit(v);
    printf("%d\n", ret);

    v = { 7, 6, 4, 3, 1 };
    ret = maxProfit(v);
    printf("%d\n", ret);

    getchar();
    return 0;
}
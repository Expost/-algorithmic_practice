#include <stdio.h>
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <functional>
using namespace std;

// 以下实现错误
//int coinChange(vector<int>& coins, int amount) {
//    sort(coins.begin(), coins.end(), greater<int>());
//    int count = 0;
//    for (int i = 0; i < coins.size() && amount > 0; i++) {
//        while (amount >= coins[i]) {
//            amount -= coins[i];
//            count += 1;
//        }
//    }
//
//    if (amount == 0)return count;
//    else return -1;
//}

// 使用递归，加上备忘录，超时。用同样实现的python测试就没问题。。。。
//int interCoinChange(vector<int>& coins, int amount, map<int, int> &m) {
//    if (amount == 0) {
//        return 0;
//    }
//    else if (amount < 0) {
//        return -1;
//    }
//    if (m.find(amount) != m.end()) return m[amount];
//
//    int count = 0x7fffffff;
//    for (int i = 0; i < coins.size(); i++) {
//        int tmp = interCoinChange(coins, amount - coins[i], m);
//        if (tmp < count && tmp != -1) {
//            count = tmp;
//        }
//    }
//
//    if (count == 0x7fffffff) {
//        m[amount] = -1;
//        return -1;
//    }
//
//    m[amount] = count + 1;
//    return count + 1;
//}
//
//int coinChange(vector<int>& coins, int amount) {
//    map<int, int> m;
//    sort(coins.begin(), coins.end(), greater<int>());
//    return interCoinChange(coins, amount, m);
//}


int interCoinChange(vector<int>& coins, int amount, vector<int> &m) {
    if (amount == 0) {
        return 0;
    }
    else if (amount < 0) {
        return -1;
    }
    if (m[amount] != 0) return m[amount];

    int count = 0x7fffffff;
    for (int i = 0; i < coins.size(); i++) {
        int tmp = interCoinChange(coins, amount - coins[i], m);
        if (tmp < count && tmp != -1) {
            count = tmp;
        }
    }

    if (count == 0x7fffffff) {
        m[amount] = -1;
        return -1;
    }

    m[amount] = count + 1;
    return count + 1;
}

int coinChange(vector<int>& coins, int amount) {
    vector<int> v;
    v.resize(amount + 1);
    
    return interCoinChange(coins, amount, v);
}

// 动态规划
//int coinChange(vector<int>& coins, int amount) {
//    vector<int> dp(amount + 1, amount + 1);
//    dp[0] = 0;
//
//    for (int i = 0; i <= amount; i++) {
//        for (int j = 0; j < coins.size(); j++) {
//            if(coins[j] > i) continue;
//            dp[i] = min(dp[i], dp[i - coins[j]] + 1);
//        }
//    }
//
//    return dp[amount] == amount + 1 ? -1 : dp[amount];
//}



int main() {
    vector<int> v;
    int ret = 0;
    
    v = { 2 };
    ret = coinChange(v, 3);
    printf("%d\n", ret);

    v = { 5,2,1 };
    ret = coinChange(v, 11);
    printf("%d\n", ret);

    v = { 137,38,18,497,97,462,400,119,479,416 };
    ret = coinChange(v, 4605);
    printf("%d\n", ret);

    v = { 186,419,83,408 };
    ret = coinChange(v, 6249);
    printf("%d\n", ret);

    getchar();
    return 0;
}
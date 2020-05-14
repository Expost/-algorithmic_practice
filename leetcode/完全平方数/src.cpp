#include <stdio.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

int numSquares(int n) {
    int count = sqrt(n);
    vector<int> dp(n + 1, n + 1);
    dp[0] = 0;
    for (int i = 0; i <= n; i++) {
        for (int j = 1; j <= count; j++) {
            int value = j * j;
            if(value > i) break;
            dp[i] = min(dp[i], dp[i - value] + 1);
        }
    }

    return dp[n];
}

int main() {
    int ret = 0;
    ret = numSquares(13);
    printf("%d\n", ret);

    getchar();
    return 0;
}

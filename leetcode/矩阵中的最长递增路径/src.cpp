#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

// 以下实现不对，还是用递归吧，好想、好写
//int longestIncreasingPath(vector<vector<int>>& matrix) {
//    int max_len = 0;
//    vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), 1));
//
//    for (int i = 0; i < matrix.size();i++) {
//        for (int j = 0;j < matrix[i].size();j++) {
//            if (j != 0 && matrix[i][j] > matrix[i][j - 1]) {
//                dp[i][j - 1] = max(dp[i][j - 1], dp[i][j] + 1);
//                max_len = max(dp[i][j - 1], max_len);
//            }
//            if (j != matrix[i].size() - 1 && matrix[i][j] > matrix[i][j + 1]) {
//                dp[i][j + 1] = max(dp[i][j + 1], dp[i][j] + 1);
//                max_len = max(dp[i][j + 1], max_len);
//            }
//            if (i != 0 && matrix[i][j] > matrix[i - 1][j]) {
//                dp[i - 1][j] = max(dp[i - 1][j], dp[i][j] + 1);
//                max_len = max(dp[i - 1][j], max_len);
//            }
//            if (i != matrix.size() - 1 && matrix[i][j] > matrix[i + 1][j]) {
//                dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] + 1);
//                max_len = max(dp[i + 1][j], max_len);
//            }
//        }
//    }
//
//    return max_len;
//}

int longestIncreasingPath(vector<vector<int>>& matrix) {

    return 0;
}

int main() {
    int ret = 0;
    vector<vector<int>> vv;

    vv = {
        { 9, 9, 4 },
        { 6, 6, 8 },
        { 2, 1, 1 }
    };

    ret = longestIncreasingPath(vv);
    printf("%d\n", ret);



    vv = {
        { 3, 4, 5 },
        { 3, 2, 6 },
        { 2, 2, 1 }
    };
    ret = longestIncreasingPath(vv);
    printf("%d\n", ret);

    getchar();
    return 0;
}
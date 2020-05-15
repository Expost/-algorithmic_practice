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

// 以下实现超时
void recursive(vector<vector<int>> &matrix, int i, int j, int count, int &max_count, vector<vector<int>> &vv) {
    int tmp = 0;
    if (j != 0 && matrix[i][j] > matrix[i][j - 1]) {
        if (vv[i][j - 1] == 0) {
            tmp = matrix[i][j];
            matrix[i][j] = INT_MAX;
            recursive(matrix, i, j - 1, count + 1, max_count, vv);
            matrix[i][j] = tmp;
        }
        else {
            vv[i][j] = vv[i][j - 1] + 1;
        }
    }
    if (j != matrix[i].size() - 1 && matrix[i][j] > matrix[i][j + 1]) {
        if (vv[i][j + 1] == 0) {
            tmp = matrix[i][j];
            matrix[i][j] = INT_MAX;
            recursive(matrix, i, j + 1, count + 1, max_count, vv);
            matrix[i][j] = tmp;
        }
        else {
            vv[i][j] = vv[i][j + 1] + 1;
        }
    }
    if (i != 0 && matrix[i][j] > matrix[i - 1][j]) {
        if (vv[i - 1][j] == 0) {
            tmp = matrix[i][j];
            matrix[i][j] = INT_MAX;
            recursive(matrix, i - 1, j, count + 1, max_count, vv);
            matrix[i][j] = tmp;
        }
        else {
            vv[i][j] = vv[i - 1][j];
        }
    }
    if (i != matrix.size() - 1 && matrix[i][j] > matrix[i + 1][j]) {
        if (vv[i + 1][j] == 0) {
            tmp = matrix[i][j];
            matrix[i][j] = INT_MAX;
            recursive(matrix, i + 1, j, count + 1, max_count, vv);
            matrix[i][j] = tmp;
        }
        else {
            vv[i][j] = vv[i + 1][j] + 1;
        }
    }

    vv[i][j] = max(vv[i][j], count);
    max_count = max(max_count, count);
}

int longestIncreasingPath(vector<vector<int>>& matrix) {
    int max_count = 0;
    vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), 0));

    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++) {
            recursive(matrix, i, j, 1, max_count, dp);
        }
    }

    return max_count;
}

int main() {
    int ret = 0;
    vector<vector<int>> vv;

    vv = {
        { 3, 4, 5 },
        { 3, 2, 6 },
        { 2, 2, 1 }
    };
    ret = longestIncreasingPath(vv);
    printf("%d\n", ret);

    vv = {
        { 9, 9, 4 },
        { 6, 6, 8 },
        { 2, 1, 1 }
    };

    ret = longestIncreasingPath(vv);
    printf("%d\n", ret);


    vv = { {1} };
    ret = longestIncreasingPath(vv);
    printf("%d\n", ret);



    getchar();
    return 0;
}
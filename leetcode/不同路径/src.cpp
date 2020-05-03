#include <stdio.h>
#include <string.h>

// 第一想法使用回溯，然而超时了，代码需要优化
//void interUniquePaths(int m, int n, int x, int y, int &count) {
//    if (x == m - 1 && y == n - 1) {
//        count += 1;
//        return;
//    }
//
//    if (x < m - 1) {
//        interUniquePaths(m, n, x + 1, y, count);
//    }
//
//    if (y < n - 1) {
//        interUniquePaths(m, n, x, y + 1, count);
//    }
//}
//
//int uniquePaths(int m, int n) {
//    int count = 0;
//    interUniquePaths(m, n, 0, 0, count);
//    return count;
//}


// 这道题依旧是动态规划，所以还是得用动态规划的思路来想
int uniquePaths(int m, int n) {
    int **matrix = new int*[n];
    for (int i = 0; i < n; i++) {
        matrix[i] = new int[m];
        memset(matrix[i], 0, sizeof(int) * m);
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i > 0 && j > 0) {
                matrix[i][j] = matrix[i - 1][j] + matrix[i][j - 1];
            }
            else {
                matrix[i][j] = 1;
            }
        }
    }

    return matrix[n - 1][m - 1];
}


int main() {
    int ret = 0;
    ret = uniquePaths(3, 2);
    printf("%d\n", ret);

    ret = uniquePaths(7, 3);
    printf("%d\n", ret);

    ret = uniquePaths(23, 12);
    printf("%d\n", ret);

    getchar();
    return 0;
}
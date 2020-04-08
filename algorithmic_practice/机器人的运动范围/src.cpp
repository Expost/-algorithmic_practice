#include <stdio.h>
#include <string.h>
#include <memory>

// ����ɵ�ƣ����˰��컭����ͼ����Ϊ�м�϶���ʲô���ɣ����ָо������ƺ�̫������
// ���տ������ۣ����ָ���һ�⣬�����е�·����˼����ȫ��ͬ��������

int cal(int row, int col) {
    int sum = 0;
    while (row != 0) {
        sum += row % 10;
        row /= 10;
    }

    while (col != 0) {
        sum += col % 10;
        col /= 10;
    }

    return sum;
}

int helper(char *matrix, int cur_row, int cur_col, int rows, int cols, int threshold) {
    int index = cur_row * cols + cur_col;
    int val = cal(cur_row, cur_col);

    if (cur_col < 0 || 
        cur_col >= cols || 
        cur_row < 0 || 
        cur_row >= rows || 
        val > threshold ||
        matrix[index] == 1) {
        return 0;
    }

    matrix[index] = 1;
    return 1 +
        helper(matrix, cur_row + 1, cur_col, rows, cols, threshold) +
        helper(matrix, cur_row - 1, cur_col, rows, cols, threshold) +
        helper(matrix, cur_row, cur_col + 1, rows, cols, threshold) +
        helper(matrix, cur_row, cur_col - 1, rows, cols, threshold);
}

int movingCount(int threshold, int rows, int cols)
{
    auto matrix = std::make_unique<char[]>(rows * cols);
    memset(matrix.get(), 0, rows * cols);
    return helper(matrix.get(), 0, 0, rows, cols, threshold);
}

int main() {
    int count = movingCount(4, 10, 10);
    printf("%d\n", count);

    getchar();
    return 0;
}
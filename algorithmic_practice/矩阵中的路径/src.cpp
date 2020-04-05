#include <stdio.h>


bool find(char *matrix, int cur_row, int cur_col, int rows, int cols, char *str) {
    if (*str == 0) {
        return true;
    }

    auto ret = false;
    if (cur_col > 0 && matrix[cur_row * cols + cur_col - 1] == *str) {
        matrix[cur_row * cols + cur_col - 1] = 0;
        ret = find(matrix, cur_row, cur_col - 1, rows, cols, str + 1);
        matrix[cur_row * cols + cur_col - 1] = *str;
        if (ret) return ret;
    }

    if (cur_row > 0 && matrix[(cur_row - 1) * cols + cur_col] == *str) {
        matrix[(cur_row - 1) * cols + cur_col] = 0;
        ret = find(matrix, cur_row - 1, cur_col, rows, cols, str + 1);
        matrix[(cur_row - 1) * cols + cur_col] = *str;
        if (ret) return ret;
    }

    if (cur_col < cols - 1 && matrix[cur_row * cols + cur_col + 1] == *str) {
        matrix[cur_row * cols + cur_col + 1] = 0;
        ret = find(matrix, cur_row, cur_col + 1, rows, cols, str + 1);
        matrix[cur_row * cols + cur_col + 1] = *str;
        if (ret) return ret;
    }

    if (cur_row < rows - 1 && matrix[(cur_row + 1) * cols + cur_col] == *str) {
        matrix[(cur_row + 1) * cols + cur_col] = 0;
        ret = find(matrix, cur_row + 1, cur_col, rows, cols, str + 1);
        matrix[(cur_row + 1) * cols + cur_col] = *str;
        if (ret) return ret;
    }

    return ret;
}

bool hasPath(char* matrix, int rows, int cols, char* str){    
    for(int index = 0; index < rows * cols; index++){
        int cur_row = index / cols;
        int cur_col = index % cols;

        if (*str == matrix[index]) {
            matrix[index] = 0;
            auto ret = find(matrix, cur_row, cur_col, rows, cols, str + 1);
            matrix[index] = *str;
            if (ret) return ret;
        }
    }

    return false;
}

// 看了下讨论，大概思想差不多，只是自己写的太麻烦了,自己的递归不够彻底。
// 使用了原来的数组作为标记，看别的代码都是另申请了一个标志数组，那样的话，不用改原来的数组，
// 改下递归的话，示例如下

bool find_1(char *matrix, int cur_row, int cur_col, int rows, int cols, char *str) {
    int index = cur_row * cols + cur_col;
    if (cur_col < 0 || cur_col >= cols || cur_row < 0 || cur_row >= rows || matrix[index] != *str)
        return false;
    
    if (*(str + 1) == 0) {
        return true;
    }

    matrix[index] = 0;
    if (find_1(matrix, cur_row, cur_col - 1, rows, cols, str + 1) ||
        find_1(matrix, cur_row - 1, cur_col, rows, cols, str + 1) ||
        find_1(matrix, cur_row, cur_col + 1, rows, cols, str + 1) ||
        find_1(matrix, cur_row + 1, cur_col, rows, cols, str + 1))
    {
        return true;
    }

    matrix[index] = *str;
    return false;
}

bool hasPath_1(char* matrix, int rows, int cols, char* str) {
    for (int index = 0; index < rows * cols; index++) {
        int cur_row = index / cols;
        int cur_col = index % cols;

        if (find_1(matrix, cur_row, cur_col, rows, cols, str)) {
            return true;
        }      
    }

    return false;
}


int main() {
    //char matrix[] = {
    //    'a', 'b', 'c', 'e',
    //    's', 'f', 'c', 's',
    //    'a', 'd', 'e', 'e'
    //};

    //char matrix[] = {
    //    'A', 'B', 'C', 'E', 'H', 'J', 'I', 'G',
    //    'S', 'F', 'C', 'S', 'L', 'O', 'P', 'Q',
    //    'A', 'D', 'E', 'E', 'M', 'N', 'O', 'E',
    //    'A', 'D', 'I', 'D', 'E', 'J', 'F', 'M',
    //    'V', 'C', 'E', 'I', 'F', 'G', 'G', 'S'
    //};

    //char matrix[] = {
    //    'A', 'B', 'C', 'E',
    //    'S', 'F', 'C', 'S', 
    //    'A', 'D', 'E', 'E' 
    //};

    char matrix[] = { 'A' };

    auto ret = hasPath_1(matrix, 1, 1, "A");
    printf("%d\n", ret);

    getchar();
    return 0;
}
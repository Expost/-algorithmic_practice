#include <stdio.h>

// 根据提示知道是贪心，但忘记了贪心算法是啥。。。
// 查了下贪心算法，写了下面的代码

int cal(int number, int length) {
    if (length == 1) {
        return number;
    }

    int cur_number = number / length;
    return (cur_number)* cal(number - cur_number, length - 1);
}

int cutRope(int number) {
    int max_value = 0;
    int cut_count = number / 2 > 2 ? number / 2 : 2;
    for (int i = 2; i <= cut_count; i++) {
        int v = cal(number, i);
        if (v < max_value) {
            break;
        }

        max_value = v;
    }

    return max_value;
}

int main() {
    int v = 0;
    v = cutRope(60);
    printf("%d\n", v);

    getchar();
    return 0;
}
#include <stdio.h>
#include <math.h>
// ������ʾ֪����̰�ģ���������̰���㷨��ɶ������
// ������̰���㷨��д������Ĵ���

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

// ���������ۣ����й��ɵģ���ȫ���Բ���̰��

int cutRope_1(int number) {
    if (number == 2) {
        return 1;
    }
    if (number == 3) {
        return 2;
    }

    int x = number / 3;
    int y = number % 3;
    if (y == 0) {
        return pow(3, x);
    }
    if (y == 1) {
        return 2 * 2 * pow(3, x - 1);
    }
    if (y == 2) {
        return 2 * pow(3, x);
    }
}


int main() {
    int v = 0;
    v = cutRope(60);
    printf("%d\n", v);

    getchar();
    return 0;
}
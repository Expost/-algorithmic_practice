#include <stdio.h>
#include <string.h>
// 这道题跟青蛙跳楼梯一样
// 下面这种方法重复运算太多，因此需要优化
//int climbStairs(int n) {
//    if (n == 0) {
//        return 0;
//    }
//
//    if (n == 1) {
//        return 1;
//    }
//
//    if (n == 2) {
//        return 2;
//    }
//
//    return climbStairs(n - 1) + climbStairs(n - 2);
//}

// 优化的第一种方法是将重叠问题进行备份
// 这种方式占的内存比较多
//int interClimbStairs(int *data, int n) {
//    if (data[n] != 0) {
//        return data[n];
//    }
//
//    data[n] = interClimbStairs(data, n - 1) + interClimbStairs(data, n - 2);
//    return data[n];
//}
//
//int climbStairs(int n) {
//    if (n == 0) return 0;
//    if (n == 1) return 1;
//    if (n == 2) return 2;
//
//    int *data = new int[n + 1];
//    memset(data, 0, sizeof(int) * (n + 1));
//    data[1] = 1;
//    data[2] = 2;
//
//    auto value = interClimbStairs(data, n);
//    delete[] data;
//    return value;
//}

// 仔细分析会发现，实际上只有当前状态的前两个状态的值，如果使用迭代由底向上将会容易很多
int climbStairs(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    if (n == 2) return 2;
    
    int a = 1;
    int b = 2;
    int v = 0;
    for (int i = 3; i <= n; i++) {
        v = a + b;
        a = b;
        b = v;
    }

    return v;
}


int main() {
    int ret = 0;
    ret = climbStairs(1);
    printf("ret %d\n", ret);

    ret = climbStairs(3);
    printf("ret %d\n", ret);

    ret = climbStairs(5);
    printf("ret %d\n", ret);

    ret = climbStairs(44);
    printf("ret %d\n", ret);

    return 0;
}
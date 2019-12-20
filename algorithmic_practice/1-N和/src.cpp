#include <stdio.h>

// 因为不让用条件判断，因此最开始把循环加的方式给排除了
// 认为需要通过公式计算出结果，但公式中要使用乘法，依旧没办法解决
// 最终没办法看讨论答案了
// 看完后，感觉很简单,然而自己就是想不起来，通过与逻辑的方式作为终止条件，这样就可以递归计算了
int Sum_Solution(int n) {
    int vv = n;
    vv && (vv += Sum_Solution(n - 1));
    return vv;
}

int main()
{
    auto value = Sum_Solution(100);
    printf("%d\n", value);

    getchar();
    return 0;
}
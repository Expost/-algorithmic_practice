#include <stdio.h>
#include <vector>
using namespace std;

int maxArea(vector<int>& height) {
    int max_v = 0;
    for (int i = 0;i < height.size();i++) {
        for (int j = i + 1;j < height.size();j++) {
            int v = 0;
            if (height[i] < height[j])
                v = height[i] * (j - i);
            else
                v = height[j] * (j - i);

            max_v = v > max_v ? v : max_v;
        }
    }

    return max_v;
}

int main() {
    vector<int> v;
    int ret;

    v = { 1,8,6,2,5,4,8,3,7 };
    ret = maxArea(v);
    printf("%d\n", ret);


    getchar();
    return 0;
}
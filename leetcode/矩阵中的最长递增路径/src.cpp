#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int longestIncreasingPath(vector<vector<int>>& matrix) {


    return 0;
}

int main() {
    int ret = 0;
    vector<vector<int>> vv;
    vv = {
        {9, 9, 4},
        {6, 6, 8},
        {2, 1, 1} 
    };
     
    ret = longestIncreasingPath(vv);
    printf("%d\n", ret);


    vv = {
        {3, 4, 5},
        {3, 2, 6},
        {2, 2, 1}
    };
    ret = longestIncreasingPath(vv);
    printf("%d\n", ret);


    getchar();
    return 0;
}
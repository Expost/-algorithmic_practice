#include <stdio.h>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <unordered_set>
using namespace std;

// 要求时间复杂度为O(N)，显然下面实现不是O(N)，但真的不知道该怎么做啊。。。
// 提交试了下，果然超时，不过我认为超时大概率是map的锅。。。
//int longestConsecutive(vector<int>& nums) {
//    int max_len = 0;
//    unordered_map<int, int> m;
//
//    for (auto &itr : nums) {
//        if(m[itr] == 0)
//            m[itr] = 1 + m[itr - 1] + m[itr + 1];
//
//        int i = 1;
//        while (m[itr - i] != 0) {
//            m[itr - i] = m[itr];
//            i++;
//        }
//        
//        i = 1;
//        while (m[itr + i] != 0) {
//            m[itr + i] = m[itr];
//            i++;
//        }
//            
//        max_len = max(m[itr], max_len);
//    }
//
//    return max_len;
//}

// 看了讨论，下面这个算法，自己实现中耗时的主要原因是因为要把整个连续的序列值摊平，
// 而摊平的过程使用了循环，这也是耗时的主要原因，而下面这个实现中，根据两边存储的值直接定位到边界
// 直接调整边界的值即可。牛逼牛逼
int longestConsecutive(vector<int>& nums) {
    unordered_map<int, int> dp;
    int ret = 0;
    for (auto &x : nums) {
        if (!dp[x]) {
            int value = dp[x - 1] + dp[x + 1] + 1;
            dp[x] = value;
            dp[x - dp[x - 1]] = value;
            dp[x + dp[x + 1]] = value;
        }
        ret = max(ret, dp[x]);
    }

    return ret;
}

// 基于hash表的另外一种实现
int longestConsecutive(vector<int>& nums) {
    unordered_set<int> st;
    for (int n : nums) st.insert(n);
    int ans = 0;
    for (int i : st) {
        // 假如一个数在哈希表中存在比他小的，那么它不是可以作为开头的数字
        if (i != INT_MIN && st.count(i - 1)) {
            continue;
        }
        int cnt = 1;
        while (i != INT_MAX && st.count(i + 1)) {
            cnt++;
            i++;
        }
        ans = max(ans, cnt);
    }
    return ans;
}

int main(){
    vector<int> v;
    int ret = 0;

    v = { 1, 2, 0, 1 };
    ret = longestConsecutive(v);
    printf("%d\n", ret);

    v = { 100, 4, 200, 1, 3, 2 };
    ret = longestConsecutive(v);
    printf("%d\n", ret);

    v = { 100, 4, 200, 1, 3, 2, 5};
    ret = longestConsecutive(v);
    printf("%d\n", ret);

    getchar();
    return 0;
}
#include <stdio.h>
#include <vector>
#include <unordered_map>
#include <algorithm>
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

int longestConsecutive(vector<int>& nums) {

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
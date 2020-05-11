#include <stdio.h>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <unordered_set>
using namespace std;

// Ҫ��ʱ�临�Ӷ�ΪO(N)����Ȼ����ʵ�ֲ���O(N)������Ĳ�֪������ô����������
// �ύ�����£���Ȼ��ʱ����������Ϊ��ʱ�������map�Ĺ�������
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

// �������ۣ���������㷨���Լ�ʵ���к�ʱ����Ҫԭ������ΪҪ����������������ֵ̯ƽ��
// ��̯ƽ�Ĺ���ʹ����ѭ������Ҳ�Ǻ�ʱ����Ҫԭ�򣬶��������ʵ���У��������ߴ洢��ֱֵ�Ӷ�λ���߽�
// ֱ�ӵ����߽��ֵ���ɡ�ţ��ţ��
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

// ����hash�������һ��ʵ��
int longestConsecutive(vector<int>& nums) {
    unordered_set<int> st;
    for (int n : nums) st.insert(n);
    int ans = 0;
    for (int i : st) {
        // ����һ�����ڹ�ϣ���д��ڱ���С�ģ���ô�����ǿ�����Ϊ��ͷ������
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
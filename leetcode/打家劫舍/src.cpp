#include <stdio.h>
#include <vector>
using namespace std;

#define max(a, b) (((a) > (b)) ? (a) : (b))

// ����֮ǰ�������ѵ��������⵹���Լ���������
// ��������������뷨����Ȼ�ӿռ�Ƕ���˵��
// ��ǰ״ֻ̬��ǰһ��״̬�йأ���˿ռ���Խ�ʡ�����Ͳ�׸����
//int rob(vector<int>& nums) {
//    int count = nums.size();
//    if (count == 0)return 0;
//    int (*dp)[2] = new int[count][2];
//    dp[0][0] = 0;
//    dp[0][1] = nums[0];
//    for (int i = 1; i < count; i++) {
//        dp[i][0] = max(dp[i - 1][1], dp[i - 1][0]);
//        dp[i][1] = dp[i - 1][0] + nums[i];
//    }
//
//    return max(dp[count - 1][0], dp[count - 1][1]);
//}

// ������⣬�Լ�ʵ���е�״̬��ϸ���˵ģ�ʵ�������Ż�һ��
// �Ż����״̬ת�Ʒ���Ϊ��f[i] = max{ f[i - 1], f[i - 2] + A[i]}����������
// ����ֻ��һ��״̬������������͵�벻͵���״̬������״̬ת�Ʒ���֮�С�������ֵΪ����͵�ĵ�����ֵ
// ��ô�ҵ���͵������ֵ��ɶ�أ���������͵�����͵�����������ֵ������͵��˵�����첻͵��
// ����͵������ֵ����f[i - 1]������͵������϶���͵���ǽ���͵�ļ�ֵ���� f[i - 2] + A[i]��
// ��������f[i - 2]�ļ�ֵ��˵���ǰ���ǰ��ļ�ֵ�����
// ���������յĽ������f[i]������ʵ�����£�

int rob(vector<int>& nums) {
    int count = nums.size();
    if (count == 0)return 0;
    int *dp = new int[count];
    dp[0] = nums[0];
    for (int i = 1; i < count; i++) {        
        if (i == 1) {
            dp[1] = max(dp[0], nums[1]);
            continue;
        }

        dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
    }

    return dp[count - 1];
}
int main() {
    vector<int> v = { 2,7,9,3,1 };
    int ret = 0;
    ret = rob(v);
    printf("ret is %d\n", ret);
    v = { 2,1,1,2 };
    ret = rob(v);
    printf("ret is %d\n", ret);

    getchar();
    return 0;
}
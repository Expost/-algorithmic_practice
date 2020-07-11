#include <stdio.h>
#include <vector>

using namespace std;

// �ռ临�Ӷ�ΪO(1)
// ���ȡ��ע�ͣ���ô�ռ临�Ӷ�ΪO(N)
vector<int> productExceptSelf(vector<int>& nums) {
    //vector<int> tangle1(nums.size());
    vector<int> ret(nums.size());
    int num = 1;
    for (int i = 0; i < nums.size();i++) {
        ret[i] = num;
        num *= nums[i];
    }
    
    num = 1;
    for (int i = nums.size() - 1;i >= 0;i--) {
        //tangle1[i] = num;
        ret[i] = ret[i] * num;
        num *= nums[i];
    }

    return ret;
}

int main() {
    vector<int> v;
    vector<int> ret;

    v = { 1,2,3,4 };
    ret = productExceptSelf(v);
    for (auto &itr : ret) {
        printf("%d ", itr);
    }

    getchar();
    return 0;
}
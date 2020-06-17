#include <stdio.h>
#include <vector>
using namespace std;


// �ƺ���ʲô���ɣ�������û�뵽�������ķ������ǽ���������ϲ�Ϊ1����������飬����ֱ�ӵõ���λ��
// ������ʱ�临�Ӷ�ΪO(M + N)���ռ临�Ӷ�Ҳͬ��
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int i = 0;
    int j = 0;
    vector<int> v;
    while (i < nums1.size() && j < nums2.size()) {
        if (nums1[i] < nums2[j]) {
            v.push_back(nums1[i]);
            i++;
        }
        else {
            v.push_back(nums2[j]);
            j++;
        }
    }

    while (i < nums1.size()) {
        v.push_back(nums1[i]);
        i++;
    }
    while (j < nums2.size()) {
        v.push_back(nums2[j]);
        j++;
    }

    if (v.size() % 2 == 0) {
        int r = v.size() / 2;
        return (v[r - 1] + v[r]) / 2.0;
    }
    else {
        return v[v.size() / 2];
    }
}

int main() {
    vector<int> nums1;
    vector<int> nums2;
    double ret = 0;

    nums1 = { 1, 3 };
    nums2 = { 2 };
    ret = findMedianSortedArrays(nums1, nums2);
    printf("%f\n", ret);
    
    nums1 = { 1, 2 };
    nums2 = { 3, 4 };
    ret = findMedianSortedArrays(nums1, nums2);
    printf("%f\n", ret);

    getchar();
    return 0;
}
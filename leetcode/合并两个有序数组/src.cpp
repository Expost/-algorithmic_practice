#include <stdio.h>
#include <vector>
using namespace std;

// ø’º‰∏¥‘”∂»£¨O(M + N)
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int i = 0;
    int j = 0;
    vector<int> mn;
    while (i < m && j < n) {
        if (nums1[i] < nums2[j]) {
            mn.push_back(nums1[i]);
            i++;
        }
        else{
            mn.push_back(nums2[j]);
            j++;
        }
    }

    if (i != m) {
        while (i < m) {
            mn.push_back(nums1[i++]);
        }
    }
    if (j != n) {
        while (j < n) {
            mn.push_back(nums2[j++]);
        }
    }

    for (i = 0; i < mn.size(); i++) {
        nums1[i] = mn[i];
    }
}

int main() {
    vector<int> v1;
    vector<int> v2;

    v1 = { 1, 2, 5, 7, 0, 0, 0, 0 };
    v2 = { 3, 4, 7, 8 };
    merge(v1, 4, v2, v2.size());
    for (auto &itr : v1) {
        printf("%d ", itr);
    }
    printf("\n");

    v1 = { 1, 2, 3, 0, 0, 0 };
    v2 = { 2, 5, 6 };
    merge(v1, 3, v2, v2.size());
    for (auto &itr : v1) {
        printf("%d ", itr);
    }
    printf("\n");



    getchar();
    return 0;
}
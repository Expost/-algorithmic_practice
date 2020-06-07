#include <stdio.h>
#include <vector>

using namespace std;

// 时间复杂度为O(logN)，显然要用二分，但细节上要进行一些调整
//int bin_search(vector<int>& nums, int l, int r, int target) {
//    while (l < r) {
//        int mid = (l + r) / 2;
//        if (nums[mid] == target)
//            return mid;
//
//        int ret = bin_search(nums, l, mid, target);
//        if (ret != -1)return ret;
//        return bin_search(nums, mid + 1, r, target);
//
//        if (mid + 1 < r && nums[mid + 1] < nums[mid]) {
//            int ret = bin_search(nums, l, mid + 1, target);
//            if (ret != -1)return ret;
//            return bin_search(nums, mid + 1, r, target);
//        }
//
//        if (mid - 1 >= l && nums[mid - 1] > nums[mid]) {
//            int ret = bin_search(nums, l, mid, target);
//            if (ret != -1)return ret;
//            return bin_search(nums, mid, r, target);
//        }
//
//        if (nums[mid] < target) {
//            l = mid + 1;
//        }
//        else if (nums[mid] > target) {
//            r = mid;
//        }
//    }
//
//    return -1;
//}

// 呃，实现有问题，复杂度略高
//int bin_search(vector<int>& nums, int l, int r, int target) {
//    if (l >= r)return -1;
//    
//    int mid = (l + r) / 2;
//    if (nums[mid] == target)
//        return mid;
//
//    int ret = bin_search(nums, l, mid, target);
//    if (ret != -1)return ret;
//    return bin_search(nums, mid + 1, r, target);
//}

int bin_search(vector<int>& nums, int l, int r, int target) {
    while (l < r) {
        int mid = (l + r) / 2;
        if (nums[mid] == target)
            return mid;

        if (nums[l] < nums[mid]) {
            if (nums[l] <= target && target < nums[mid]) {
                r = mid;
            }
            else {
                l = mid + 1;
            }
        }
        else {
            if (nums[mid] < target && target <= nums[r - 1]) {
                l = mid + 1;
            }
            else {
                r = mid;
            }
        }
    }

    return -1;
}



int search(vector<int>& nums, int target) {
    return bin_search(nums, 0, nums.size(), target);
}

int main() {
    vector<int> v;
    int pos = 0;

    //v = { 0, 1, 2, 3, 4, 5, 6, 7 };
    //pos = search(v, -10);
    //printf("%d\n", pos);

    v = { 4, 5, 6, 7, 0, 1, 2, 3 };
    pos = search(v, 7);
    printf("%d\n", pos);

    v = { 6, 7, 1, 2, 3, 4, 5 };
    pos = search(v, 5);
    printf("%d\n", pos);

    v = { 3, 1 };
    pos = search(v, 1);
    printf("%d\n", pos);



    getchar();
    return 0;
}
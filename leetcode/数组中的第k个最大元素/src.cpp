#include <stdio.h>
#include <vector>
using namespace std;


void quick_sort(vector<int> &nums, int l, int r) {
    if (l < r) {
        int i = l;
        int j = r;
        int tmp = nums[l];
        while (i < j) {
            while (i < j && nums[j] > tmp)j--;
            if (i < j)
                nums[i++] = nums[j];


            while (i < j && nums[i] < tmp)i++;
            if (i < j)
                nums[j--] = nums[i];
        }

        nums[i] = tmp;
        quick_sort(nums, l, i - 1);
        quick_sort(nums, i + 1, r);
    }
}

void adjust(vector<int>& data, int i, int count) {
    int tmp = data[i];
    for (int largest = i * 2 + 1; largest < count; largest = largest * 2 + 1) {
        if (largest != count - 1 && data[largest + 1] > data[largest])
            largest++;

        if (data[largest] > tmp) {
            data[i] = data[largest];
            i = largest;
        }
        else
            break;
    }

    data[i] = tmp;
}

void HeapSort(vector<int>& data, int count, int k) {
    for (int i = count / 2 - 1; i >= 0; i--) {
        adjust(data, i, count);
    }

    for (int i = count - 1, j = 1; i > 0; i--, j++) {
        int tmp = data[0];
        data[0] = data[i];
        data[i] = tmp;

        if (j == k)
            break;

        adjust(data, 0, i);
    }
}

// 这道题说白了就是排序，各种排序算法
int findKthLargest(vector<int>& nums, int k) {
    HeapSort(nums, nums.size(), k);
    return nums[nums.size() - k];
}

int main() {
    vector<int> v;
    int ret = 0;

    v = { 3, 2, 1, 5, 6, 4 };
    ret = findKthLargest(v, 2);
    printf("%d\n", ret);

    getchar();
    return 0;
}
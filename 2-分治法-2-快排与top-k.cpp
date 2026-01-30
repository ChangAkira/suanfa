#include <stdio.h>

int partition(int arr[], int left, int right) {
    int val = arr[left]; // 基准数
    while (left < right) {
        while (left < right && arr[right] >= val) {
            right--;
        }
        if (left < right) {
            arr[left] = arr[right];
            left++;
        }
        while (left < right && arr[left] < val) {
            left++;
        }
        if (left < right) {
            arr[right] = arr[left];
            right++;
        }
    }
    arr[left] = val;
    return left;
}
// 检验用，求topk问题是不需要全部排好序的
/*
void quicksort(int arr[], int left, int right) {
    if (left >= right) {
        return;
    }
    int pivotIndex = partition(arr, left, right);
    quicksort(arr, left, pivotIndex - 1);
    quicksort(arr, pivotIndex + 1, right);
}
*/

int max_select_topk(int arr[], int i, int j, int k, int length) {
    int pivotindex = partition(arr, i, j);
    if (pivotindex == length - k) {
        return pivotindex;
    } else if (pivotindex > length - k) {
        return max_select_topk(arr, i, pivotindex - 1, k, length);
    } else {
        return max_select_topk(arr, pivotindex + 1, j, k, length);
    }
}

int main() {
    int arr[] = {12, 35, 1, 89, 74, 52, 78, 55, 92, 4, 0, 76, 43, 88, 52, 11};
    int k = 10; // 求第10大的元素
    int length = sizeof(arr) / sizeof(arr[0]);
    int value = max_select_topk(arr, 0, length - 1, k, length);
    printf("第%d大的：%d\n", k, arr[value]);
    printf("前%d大的：\n", k);
    for (int k = value; k < length; k++) {
        printf("%d ", arr[k]);
    }
    // quicksort(arr, 0, length - 1); // 检验用，求topk问题是不需要全部排好序的
    // for (int k = 0; k < length; k++) {
    //     printf("%d ", arr[k]);
    // }
    return 0;
}
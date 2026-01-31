// 中位数，偶数个数字时，取中间两个数的平均值
// 有两个升序的数组，长度分别是m和n，求两个数组所有元素的中位数，要求O(log_2n)完成

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

double middleValue(vector<int> &nums1, int length1, vector<int> &nums2,
                   int length2) {
    if (length1 > length2) {
        return middleValue(nums2, length2, nums1, length1);
    }
    int i = 0, j = 0;
    int begin = 0;
    int end = length1;
    int k = (length1 + length2 + 1) / 2; // 算第几个，不算下标
    while (begin <= end) {
        i = (begin + end) / 2;
        // i+j要等于k
        j = k - i;
        if (i > 0 && j < length2 && nums1[i - 1] > nums2[j]) {
            end = i - 1;
        } else if (j > 0 && i < length1 && nums2[j - 1] > nums1[i]) {
            begin = i + 1;
        } else {
            break;
        }
    }

    // num1特别短，而且nums1数组的数字都特别大
    int left = 0;
    if (i == 0) {
        left = nums2[j - 1];
    } else if (j == 0) { // num2特别短
        left = nums1[i - 1];
    } else {
        left = std::max(nums1[i - 1], nums2[j - 1]);
    }
    int right = 0;
    if (i == length1) { // nums1太少而且都特别小
        right = nums2[j];
    } else if (j == length2) {
        right = nums1[i];
    } else {
        right = std::min(nums1[i], nums2[j]);
    }
    // 找到了合适的i和j的值
    if ((length1 + length2) % 2 == 0) {
        return (left + right) * 1.0 / 2;
    } else {
        return left;
    }
}

int main() {
    vector<int> vec1;
    vector<int> vec2;
    for (int i = 0; i < 10; i++) {
        vec1.push_back(rand() % 100);
    }
    for (int i = 0; i < 5; i++) {
        vec2.push_back(rand() % 100);
    }

    vector<int> vec = vec1;
    for (int v : vec2) {
        vec.push_back(v);
    }
    sort(vec.begin(), vec.end());
    for (int v : vec) {
        cout << v << " ";
    }
    cout << endl;

    sort(vec1.begin(), vec1.end());
    sort(vec2.begin(), vec2.end());

    double midval = middleValue(vec1, vec1.size(), vec2, vec2.size());
    cout << "midval:" << midval << endl;

    return 0;
}
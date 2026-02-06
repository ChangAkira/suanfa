// 1,3,5分硬币，给定价值C：11，问组成价值C需要的最少硬币数量

#include <algorithm>
#include <iostream>
using namespace std;

int main() {
    int arr[] = {1, 3, 5};
    int c = 11;

    int length = sizeof(arr) / sizeof(arr[0]);
    sort(arr, arr + length, [](int a, int b) -> bool { return a > b; });

    int idx = 0;
    int cnt = 0; // 记录硬币个数
    while (c > 0) {
        if (c >= arr[idx]) {
            c -= arr[idx];
            cnt++;
        } else {
            idx++;
        }
    }
    cout << cnt << endl;
    return 0;
}
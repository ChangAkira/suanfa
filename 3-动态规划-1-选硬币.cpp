/*
有1、3、5分钱面额的硬币，给定面值11，问组成给定面值所需要的最少硬币数量
贪心算法最契合这个问题。动态规划也可以。

11  1+(10)    3+(8)    5+(6)      子问题为10、8、6
10  1+(9)   3+(7)   5+(5)   子问题为9、7、5
以此类推
*/
#include <stdio.h>
int fun1(int n) { // 不使用dp数组——其实是分治法
    // n为需要面值，返回值为最少需要的硬币数量
    if (n == 1 | n == 3 | n == 5) {
        return 1;
    } else if (n == 2 ||
               n == 4) { // 必须有，否则fun1(2)的时候会减成负数从而死循环
        return 2;
    } else {
        int n1 = fun1(n - 1) + 1; // 选择了一分硬币
        int n3 = fun1(n - 3) + 1; // 选择了一分硬币
        int n5 = fun1(n - 5) + 1; // 选择了一分硬币
        int min = n1;
        if (n3 < min)
            min = n3;
        if (n5 < min)
            min = n5;
        return min;
    }
}
int fun2(int n, int dp[]) {
    // n为需要面值，返回值为最少需要的硬币数量
    if (dp[n] != -1) {
        return dp[n];
    } else {
        int n1 = fun2(n - 1, dp) + 1; // 选择了一分硬币
        int n3 = fun2(n - 3, dp) + 1; // 选择了一分硬币
        int n5 = fun2(n - 5, dp) + 1; // 选择了一分硬币
        int min = n1;
        if (n3 < min)
            min = n3;
        if (n5 < min)
            min = n5;
        dp[n] = min;
        return min;
    }
}

int main() {
    const int n = 11;
    int dp[n + 1];
    // 组成价值为对应下标需要的最少硬币数量，这样就不用重复求解了。赋初值为-1.
    for (int i = 0; i <= n + 1; i++) {
        dp[i] = -1;
    }
    // 已知的一些直接放进去
    dp[1] = 1;
    dp[3] = 1;
    dp[5] = 1;
    dp[2] = 2;
    dp[4] = 2;
    // int num=fun1(n);
    int num = fun2(n, dp);
    printf("%d ", num);
    return 0;
}
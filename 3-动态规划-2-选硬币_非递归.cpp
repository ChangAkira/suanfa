/*

与上一个文件相比，不用递归，自己推导状态转移方程：

dp[0]=0;
dp[1]=1 +dp[1-1]=1;
dp[2]=1+dp[2-1]=1+dp[1]=2;
dp[3]:
    1+dp[3-1]=1+dp[2]=3;
    1+dp[3-3]=1+dp[0]=1;
dp[4]:
    1+dp[4-1]=2;
    1+dp[4-3]=2;
dp[5]:
    1+dp[5-1]=3;
    1+dp[5-3]=3;
    1+dp[5-5]=0;

dp[i]=min(1+dp[i-{1,3,5}]) (i>=1|3|5)
*/

#include <stdio.h>

int main() {
    const int n = 11;
    int v[] = {1, 3, 5};
    int dp[n + 1]; // 12个数下标0-11
    // 组成价值为对应下标需要的最少硬币数量，这样就不用重复求解了。赋初值为-1.
    // for (int i = 0; i < n + 1; i++) {
    //     dp[i] = -1;
    // }
    // dp[0] = 0;
    // int n1 = __INT_MAX__, n2 = __INT_MAX__, n3 = __INT_MAX__;
    // for (int k = 1; k < n + 1; k++) {
    // n1 = __INT_MAX__, n2 = __INT_MAX__, n3 = __INT_MAX__;
    // 记得每次循环重新初始化//如果min=这个max值（不太可能），那么min+1会溢出。最好定义为一个足够大但又不会溢出的数100000
    // if (k >= v[0]) {
    //     n1 = dp[k - v[0]];
    // }
    // if (k >= v[1]) {
    //     n2 = dp[k - v[1]];
    // }
    // if (k >= v[2]) {
    //     n3 = dp[k - v[2]];
    // }
    // int min = n1;
    // if (min > n1)
    //     min = n2;
    // if (min > n3)
    //     min = n3;
    // dp[k] = min + 1;

    // }

    // 不需要这样算min。每次遍历，更小就更新就行了。这样没有写死，硬币面额和数量也可以直接改变了。

    for (int k = 0; k < n + 1; k++) {
        dp[k] = k; // 初始全用1分钱，肯定是最大的.dp[0]=0也设置好了
        for (int j = 0; j < sizeof(v) / sizeof(v[0]); j++) {
            if (k >= v[j] && (1 + dp[k - v[j]]) < dp[k]) {
                dp[k] = 1 + dp[k - v[j]];
            }
        }
    }

    printf("%d ", dp[n]);
    return 0;
}
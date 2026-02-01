// 1,1,2,3,……

#include <stdio.h>
//递归方式
// int func(int n, int dp[]) { // 问第n个斐波那契数列数字
//     if (dp[n] == 0) {
//         int result = func(n - 1, dp) + func(n - 2, dp);
//         dp[n] = result;
//         return result;
//     } else {
//         return dp[n];
//     }
// }

// int main() {
//     int dp[1000] = {0};
//     dp[1] = 1;
//     dp[2] = 1;
//     int num = func(10, dp);
//     printf("%d", num);
//     return 0;
// }

//非递归方式

//dp[1]=1;
//dp[2]=1;
//dp[3]=dp[1]+dp[2]=2;
//dp[4]=dp[3]+dp[2]=3;
//dp[i]=dp[i-1]+dp[i-2];  i>2

int main(){

    const int n=10;
    int dp[n]={0};
    dp[1]=1,dp[2]=1;
    for(int i=3;i<=n;i++){
        dp[i]=dp[i-1]+dp[i-2];
    }
    printf("%d",dp[n]);

    return 0;
}
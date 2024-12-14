#include <bits/stdc++.h>
#define FOR(i, a, b)  for(int i = (a); i < (b); i++)
#define ll long long
#define f first
#define s second
#define pb push_back
using namespace std;


/**
 * 区间dp
 * dp[i][j] 合并i～j的消耗(inclusive)
 * dp[1][n] 就是答案
 * sum[i][j] 元素和，区间i~j
 * 
 * 单个元素合并
 * dp[i][i] = 0
 * 
 * 两个元素合并
 * dp[i][i+1] = dp[i][i] + dp[i+1][i+1] + sum[i][i+1]
 * 
 * 三个元素合并-有两种可能，     先合并后两个，  或者先合并前两个 - 会有不同的结果
 * dp[i][i+2] = min(dp[i][i]+dp[i+1][i+2], dp[i][i+1]+dp[i+2][i+2]) + sum[i][i+2]
 * 
 * 最终的状态转移方程 -- 三轮循环-循环i,j,k
 * dp[i][j] = min(dp[i][k] + dp[k+1][j]) + sum[i][j]; for (i<=k<j)
 * 
 *  */


int mergeStones(vector<int>v) {
    int N = v.size();
    int s[N+1];//前缀和
    for (int i = 1; i <= N; i++) {
        s[i] = v[i-1];
        s[i] += s[i - 1];
    }
    int dp[N+1][N+1];

    for (int len = 2; len <= N; len++) {//先枚举区间长度
        for (int i = 1; i + len - 1 <= N; i++) {//再枚举区间左端点
            int j = i + len - 1; //右端点
            dp[i][j] = 100000000;
            for (int k = i; k < j; k++) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + s[j] - s[i - 1]);
            }
        }
    }
    return dp[1][N];
}
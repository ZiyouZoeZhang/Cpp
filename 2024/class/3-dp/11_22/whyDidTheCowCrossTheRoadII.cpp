//why did the cow cross the road 2

#include <bits/stdc++.h>
#define FOR(i, a, b)  for(int i = (a); i < (b); i++)
#define ll long long
#define f first
#define s second
#define pb push_back
using namespace std;

int dp[1001][1001];

int main (){

    int n; cin>>n;
    vector<int> v1(n+1), v2(n+1);
    //int dp[n+1][n+1];
    memset(dp, 0, sizeof(dp));
    FOR(i, 0, n) cin>>v1[i+1];
    FOR(i, 0, n) cin>>v2[i+1];

    FOR(i, 1, n+1){
        FOR(j, 1, n+1){
            if (abs(v1[i] - v2[j])<=4){
                dp[i][j] = dp[i-1][j-1] + 1;
            } else dp[i][j] = dp[i-1][j-1];
            dp[i][j] = max(dp[i][j], dp[i-1][j]);
            dp[i][j] = max(dp[i][j], dp[i][j-1]);
        }

    }

    cout<<dp[n][n];


    //if differnece between i & j <4, 
    /**
     * if differnece between i and j <= 4,
     * then dp[i][j] = dp[i-1][j-1] + 1
     * else 
     * dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
     */
}
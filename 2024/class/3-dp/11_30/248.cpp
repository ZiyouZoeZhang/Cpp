

#include <bits/stdc++.h>
#define FOR(i, a, b)  for(int i = (a); i < (b); i++)
#define ll long long
#define f first
#define s second
#define pb push_back
using namespace std;


int main (){
    int n; cin>>n;
    int dp[n][n];
    memset(dp, -1, sizeof(dp));

    int v[n];
    int ans = 0;
    FOR(i, 0, n) cin>>v[i], dp[i][i] = v[i];

    FOR(i, 0, n){
        FOR(j, 0, n){
            if (i==j) dp[i][j] = v[i];
            FOR(k, 0, n){
                if (dp[i][k]!=-1 and dp[i][k] == dp[k+1][j]){
                    dp[i][j] = dp[i][k] + 1;
                }
            }
            ans = max(ans, dp[i][j]);
        }
        
    }

    cout<<ans<<endl;
}
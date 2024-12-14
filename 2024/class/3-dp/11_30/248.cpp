#include<bits/stdc++.h>
using namespace std;

int dp[300][300]; //dp[i][j] : 从[i,j]内能够获得的最大整数值
int n;
int a[300];
int maxx = INT_MIN;
int ans = 0;

int main(void){

    cin >> n;
    for(int i = 0 ; i < n ; i++){
        cin >> a[i];
        ans = max(ans,a[i]);
    }

    for(int i = 0; i < n ; i++){
        dp[i][i] = a[i];
    }


    for(int len = 2; len <= n ; len++){ //len是区间的长度
        for(int i = 0 ; i <= n-len; i++){ //i是区间的起点
            int j = i + len - 1; //j是区间的终点
            for(int k = i ; k < j ; k++){
                if(dp[i][k] == dp[k+1][j] and dp[i][k]!= 0){
                    dp[i][j] = max(dp[i][j],dp[i][k] + 1);
                }
            }
            ans = max(ans, dp[i][j]);
        }
    }

/*
    for(int i = 0; i < n ; i++){ //i是区间的起点
        for(int j = i+1 ; j < n; j++){ //i是区间的终点
            for(int k = i ; k < j ; k++){
                if(dp[i][k] == dp[k+1][j] and dp[i][k]!= 0){
                    dp[i][j] = max(dp[i][j],dp[i][k] + 1);
                }
            }
            ans = max(ans, dp[i][j]);
        }
    }
*/

    // for(int i = 0 ; i < n ; i++){
    //     for(int j = 0 ; j < n ; j++){
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    cout << ans << endl;


   return 0;
}
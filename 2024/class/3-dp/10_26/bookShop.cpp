//https://cses.fi/problemset/task/1158/
#include<bits/stdc++.h>
#define FOR(i, a, b)  for(ll i = (a); i < (b); i++)
#define ll long long
#define pb push_back
#define s second
#define f first
using namespace std;
//values too large sometimes



int knapsack01(){
    //排序-容量从小到大

    int N, C; //N- items; C - time

    cin>>N>>C;

    int weight[N+1];
    int value[N+1];
    int dp[N+1][C+1];

    memset(dp, 0, sizeof(dp));

    FOR(i, 1, N+1){
        //cin>>weight[i]>>value[i];
        cin>>value[i]>>weight[i];
    }

    for(int i=1; i<=N; i++){
        for(int j=1; j<=C; j++){
            if (j < weight[i]){ //j=current storage place, weight[i]=weight of ith iteam
                dp[i][j] = dp[i-1][j];
            } else {
                dp[i][j] = max(dp[i-1][j], value[i]+dp[i-1][j-weight[i]]);
            }
        }
    }

    return dp[N][C];
}

int main(){

    cout<<knapsack01()<<endl;
    return 0;

}

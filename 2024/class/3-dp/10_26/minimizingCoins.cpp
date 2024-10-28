#include<bits/stdc++.h>
#define FOR(i, a, b)  for(ll i = (a); i < (b); i++)
#define ll long long
#define pb push_back
#define s second
#define f first
using namespace std;

int main(){

}

void knapsackfull(){
    int N, C; //count, limit;

    cin>>N>>C;

    FOR(i, 1, N+1){
        cin>>weight[i]
    }

    int weight[N+1];
    int value[N+1];
    int dp[C+1];
    
    //knapsack full
    //假设有N个物品，要求在总重量不超过W的情况下的最大价值
    for (int i=1; i<=N; i++){
        for (int j=weight[i]; j<=C; j++){
            dp[j] = max(dp[j], value[i] + dp[j-weight[i]]);
        }
    }

}
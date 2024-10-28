//dp

#include<bits/stdc++.h>
using namespace std;

//0-1 knapsack

int main(){
    




    
}



void knapsack01(){
    //排序-容量从小到大
    int N, C;
    int weight[N+1];
    int value[N+1];
    int dp[N+1][C+1];
    

    for(int i=1; i<=N; i++){
        for(int j=1; j<=C; j++){
            if (j < weight[i]){ //j=current storage place, weight[i]=weight of ith iteam
                dp[i][j] = dp[i-1][j];
            } else {
                dp[i][j] = max(dp[i-1][j], value[i]+dp[i-1][j-weight[i]]);
            }
        }
    }
}

void knapsackfull(){
    int N, C;
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
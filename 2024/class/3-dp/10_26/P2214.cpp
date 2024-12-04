#include <bits/stdc++.h>
#define FOR(i, a, b)  for(ll i = (a); i < (b); i++)
#define ll long long
#define pb push_back
using namespace std;

int n, b, v[10010], coin[10010], a[10010];

int main (){
    cin>>n>>b;
    FOR(i, 0, b) cin>>coin[i];
    FOR(i, 0, n) cin>>v[i];
    int sum = 0;
    FOR(i, 0, n){
        a[i] = v[i] - sum;
        sum = v[i]-1;
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

/*#include<iostream>
#include<cstring>
#define int long long
using namespace std;
int n,m,ans,dp[1000005],cows[20005],c[10005],r[10005];
signed main(){
 cin>>n>>m;
 for(int i=1;i<=1000000;i++) dp[i]=2147483647;
 for(int i=1;i<=m;i++){
  cin>>cows[i];
  dp[cows[i]]=1;
 }
 for(int i=1;i<=n;i++){
  cin>>c[i];
  if(c[i]<c[i-1]-1){//如果存在负牛 
   cout<<-1;
   return 0;
  }
  r[i]=c[i]-max((long long)0,c[i-1]-1);
 }
 for(int i=1;i<=m;i++){
  for(int j=1;j<=100000;j++){
   if(j<=cows[i]) continue;//音量j比奶牛i对应的音量还要小就不能被更新 
   dp[j]=min(dp[j],dp[j-cows[i]]+dp[cows[i]]);
  }
 }
 for(int i=1;i<=n;i++){
  if(r[i]==0) continue;
  if(dp[r[i]]==2147483647){//音量不可达 
   cout<<-1;
   return 0;
  }
  ans+=dp[r[i]];
 }
 cout<<ans;
 return 0;
}
*/
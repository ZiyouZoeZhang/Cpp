#include<bits/stdc++.h>
using namespace std;

int n,a[10005],dp[10005][10005];
int main(){
 cin>>n;
 for(int i=1;i<=n;i++)
 {
  cin>>a[i];
 }
 for(int i=1;i<=n;i++)
 {
  dp[i][i]=1;
 }
 for(int len=2;len<=n;len++){
  for(int i=1;i<=n-len+1;i++)
  {
   int j=i+len-1;
   dp[i][j]=1e+9;
   if(a[i]==a[j])
   {
    dp[i][j]=dp[i][j-1];
   }
    for(int k=i;k<j;k++)
    {
     dp[i][j]=min(dp[i][k]+dp[k+1][j],dp[i][j]);
    }
  }
 }
 cout<<dp[1][n]; 
}
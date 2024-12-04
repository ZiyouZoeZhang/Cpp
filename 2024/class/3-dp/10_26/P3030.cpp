//https://www.luogu.com.cn/problem/P3030
//tile exchanging
#include<bits/stdc++.h>
using namespace std;

int N,M;
int A[11];
int dp[11][10001];

int main(void){
 //ifstream fin("tilechng\\I.7");
 //ofstream fout("tilechng.out");
 cin >> N >>M;

 for(int i=1;i<=N;i++){
  cin >> A[i];
 }
 
 for(int i=0;i<=N;i++){
  dp[i][0] = INT_MAX;
 }
 for(int i=0;i<=M;i++){
  dp[0][i] = INT_MAX;
 }

    dp[0][0] = 0;

 for(int i=1;i<=N;i++){
  for(int j=1; j<=M;j++){
   dp[i][j] = INT_MAX;
   for(int k=1;k*k<=j;k++){
    if( dp[i-1][j-k*k]  != INT_MAX){
        dp[i][j] = min(dp[i][j] , dp[i-1][j-k*k] + (A[i] - k) *(A[i] - k));
    }
   }
  }
 }
 if(dp[N][M]!=INT_MAX)
 cout << dp[N][M] << endl;
 else 
 cout << -1 <<endl;
 //fout << dp[N][M] << endl;
 //fout.close();
 return 0;
}
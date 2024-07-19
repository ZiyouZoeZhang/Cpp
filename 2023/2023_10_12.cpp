//01背包plus

#include<iostream>
#include<vector>
using namespace std;

vector<long long> cost;
vector<long long> win;
vector<long long> lose;
vector<vector<long long> > dp;

int main(){
    long long x, n, c,w,l; //c=药的数量, n=number of things, cost, win, lose
    cin >>n>>x;
    
    if (n==0){
        cout<<0<<endl;
        return 0;
    }

    cost.resize(n);
    win.resize(n);
    lose.resize(n);
    dp.resize(n + 1, vector<long long>(x + 1, 0));

    for (long long i = 0; i < n; ++i) {
        cin >> lose[i] >> win[i] >> cost[i];
    }
    
    for (long long i=1; i<=n; ++i) {
        for (long long j=0; j<=x; ++j) {
            if (cost[i-1]>j || lose[i-1]>=win[i-1]) { //要么装不下，要么不值得
                dp[i][j] = dp[i-1][j]  +  lose[i-1]; // Cannot include the item
            } else {
                dp[i][j] = max(dp[i-1][j] + lose[i-1], win[i-1] + dp[i-1][j-cost[i-1]]); // Maximum of including or excluding the item
            }
        }
    }
    cout<<dp[n][x] * 5<<endl; // Maximum value that can be obtained
    return 0;
}
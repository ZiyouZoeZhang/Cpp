//https://www.luogu.com.cn/problem/P1434
//滑雪
//wrote during class
#include <bits/stdc++.h>
#define FOR(i, a, b)  for(ll i = (a); i < (b); i++)
#define ll long long
#define pb push_back
using namespace std;

int f[105][105];
int a[105][105];
int n, m, ans;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};


int dp(int x, int y){
    if (f[x][y]) return f[x][y];
    int sum = 0;
    FOR(i, 0, 4){
        if (x+dx[i]>0 && y+dy[i]>0){
            if (a[x+dx[i]][y+dy[i] > a[x][y]]) sum = max (sum, dp(x+dx[i], y+dy[i]));
        }
    }
}


int main (){
    cin>>n>>m;
    FOR (i, 1, n+1){
        FOR (j, 1, m+1){
            cin>>a[i][j];
        }
    }

    FOR (i, 1, n+1){
        FOR (j, 1, m+1){
            if (f[i][j]==0) f[i][j] = dp(i, j);
            ans = max(ans, f[i][j]);
        }
    }

    cout<<ans<<endl;

}

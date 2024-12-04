#include <bits/stdc++.h>
using namespace std;

//dp[天数][城市ID] = 最大收益
//dp[k][j] = dp[i-1][k] + cal[j], 其中k是j的父节点

int n, m, c;

int main (){
    cin>>n>>m>>c;
    int val[n+1];
    vector <int> v[n+1];

    for (int i=0; i<n; i++){
        cin>>val[i];
    }
    for (int i=0; i<m; i++){
        int a, b; cin>>a>>b;
        v[a].push_back(b);
    }





}
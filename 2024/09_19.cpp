//https://codeforces.com/contest/839/problem/C
//C. journey

#include <bits/stdc++.h>
#include <vector>
#define FOR(i, a, b)  for(ll i = (a); i < (b); i++)
#define ll long long
#define pb push_back
using namespace std;

int n;
vector<int> adj[100010];
double ans[100010];
bool vis[100010];

void dfs(int u){
    vis[u] = true;
    double total = 0, c = 0;
    for (auto v: adj[u]){
        if (!vis[v]){
            dfs(v);
            total += ans[v]+1; c++;
        }
    }
    if (c==0) ans[u] = 0;
    else ans[u] = total/c;
    return;
}

int main (){

    //cout<<"hello world"<<endl;


    memset(vis, false, sizeof(vis));
    memset(ans, 0, sizeof(ans));
    cin>>n;
    FOR(i, 0, n-1){
        int u, v; cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    dfs(1);

    //f (n==2000) cout<<adj[1].size()<<endl;
    cout<<setprecision(15)<<ans[1]<<endl;
}
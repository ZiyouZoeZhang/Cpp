//https://cses.fi/problemset/task/1678/

#include <bits/stdc++.h>
#define FOR(i, a, b)  for(int i = (a); i < (b); i++)
#define pb push_back
using namespace std;

vector<int> adj[100010];
vector<int> pre;
vector<int> vis;
stack <int> cyl;

void dfs(int u){
    vis[u] = 1;
    for (auto v: adj[u]){
        if (vis[v] == 1){
            cyl.push(u);
            while (cyl.top()!=v){
                cyl.push(pre[cyl.top()]);
            }
            cyl.push(u);
            cout<<cyl.size()<<endl;
            while(!cyl.empty()) {
                cout<<cyl.top()+1<<" "; cyl.pop();
            }
            exit(0);

        } else if (vis[v] == 0) {
            pre[v] = u;
            dfs(v);
        }
    }
    vis[u] = 2;
}

int main (){
    int n, m;

    cin>>n>>m;
    vis.resize(n, 0);
    pre.resize(n);

    FOR (i, 0, n) pre[i] = i;

    FOR (i, 0, m) {
        int a, b;
        cin>>a>>b;
        adj[--a].pb(--b);
    }

    FOR(i, 0, n){
        if (!vis[i]) dfs(i);
    }

    cout<<"IMPOSSIBLE"<<endl;

    return 0;
}

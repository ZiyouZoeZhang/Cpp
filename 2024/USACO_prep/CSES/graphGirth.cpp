#include <bits/stdc++.h>
using namespace std;
int n, m;
int num[2510];
bool vis[2510];
vector<int> adj[2510];

int main (){
    cin>>n>>m;
    for (int i=0; i<m; i++){
        int a, b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (int i=0; i<n; i++){
        dfs(i);

    }


}

int dfs(int x){
    //if (vis[x]) return 0;

    if (adj[x].size()==0) return -1;
    //if (vis[x]) return 1;
    int c = 0x3f3f3f3f;
    for (auto b: adj[x]){
        num[b] = min(num[b], dfs(x)+1);
        c = min(c, num[b]);
    }
    vis[x] = true;
    return c;
}
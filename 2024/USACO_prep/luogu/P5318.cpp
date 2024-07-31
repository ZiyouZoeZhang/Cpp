//https://www.luogu.com.cn/problem/P5318
#include<bits/stdc++.h>
using namespace std;

vector<int> adj[100010];
vector<bool> vis(100010, false);

int N, M;

void dfs(int i){
    if (vis[i]) {return;}
    vis[i] = true;
    cout<<i<<" ";
    for (auto j: adj[i]) dfs(j);
}

void bfs (int i){
    queue<int> q;
    q.push(i);

    while (!q.empty()){
        int a = q.front(); q.pop();
        if (vis[a]) continue;
        vis[a] = true;
        cout<<a<<" ";
        for (auto b: adj[a]){
            q.push(b);
        }
    }
}

int main (){
    cin>>N>>M;
    for (int i=0; i<M; i++){
        int a, b;
        cin>>a>>b;
        adj[a].push_back(b);
    }

    for (int i=0; i<=N; i++){
        sort(adj[i].begin(), adj[i].end());
    }

    dfs(1);
    cout<<endl;
    for (int i=0; i<=N; i++) vis[i] = false;
    bfs(1);
    cout<<endl;

    return 0;
}
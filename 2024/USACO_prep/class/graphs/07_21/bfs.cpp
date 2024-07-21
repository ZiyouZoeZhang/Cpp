#include <bits/stdc++.h>
using namespace std;
vector<int> adj[10010];
bool visited[100010];
int dist[100010];
int n, m;

void bfs(int x){
    cout<<"222";
    queue<int> q;
    dist[x]=1;
    q.push(x);
    while (!q.empty()){
        int a=q.front(); q.pop();
        if (visited[a]) continue;
        visited[a]=true;
        for (auto b: adj[a]){
            q.push(b);
            dist[b]=dist[a]+1;
        }
    }
    return;
}

int main(){
    //memset(dist, 0x3f3f3f3f, 100010);
    cin>>n>>m;
    for (int i=0; i<m; i++){
        int a, b;
        cin>>a>>b;
        adj[a].push_back(b);
    }
    cout<<"hello";
    bfs(0);

    return 0;
}
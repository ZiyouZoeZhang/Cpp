#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
vector<int> adj[200010];
bool visited[200010];
int dist[200010];
//int parent[200010];
int n, m;

void bfs(int x){
    queue<int> q;
    dist[x]=1;
    q.push(x);
    while (!q.empty()){
        int a=q.front(); q.pop();
        if (visited[a]) continue;
        visited[a]=true;
        for (auto b: adj[a]){
            q.push(b);
            //if (dist[a]+1<dist[b]){
                //dist[b]=dist[a]+1;
                //parent[b]=a;
            //}
            
        }
    }
}

int main(){
    memset(dist, INF, 200010);
    //memset(parent, INF, 200010);
    //updated
    cin>>n>>m;
    for (int i=0; i<m; i++){
        int a, b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    bfs(1);
    
    cout<<dist[n]<<endl;

/*
    while (parent[n]!=INF){
        cout<<parent[n];
        n=parent[n];
    }
   */

}


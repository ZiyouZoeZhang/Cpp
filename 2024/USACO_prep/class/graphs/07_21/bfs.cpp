#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define ll long long
using namespace std;

vector<int> adj[200010];
bool visited[200010];
int dist[200010];
int parent[200010];
int n, m;

void bfs(int x){
    queue<int> q;
    dist[x]=1;
    q.push(x);
    while (!q.empty()){
        int a=q.front(); q.pop();
        for (auto b: adj[a]){
            if (visited[b]) continue;
            visited[b]=true;
            dist[b]=dist[a]+1;
            parent[b]=a;
            q.push(b);
        }
    }
}

int main(){
    memset(dist, INF, sizeof(dist));
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

    if (dist[n]==INF){
        cout<<"IMPOSSIBLE"<<endl; 
        return 0;
    }
    
    cout<<dist[n]<<endl;

    stack<int> s;
    
    while (n!=INF){
        s.push(n);
        n=parent[n];
    }

    while (!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }

}


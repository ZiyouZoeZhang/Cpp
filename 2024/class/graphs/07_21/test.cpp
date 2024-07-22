#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
long long dist [100010];
int processed [10010];
vector<pair<int, int>> adj [200001];
int n, m;

void dijkstra (int x){
    //memset(dist, 0x3f, sizeof (dist));
    priority_queue<pair<long long, int>>q;
    dist [x]=0;
    q.push({0, x});

    while (!q.empty()){
        auto elements = q.top();
        int a = elements.second;
        q.pop();

        if (processed[a]==1){
            continue;
        }

        processed[a] = 1;

        for (auto i:adj[a]){
            int u= i.first;
            long long b=i.second;
            if (dist[a]+b<dist[u]){
                dist[u]=dist[a]+b;
                q.push({-dist[u], u});
            }
        }
    }
}

int main (void){
    cin>>n>>m;
    for (int i=1; i<=m; i++){
        int a, b, c;
        cin>>a>>b>>c;
        adj[a].push_back({b, c});
    }

    dijkstra(1);
    for (int i=1; i<= n; i++){
        cout<<dist[i]<<" ";
    }
}
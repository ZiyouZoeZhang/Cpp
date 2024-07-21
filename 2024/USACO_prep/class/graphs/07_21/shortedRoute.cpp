#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
long long dist [100010];
int processed [10010];
vector<pair<int, int>> adj [200001];
int n, m;

void  dijkastra (int x){
    memset (dist, 0x3f, sizeof(dist));
    priority_queue<pair<long, long>>q;
    dist[x] = 0;
    q.push({0,x});
    while (!q.empty()) {
        int a = q.top().second; q.pop();
        if (processed[a]) continue;
        processed[a] = true;
        for (auto u : adj[a]) {
            int b = u.first, w = u.second;
            if (dist[a]+w < dist[b]) {
                dist[b] = dist[a]+w;
                q.push({-dist[b],b});
            }
        }
    }
}

int main(){
    cin>>n>>m;

    for(int i = 0 ; i < 100010; i++){
        dist[i] = 0x3f3f3f3f;
    }

    while (m-->0) {
        int a, b, w;
        cin >> a >> b >> w;
        adj[a].push_back(make_pair(w, b));
    }

    dijkastra(1);

    for (int i=1; i<n-1; i++){
        //if (dist[i]!=INF) 
        cout<< dist[i]<<" ";
    }

    return 0;

}




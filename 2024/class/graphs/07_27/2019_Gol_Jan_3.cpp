#include<bits/stdc++.h>
#define INF 0x3f3f3f3f
#define s second
#define f first
#define ll long long
using namespace std;

ofstream fout ("shortcut.out");
ifstream fin ("shortcut.in");

int main (){
    int N, M, K;
    fin>>N>>M>>K;
    vector<int> iniCows(N+1);
    for (int i=1; i<N+1; i++) fin>>iniCows[i];

    vector<vector<pair<int, int>>> adj (N+1); //time, node
    vector<int> dist (N+1, INF);
    vector<bool> vis(N+1, false);
    vector<int> parent(N+1, INF);
    for (int i=0; i<M; i++){
        int a, b, w;
        fin>>a>>b>>w;
        adj[a].push_back({w, b});
        adj[b].push_back({w, a});
    }

    for (int i=0; i<N+1; i++){
        sort(adj[i].begin(), adj[i].end());
    }

    priority_queue<pair<int, int>>pq;
    pq.push({0, 1});
    dist[1]=0;

    while (!pq.empty()){
        int a = pq.top().s, aw = pq.top().f; pq.pop();

        if (vis[a]) continue;
        vis[a] = true;

        for (auto i: adj[a]){
            int b= i.s, w = i.f;
            if (aw + w < dist[b]){
                dist[b] = aw+w;
                parent[b] = a;
                pq.push({dist[b], b});
            } else if (aw + w == dist[b] && a < parent[b]){
                parent[b] = a;
                pq.push({dist[b], b});
            }
        }
    }

    //now backtrack
    vector<ll> cow (N+1, 0);

    for (int i=1; i<N+1; i++){ //parent
        int cur = i;
        while(cur != INF){
            cow[cur] += iniCows[i];
            cur = parent[cur];
        }
    }

    ll maximum = 0;
    for (int i=1; i<N+1; i++){
        maximum = max(maximum, (cow[i] * (dist[i] - K)));
    }

    fout<<maximum<<endl;
    return 0;

}
//https://www.luogu.com.cn/problem/P5201
//done!!!
#include<bits/stdc++.h>
#define INF 0x3f3f3f3f
#define s second
#define f first
#define ll long long
using namespace std;

//ofstream fout ("shortcut.out");
//ifstream fin ("shortcut.in");

int main (){
    int N, M, K;
    cin>>N>>M>>K;
    vector<int> iniCows(N);
    for (int i=0; i<N; i++) cin>>iniCows[i];

    vector<vector<pair<int, int>>> adj (N); //time, node
    vector<int> dist (N, INF);
    vector<bool> vis(N, false);
    vector<int> parent(N, INF);

    for (int i=0; i<M; i++){
        int a, b, w;
        cin>>a>>b>>w;
        adj[--a].push_back({w, --b});
        adj[b].push_back({w, a});
    }

    for (int i=0; i<N; i++){
        sort(adj[i].begin(), adj[i].end());
    }


    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq; //what is this??
    pq.push({0, 0});
    dist[0]=0;

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
    vector<ll> cow (N);

    for (int i=0; i<N; i++){ //parent
        int cur = i;
        while(cur != INF){
            cow[cur] += iniCows[i];
            cur = parent[cur];
        }
    }

    ll maximum = 0;
    for (int i=0; i<N; i++){
        maximum = max(maximum, (cow[i] * (dist[i] - K)));
    }

    cout<<maximum<<endl;
    return 0;

}
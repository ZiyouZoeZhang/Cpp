//https://usaco.org/index.php?page=viewproblem2&cpid=861
#include<bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3f
using namespace std;

ofstream fout ("dining.out");
ifstream fin ("dining.in");

vector<pair<int, int>> adj [50010]; //b, w
int N, M, K;

vector<ll> dij(int x){
    priority_queue<pair<int, int>> q;
    vector<bool> vis(50010, false);
    vector<ll> dist(100010, INFL);

    dist[x]=0;
    q.push(make_pair(0, x));
    
    while (!q.empty()){
        int a = q.top().second; q.pop();
        if (vis[a]) continue;
        vis[a]=true;
        for (auto i: adj[a]){
            int b=i.first, w=i.second;
            dist[b] = min (dist[b], dist[a]+w);
            q.push(make_pair(-dist[b], b));
        }
    }
    return dist;
}

int main (){
    cin>>N>>M>>K;

    for (int i=0; i<M; i++){
        int a, b, c;
        cin>>a>>b>>c;
        adj[a].push_back(make_pair(b,c));
        adj[b].push_back(make_pair(a,c));
    }

    vector<ll> disA  = dij(N);

    for (int i=0; i<K; i++) {
        int a, w;
        cin>>a>>w;
        adj[N+1].push_back(make_pair(a, disA[a]-w));
    }

    vector<ll> disB = dij(N+1);

    for (int i=1; i<N; i++){
        if (disB[i]<=disA[i]) cout<<1<<endl;
        else cout<<0<<endl;
    }

    return 0;
}
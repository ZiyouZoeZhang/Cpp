//https://usaco.org/index.php?page=viewproblem2&cpid=969&lang=en
#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;

ofstream fout ("pump.out");
ifstream fin ("pump.in");

struct pipe {
    int b; //connnected to
    int c; //cost
    float f; //flow rate
};

vector<pipe> adj[1010];
int N, M;

vector<int> dij(int flow){
    vector<int> dist(N+1, INF);
    vector<bool> vis(N+1, false);
    priority_queue<pair<int, int>> pq;

    dist[1]=0;
    pq.push(make_pair(0,1));

    while(!pq.empty()){
        int a=pq.top().second; pq.pop();
        if (vis[a]) continue;
        vis[a]=true;
        for (auto p: adj[a]){
            if (p.f>=flow){
                dist[p.b] = min(dist[a] + p.c, dist[p.b]);
                pq.push(make_pair(-dist[p.b], p.b));
            }
        }
    }
    return dist;
}

int main (){

    fin>>N>>M;
    for (int i=0; i<M; i++){
        int a, b, c, f;
        fin>>a>>b>>c>>f;
        pipe p; p.b=b; p.c=c; p.f=f;
        adj[a].push_back(p);
        p.b=a; adj[b].push_back(p);
    }

    float high = 0;
    for (int a=1; a<=N; a++){
        for (auto p: adj[a]){
            //p.b, p.c, p.f
            vector<int> dist = dij(p.f);
            if(dist[N]!= INF && p.f/dist[N]>high) high = p.f/dist[N];       
        }
    }

    fout<<int(high*1000000)<<endl;

    return 0;
}
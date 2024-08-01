//https://cses.fi/problemset/task/1202
// 50 %

#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define INFl 0x3f3f3f3f3f3f3f3f
#define f first
#define s second
#define ll long long
using namespace std;

vector<bool> vis(100010, false); //updates when visiting child nodes
vector<pair<int, ll>> adj[100010]; //node, dist
vector<pair<ll, ll>> dist(100010, pair<ll, ll>({INFl, 0})); //dist, count of that distance
vector<int> mx(100010, 0); //maximum # of flights
vector<int> mi(100010, INF); //minimum # of flights

ll N, M;

void dij(int i){
    priority_queue<pair<int, int>> pq; //dist, val
    pq.push({0, 0});
    dist[i] = {0, 1};
    mi[0] = 0;
    mx[0] = 0;

    while (!pq.empty()){
        int a = pq.top().s; pq.pop();
        if (vis[a]) {continue;}
        vis[a] = true;
        for (auto i: adj[a]) {
            int b= i.f, w = i.s; //node, weighten (dist)
            if (dist[b].f >  dist[a].f+w){ //if distance needs to be updated
                dist[b] = {dist[a].f+(ll)w, dist[a].s}; //update distane, count
                mi[b] = mi[a]+1;
                mx[b] = mx[a]+1;
            } else if (dist[b].f  == dist[a].f+w){ //if distance stays the same
                dist[b].s += dist[a].s;
                mi[b] = min(mi[b], mi[a]+1);
                mx[b] = max(mx[b], mx[a]+1);
            } 
            pq.push({-dist[b].f, b});
        }
    }
    return;
}

int main (){
    cin>>N>>M;

    for (ll i=0; i<M; i++){
        ll a, b, c;
        cin>>a>>b>>c;
        adj[--a].push_back({--b, c});
    }

    dij(0);
    cout<<dist[N-1].f<<" "<<dist[N-1].s<<" "<<mi[N-1]<<" "<<mx[N-1]<<endl;

    return 0;
}

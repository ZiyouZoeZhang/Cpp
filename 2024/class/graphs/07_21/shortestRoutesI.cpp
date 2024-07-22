//https://cses.fi/problemset/result/9943897/
#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f

using namespace std;

vector<pair<ll, ll>> adj[200001]; //b, w
ll dist[200001];
bool vis[200001];
ll n, m;


void dijkastra(ll x){
    priority_queue<pair<ll, ll>> pq;

    memset(dist, INF, sizeof(dist));
    memset(vis, false, sizeof(vis));

    pq.push(make_pair(0, x));
    dist[x]=0;
    while (!pq.empty()){
        ll a=pq.top().second; pq.pop();
        if (vis[a]==true) continue;
        vis[a]=true;
        for (auto i: adj[a]){
            ll b=i.first, w=i.second;

            //-- 第一种写法
            dist[b] = min(dist[b], dist[a]+w);
            pq.push(make_pair(-dist[b], b));
            //-- end

            //-- 第二种
            /*
            if (dist[a]+w<dist[b]){
                dist[b]=dist[a]+w;
                q.push({-dist[b], b});
            }
            */
            //-- end
        }
    }
}

int main (){
    cin>>n>>m;
    for (ll i=1; i<=m; i++){
        ll a, b, c;
        cin>>a>>b>>c;
        adj[a].push_back({b, c});
    }

    dijkastra(1);
    for (ll i=1; i<= n; i++){
        cout<<dist[i]<<" ";
    }

    return 0;

}
//https://cses.fi/problemset/task/1195
#include<bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;

vector<pair<ll, ll>> adj[200010]; //b, w
vector<pair<ll, ll>> adj_rev[200010]; //b, w

ll N, M;

vector<ll> distB;

//visA, vis B

vector<ll> dij(ll x){
    vector<ll> dist (M+2, INF);
    vector<bool> vis (M+2, false);
    priority_queue<pair<ll, ll>> pq;

    pq.push(make_pair(0, x));
    dist[x]=0;

    while (!pq.empty()){
        ll a=pq.top().second; pq.pop();
        if (vis[a]) continue;
        vis[a]=true;

        for (auto i: adj[a]){
            ll b=i.first, w=i.second;
            dist[b]=min(dist[b], dist[a]+w);
            pq.push(make_pair(-dist[b], b));
        }
    }
    return dist;
}


vector<ll> dij_rev(ll x){
    vector<ll> dist (M+2, INF);
    vector<bool> vis (M+2, false);
    priority_queue<pair<ll, ll>> pq;

    pq.push(make_pair(0, x));
    dist[x]=0;

    while (!pq.empty()){
        ll a=pq.top().second; pq.pop();
        if (vis[a]) continue;
        vis[a]=true;

        for (auto i: adj_rev[a]){
            ll b=i.first, w=i.second;
            dist[b]=min(dist[b], dist[a]+w);
            pq.push(make_pair(-dist[b], b));
        }
    }

    return dist;
}


int main(){
    cin>>N>>M;
    for (ll i=0; i<M; i++){
        ll a, b, c;
        cin>>a>>b>>c;
        adj[a].push_back(make_pair(b, c));
        adj_rev[b].push_back(make_pair(a, c));
    }

    vector<ll> distA = dij(1), distB = dij_rev(N);

    ll minimum=INF;
    for (ll a=1; a<=M; a++) {
        for (auto i: adj[a]) {
            ll b=i.first, w=i.second;
            if (distA[a]+distB[b]+(w/2.0)<minimum) minimum = distA[a]+distB[b]+(w/2);
        }
    }

    cout<<minimum<<endl;

}
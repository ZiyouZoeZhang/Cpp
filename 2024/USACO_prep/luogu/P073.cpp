#include <bits/stdc++.h>
#define f first
#define s second
#define ll long long
#define INF 0x3f3f3f3f3f3f3f3f
#define FOR(i, a, b)  for(ll i = (a); i < (b); i++)
#define PB push_back
using namespace std;

ll N, M, mx = 0;
ll val[100010];
vector<pair<ll, ll>> win (100010, {INF, 0});//min_val, max_diff
bool vis[100010];
vector<ll> adj[100010];

void bfs(ll x){
    queue<ll> q;
    q.push(x);
    win[x] = {val[x], 0};

    while (!q.empty()){
        ll u = q.front(); q.pop();
        for (auto v: adj[u]){
            ll temp1= win[v].s, temp2 = win[v].f;
            win[v].s = max(win[v].s, win[u].s);
            win[v].s = max(val[v]-win[u].f, win[v].s);
            mx = max(mx,  win[v].s);
            win[v].f = min(win[v].f, win[u].f);
            win[v].f = min(val[v], win[v].f);
            if (temp1 != win[v].s || temp2 != win[v].f) q.push(v);
        }
    }
}

int main (){
    cin>>N>>M;
    FOR(i, 0, N){
        cin>>val[i];
    }

    FOR(i, 0, M){
        ll a, b, c;
        cin>>a>>b>>c;
        adj[--a].PB(--b);
        if (c==2) adj[b].PB(a);
    }
    memset(vis, false, 100010);

    bfs(0);

    cout<<win[N-1].s<<endl;
    return 0;
}
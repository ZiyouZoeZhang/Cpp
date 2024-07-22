#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f

using namespace std;

vector<pair<ll, ll>> adj[200001];
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
            dist[b] = min(dist[b], dist[a]+w);
            pq.push(make_pair(-dist[b], b));
        }
    }
}

/*
void bfs(int x){
    vector<int> adj[10010];
    int dist[10010];

    queue<int> q;

    memset(dist, INF, sizeof(dist));

    q.push(x);
    dist[x]=1;
    while (!q.empty()){
        int a = q.front(); q.pop();
        for (auto b: adj[a]){
            if (dist[b]==INF){
                dist[b]=dist[a]+1;
                q.push(b);
            }
        }
    }

}
*/

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



//teachers version of the cses question
/*
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
*/
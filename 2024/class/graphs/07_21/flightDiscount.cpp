//https://cses.fi/problemset/task/1195
#include<bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;

vector<pair<int, int>> adj[200010]; //b, w
vector<pair<int, int>> adj_rev[200010]; //b, w

int N, M;


vector<int> distB;

//visA, vis B

vector<int> dij(int x){
    vector<int> dist (M+2, INF);
    vector<bool> vis (M+2, false);
    priority_queue<pair<int, int>> pq;

    pq.push(make_pair(0, x));
    dist[x]=0;

    while (!pq.empty()){
        int a=pq.top().second; pq.pop();
        if (vis[a]) continue;
        vis[a]=true;

        for (auto i: adj[a]){
            int b=i.first, w=i.second;
            dist[b]=min(dist[b], dist[a]+w);
            pq.push(make_pair(-dist[b], b));
        }
    }

    return dist;
}

vector<int> dij_rev(int x){
    vector<int> dist (M+2, INF);
    vector<bool> vis (M+2, false);
    priority_queue<pair<int, int>> pq;

    pq.push(make_pair(0, x));
    dist[x]=0;

    while (!pq.empty()){
        int a=pq.top().second; pq.pop();
        if (vis[a]) continue;
        vis[a]=true;

        for (auto i: adj_rev[a]){
            int b=i.first, w=i.second;
            dist[b]=min(dist[b], dist[a]+w);
            pq.push(make_pair(-dist[b], b));
        }
    }

    return dist;
}


int main(){
    cin>>N>>M;
    for (int i=0; i<M; i++){
        int a, b, c;
        cin>>a>>b>>c;
        adj[a].push_back(make_pair(b, c));
        adj_rev[b].push_back(make_pair(a, c));
    }

    vector<int> distA = dij(1), distB = dij_rev(N);

    int minimum=INF;
    for (int a=1; a<M; a++) {
        for (auto i: adj[a]) {
            int b=i.first, w=i.second;

            if (distA[a]+distB[b]+(w/2.0)<minimum) minimum = distA[a]+distB[b]+(w/2);
        }
    }

    cout<<minimum<<endl;

}
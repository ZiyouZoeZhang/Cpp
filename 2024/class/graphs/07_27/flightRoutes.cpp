//https://cses.fi/problemset/task/1196/
#include <bits/stdc++.h>
#define ll long long
#define f first
#define s second
using namespace std;

vector<vector<ll>> costs(100010);
vector<pair<int, ll>> adj[100010]; //b, price

ll N, M, K;

void dij(int i){
    priority_queue<pair<ll, int>> pq; //cost, node
    pq.push({0, i});
    //costs[i].push_back(0);

    while (!pq.empty() && costs[N-1].size()<K){ //while not enough nodes...
    //while (!pq.empty()){ 
        ll a = pq.top().s, ac = -pq.top().f; pq.pop();
        if (costs[a].size()>=K) {continue;}
        costs[a].push_back(ac);
        //if (costs[a].size()<K) costs[a].push_back(ac);
        for (auto j: adj[a]){
            ll b=j.f, bc = j.s;
            //costs[b].push_back(ac + bc);
            pq.push({-(ac + bc), b});
        }
    }
}

int main (){
    cin>>N>>M>>K;
    for (ll i=0; i<M; i++){
        ll a, b, c;
        cin>>a>>b>>c;
        adj[--a].push_back({--b, c});
    }

    for (ll i=0; i<N; i++){
        sort(adj[i].begin(), adj[i].end(), [](pair<int, ll>a, pair<int, ll>b) {return a.s < b.s;});
    }

    dij(0);

    sort(costs[N-1].begin(), costs[N-1].end());
    
    for (ll i=0; i<K; i++) cout<<costs[N-1][i]<<" ";
    /*
    for (auto i: costs[N-1]){
        cout<<i<<" ";
    }
    */
    cout<<endl;
}
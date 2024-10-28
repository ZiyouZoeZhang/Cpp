//https://usaco.org/index.php?page=viewproblem2&cpid=1017
#include <bits/stdc++.h>
#define FOR(i, a, b)  for(int i = (a); i <= (b); i++)
#define pb push_back
using namespace std;

int n, m, c;
queue<int> q;
vector<int> vec, in;
vector<pair<int, int>> adj[100010];

int main (){
    cin>>n>>m>>c;
    vec.resize(n+5);
    in.resize(n+5, 0);

    FOR(i, 1, n) cin>>vec[i];
    FOR(i, 1, c){
        int a, b, x;
        cin>>a>>b>>x;
        adj[a].pb({b, x});
        in[b]++;
    } 

    FOR (i, 1, n){
        if (in[i] == 0) q.push(i);
    }

    while (!q.empty()){
        int u = q.front(); q.pop();
        for (auto [v, x]: adj[u]){
            in[v]--;
            vec[v] = max(vec[v], vec[u]+x);
            if (in[v]==0) q.push(v);
        }
        adj[u].clear();
    }

    FOR(i, 1, n){
        cout<<vec[i]<<endl;
    }
}
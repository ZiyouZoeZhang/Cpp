//https://cses.fi/problemset/task/1751

#include <bits/stdc++.h>
#define pb push_back
#define FOR(i, a, b)  for(int i = (a); i < (b); i++)
using namespace std;

vector<int> v, ans, adj[200010];

void dfs(int u, int t)
{
    if(ans[u] > 0) return;

    ans[u] = t;
    for(auto v: adj[u]){
        dfs(v, t + 1);
    }
}

void Floyd(int x){ //处理环的
    int a = v[x];
    int b = v[v[x]];

    while (a!=b){
        a = v[a];
        b = v[v[b]];
    } 
    a = x;
    while (a!=b){
        a = v[a];
        b = v[b];
    }

    int first = a; //where the cycle starts

    vector<int> cycle;

    b = v[a]; 
    int length = 1; 
    while (a != b) { 
        cycle.pb(b);
        b = v[b]; 
        length++;
    } 
    cycle.pb(b);

    FOR(i, 0, cycle.size()) ans[cycle[i]] = length;

    FOR(i, 0, cycle.size()) {
        for (auto v: adj[cycle[i]]){
             dfs(v, length+1);
        }
    }
}

int main (){
    int n; cin>>n;
    v.resize(n+5);
    ans.resize(n+5, 0);

    for (int i=0; i<n; i++) {
        cin>>v[i]; 
        v[i]--;
        adj[i].push_back(v[i]);
        adj[v[i]].push_back(i);
    }
    for (int i=0; i<n; i++){
        if (ans[i] == 0) Floyd(i);
        cout<<ans[i]<<" ";
    }
}
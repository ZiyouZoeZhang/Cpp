#include<bits/stdc++.h>
using namespace std;

vector<int>topo;
int vis[100010];
int state[100010]; 
int ans[100010];
int in[100010];
vector<pair<int, int>> adj[100010];

void toposort(int s){
    if(vis[s] == 1 or state[s] == 2){
        return;
    }
    vis[s] = 1;
    state[s] = 1;
 
    for(auto [x, u] : adj[s]){
        if(state[u] == 1){
            exit(0);
        }
        ans[u] = max(ans[u], ans[s]+x);
        toposort(u);
    }
    
    state[s] = 2;
    topo.push_back(s);
}


int main (){
    int n, m, c;

    cin>>n>>m>>c;
    
    vector<int> v(n);
    memset(vis, false, sizeof(n));
    memset(state, 0, sizeof(n));
    memset(ans, 0, sizeof(n));
    memset(in, 0, sizeof(n));

    for (int i=0; i<n; i++) {cin>>v[i]; v[i]--; ans[i] = v[i];}
    for (int i=0; i<c; i++) {
        int a, b, x;
        cin>>a>>b>>x;
        adj[--a].push_back({x, --b});
        in[b]++;
    }

    for (int i=0; i<n; i++){
        if (!vis[v[i]]){
            toposort(v[i]);
        }
    }

    reverse(topo.begin(),topo.end());

    for (int i=0; i<n; i++){
        cout<<++ans[i]<<endl;
    }
}
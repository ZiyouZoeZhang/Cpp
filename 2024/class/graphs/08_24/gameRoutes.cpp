//https://cses.fi/problemset/task/1681
#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;
 
int n,m;
vector<int>adj[100010];
vector<int>topo;
int vis[100010];
int state[100010]; //default value is 0; processing value is 1; completed value is 2
 
 
void toposort(int s){
    if(vis[s] == 1 or state[s] == 2){
        return;
    }
 
    vis[s] = 1;
    state[s] = 1;
 
    for(auto u : adj[s]){
        if(state[u] == 1){
            cout << "IMPOSSIBLE" << endl;
            exit(0);
        }
        toposort(u);
    }
    
    state[s] = 2;
    topo.push_back(s);
}
 
 
 
int main(){
    cin >> n >> m;
    for(int i = 0; i < m ; i++){
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
    }
    
    for(int i = 1; i <= n ; i++){
        if(vis[i] == 0){
            toposort(i);
        }
    }
 
    reverse(topo.begin(),topo.end());

    vector<int> count(100010, 0);
    count[1] = 1;
    for(auto u : topo){
        for (auto v: adj[u]){
            count[v] += count[u];
            count[v] %= MOD;    
        }
        //cout << u << " ";
    }
    cout << count[n]<<endl;
 
   return 0;
}
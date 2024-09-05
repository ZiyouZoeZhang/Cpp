//https://usaco.org/index.php?page=viewproblem2&cpid=838
#include <bits/stdc++.h>
#define FOR(i, a, b)  for(int i = (a); i < (b); i++)
#define pb push_back
using namespace std;

int n, m;
vector<int> input[50010];
vector<int> topo;
vector<int> adj[100010];
bool vis[100010];
int state[100010];

bool toposort(int x){
    if (vis[x] or state[x] == 2) return true;

    vis[x] = true;
    state[x] = 1;
    for (auto v: adj[x]) {
        if (state[v]==1){
            return false;
        } 
        if (!toposort(v)) return false;
    }
    state[x] = 2;
    topo.pb(x);
    return true;
}

bool check(int x){
    memset(vis, false, sizeof(vis));
    memset(state, 0, sizeof(state));
    topo.clear();
    FOR(i, 0, n) adj[i].clear();
    
    FOR(i, 0, x){
        FOR(j, 1, input[i].size()){
            adj[input[i][j-1]].pb(input[i][j]);
        }
    }

    FOR (i, 0, x){
        sort(adj[i].begin(), adj[i].end(), greater<int>());
    }  

    for(int i=n-1; i>=0; i--){
        if (!vis[i]) {
            if (!toposort(i)) return false;
        }
    }

    reverse(topo.begin(), topo.end());
    return true;
}

int main (){
    cin>>n>>m;
    int size;
    FOR(i, 0, m){
        cin>>size;
        input[i].resize(size);
        FOR(j, 0, size){
            cin>>input[i][j];
            input[i][j]--;
        }
    }

    int x = n-1;
    for (int b = n-2; b > 0; b /= 2) {
        while (!check(x-b)){ x -= b;}
    }

    FOR(i, 0, n){
        cout<<topo[i]+1<<" ";
    }

    return 0;
}

/*
5 5
5 1 2 3 4 5
6 1 3 2 5 4 3
4 5 1 3 2
8 5 2 3 1 4 2 3 5
2 4 3

5 5          
5 3 2 4 1 5
3 3 1 5
2 4 5
4 5 1 3 2
8 5 2 3 1 4 2 3 5

5 5 
3 3 1 5
2 4 5
2 3 4
5 1 2 3 4 5
6 1 3 2 5 4 3
*/

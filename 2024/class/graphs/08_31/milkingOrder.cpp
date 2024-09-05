//https://usaco.org/index.php?page=viewproblem2&cpid=838
#include <bits/stdc++.h>
#define FOR(i, a, b)  for(int i = (a); i < (b); i++)
#define pb push_back
using namespace std;

int n, m, state[100010];
vector<int> input[50010], adj[100010];

bool toposort(int x){
    if (state[x]!= 0) return true;
    state[x] = 1;

    for (auto v: adj[x]) {
        if (state[v]==1 or !toposort(v)) return false;
    }

    state[x] = 2;
    return true;
}

void setup(int x){
    memset(state, 0, sizeof(state));
    FOR(i, 0, n) adj[i].clear();
    FOR(i, 0, x){
        FOR(j, 1, input[i].size()) adj[input[i][j-1]].pb(input[i][j]);
    }
    FOR (i, 0, x) sort(adj[i].begin(), adj[i].end(), [](int a, int b){return b<a;});
}

bool check(int x){
    setup(x);
    for(int i=n-1; i>=0; i--){
        if (state[i]==0) {
            if (!toposort(i)) return false;
        }
    }
    return true;
}

void final (int x){
    //setup(x);
    vector<int> in(n, 0);
    priority_queue<int, vector<int>, greater<int>>q;
    
    FOR(i, 0, n) for (auto v: adj[i]) in[v]++;
    FOR(i, 0, n) { if(in[i] == 0) q.push(i); }

	while(!q.empty()) {
		int u = q.top(); q.pop();
		cout<<u+1<<" ";
        for (auto v: adj[u]) {
            in[v]--;
            if (in[v]==0) q.push(v);
        }
	}
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

    int x = n-1, b;
    for (b = n-2; b > 0; b /= 2) {
        while (!check(x-b)) { x -= b;}
    }

    final(x-b-1);
    return 0;
}
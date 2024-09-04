//https://codeforces.com/contest/919/problem/D
#include <bits/stdc++.h>
#define FOR(i, a, b)  for(int i = (a); i < (b); i++)
#define pb push_back
using namespace std;

int n, m;
string s;

vector<int>topo;
vector<int> rev[300010];
int vis[300010];
int state[300010]; //default value is 0; processing value is 1; completed value is 2
int ans[300010][26];
 
void toposort(int s){
    if(vis[s] == 1 or state[s] == 2) return;

    vis[s] = 1;
    state[s] = 1;

    for(auto u : rev[s]){
        if(state[u] == 1){
            cout << "-1" << endl;
            exit(0);
        }
        toposort(u);
    }
    state[s] = 2;
    topo.push_back(s);
}

int check(int x){
    int mx = 0;

    FOR(i, 0, n){
        int u = topo[i];

        if (s[u]-'a' == x) ans[u][x]++;
        mx = max(mx, ans[u][x]);
        for (auto v: rev[u]){
            ans[v][x] = max(ans[v][x], ans[u][x]);
        }
    }

    return mx;
}


int main(){
    cin>>n>>m;
    
    memset(vis, false, sizeof(vis));
    memset(state, 0, sizeof(state));
    memset(ans, 0, sizeof(ans));
    memset(rev, 0, sizeof(rev));

    cin>>s;

    FOR(i, 0, m) {
        int a, b;
        cin>>a>>b;
        rev[--b].pb(--a);
    }

    FOR(i, 0, n){
        if (!vis[i]) toposort(i);
    }

    reverse(topo.begin(), topo.end());

    int mx = 0;
    FOR(i, 0, 26){
        mx = max(mx, check(i));
    }

    cout<<mx<<endl;
    return 0;
}
//https://codeforces.com/problemset/problem/510/C
#include <bits/stdc++.h>
#define FOR(i, a, b)  for(int i = (a); i < (b); i++)
#define pb push_back
using namespace std;

int n;

vector<int> adj[26];
vector<string> ss;
vector<int> topo;
bool vis[26];
int state[26];


void toposort(int x){
    if (vis[x] or state[x]==2) return;

    vis[x] = true;
    state[x] = 1;

    for (auto u: adj[x]){
        if (state[u]==1) {
            cout<<"Impossible"<<endl;
            exit(0);
        }
        toposort(u);
    }

    state[x] = 2;
    topo.pb(x);
}

int main(){
    cin>>n;

    FOR(i, 0, n){
        string s;
        cin>>s;
        ss.pb(s);
    }

    FOR(i, 1, n){
        int j=0;
        while(j<ss[i-1].size() && j<ss[i].size() && ss[i-1][j]==ss[i][j]) j++;
        if (j<ss[i-1].size() && j<ss[i].size()) adj[ss[i-1][j]-'a'].pb(ss[i][j]-'a');
        else if (ss[i-1].size() > ss[i].size()) {
            cout<<"Impossible"<<endl;
            exit(0);
        }
    }

    FOR(i, 0, 25){
        if (adj[i].size()==0 && i!= (ss[n-1][0]-'a') ) adj[i].pb(i+1);
    }

    FOR(i, 0, 26){
        if (!vis[i]) toposort(i);
    }
    reverse(topo.begin(), topo.end());

    vector<bool> v(26, false);

    FOR(i, 0, topo.size()){
        cout<<char(topo[i]+'a');
        v[topo[i]] = true;
    }

    FOR (i, 0, 26){
        if (!v[i]) cout<<char(i+'a');
    }

}
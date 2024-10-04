//to be continued
#include <bits/stdc++.h>
#define FOR(i, a, b)  for(ll i = (a); i < (b); i++)
#define ll long long
#define pb push_back
using namespace std;

int n;
vector<int> adj[100010];
vector<bool> vis(100010, false);

int main (){
    cin>>n;
    FOR(i, 0, n-1){
        int a, b;
        cin>>a>>b;
        adj[a].pb(b);
        adj[b].pb(a);
    }


}
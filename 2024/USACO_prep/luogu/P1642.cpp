#include <bits/stdc++.h>
#define FOR(i, a, b)  for(ll i = (a); i < (b); i++)
#define ll long long
#define pb push_back
using namespace std;


int n, m;
vector<int> prod;
vector<int> poll;
vector<int> adj[100];
vector<int> ans;

int f(int a, int b) { //node a, b to be removed
    for (auto v: adj[a]){
        FOR (c, 0, b){
            ans[a] = max(ans[a], f(a, c) + f(v, b-c));
        }
    }
    return ans[a];
}

int main (){
    cin>>n>>m;
    prod.resize(n);
    poll.resize(n);
    ans.resize(n, 0);

    FOR (i, 0, n) cin>>prod[i];
    FOR (i, 0, n) cin>>poll[i];

    FOR (i, 0, n-1){
        int a, b;
        cin>>a>>b;
        adj[--a].pb(--b);
    }



}

//f(a, b) = max(f(a, b), f(a, c)+f(v, b-c));
//https://usaco.org/index.php?page=viewproblem2&cpid=767
#include <bits/stdc++.h>
#define FOR(i, a, b)  for(ll i = (a); i < (b); i++)
#define ll long long
#define pb push_back
#define s second
#define f first
using namespace std;

ll n, m;
multiset<ll> spices;
ll s[100010], f[100010];
ll a;

void setIO(string name = "") {
    ios_base::sync_with_stdio(0); cin.tie(0);
    if((int)(name).size()){
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout);
    }
}

int main (){
    setIO("hayfeast");
    cin>>n>>m;
    FOR(i, 0, n){
        cin>>f[i]>>s[i];
    }
    
    ll total = 0;
    ll mi = 0x3f3f3f3f3f3f3f3f;
    
    FOR(i, 0, n){
        total+=f[i];
        spices.insert(s[i]);
        while((total-f[a])>=m){
            total-=f[a];
            spices.erase(spices.find(s[a]));
            a++;
        }
        if (total>=m) mi = min(mi, *spices.rbegin());
    }
    cout<<mi<<endl;
}
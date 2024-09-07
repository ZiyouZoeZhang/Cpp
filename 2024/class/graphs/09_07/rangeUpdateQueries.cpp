//https://cses.fi/problemset/task/1651 差分数组 + BIT
#include <bits/stdc++.h>
#define FOR(i, a, b)  for(ll i = (a); i < (b); i++)
#define ll long long
#define pb push_back
#define lowbit(x) ((x) & - (x))
using namespace std;

ll n, q;
vector<ll> v;
vector<ll> cf;
vector<ll> tree;

void add(ll x, ll d){  //ax = ax + d
	while(x <= n) {
	   tree[x] += d;  
       x += lowbit(x); 
	}
}

ll sum(ll x){
    ll sum = 0;
    while (x>0){
        sum += tree[x]; 
        x -= lowbit(x);
    }
    return sum;
}

int main (){
    cin>>n>>q;
    v.resize(n+20);
    cf.resize(n+20);
    tree.resize(n+20, 0);

    FOR(i, 1, n+1) {
        cin>>v[i];
        (i==1) ? cf[i]=v[i] : cf[i] = v[i]-v[i-1];
        add(i, cf[i]);
    }

    FOR (i, 0, q){
        ll x;
        cin>>x;
        if (x==1){
            ll a, b, u;
            cin>>a>>b>>u; //range increase
            //cf[a] + u, cf[b+1] - u
            add(a, u); add(b+1, -u);

        } else if (x==2){
            ll k;
            cin>>k; //value at pos k
            //sum of k
            cout<<sum(k)<<endl;
        }
    }
    return 0;
}
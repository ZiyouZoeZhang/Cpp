//https://cses.fi/problemset/task/1648/
#include <bits/stdc++.h>
#define FOR(i, a, b)  for(ll i = (a); i < (b); i++)
#define ll long long
#define pb push_back
#define lowbit(x) ((x) & - (x))
using namespace std;

ll n, q, tree[200050];

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
    memset(tree, 0, sizeof(n+50));

    FOR(i, 1, n+1) {
        ll a; cin>>a;
        add(i, a);
    }

    FOR (i, 0, q){
        ll x; cin>>x;
        if (x==1){
            ll k, u; cin>>k>>u; //update value
            add(k, u-sum(k)+sum(k-1));

        } else if (x==2){
            ll a, b; cin>>a>>b; //sum of range
            cout<<sum(b) - sum(a-1)<<endl;
        }
    }
    return 0;
}

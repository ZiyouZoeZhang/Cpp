//https://www.luogu.com.cn/problem/P3054
#include <bits/stdc++.h>
#define FOR(i, a, b)  for(ll i = (a); i < (b); i++)
#define ll long long
#define pb push_back
#define lowbit(x) ((x) & - (x))
#define s second
#define f first
#define MAXN 100010

using namespace std;

void setIO(string name = "") {
    ios_base::sync_with_stdio(0); cin.tie(0);
    if((ll)(name).size()){
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout);
    }
}

ll n, l, c;
ll tree[100010];

void add(ll x, ll d){  //ax = ax + d
	while(x <= MAXN) {
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
    cin>>n>>l>>c;
    vector<ll> v(n);
    ll mx = 0;
    FOR(i, 0, n) cin>>v[i];
    sort(v.begin(), v.end());

    ll time = c*l/v[n-1];

    ll count = 0, ans = 0;
    FOR(i, 0, n){
        while(v[i]*time >= v[count]*time+c) { //大一圈
            count++;
        }
        ans+=count;
    }

    cout<<ans<<endl;

}

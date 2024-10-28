//https://www.luogu.com.cn/problem/P3054
#include <bits/stdc++.h>
#define FOR(i, a, b)  for(ll i = (a); i < (b); i++)
#define ll long long
#define pb push_back
#define lowbit(x) ((x) & - (x))
#define s second
#define f first
#define MAXN 1000010
using namespace std;

int n, l, c;
ll ans = 0, m = 1e6, prefix = 0, q[100010], maxv = 0;
ll tree[1000100];

struct laps{
    ll s, t;
};

laps p[100002];


bool cmp(laps aa, laps bb){
    if (aa.s != bb.s ) return aa.s < bb.s; 
    return aa.t < bb.t;
}

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
    FOR(i, 0, n){
        cin>>q[i];
        maxv = max(maxv, q[i]);
    }

    FOR(i, 0, n){
        p[i].s  = q[i]*l/maxv; //完整的圈数
        p[i].t = q[i]*l%maxv; //小数部分
    }

    sort(p, p+n, cmp);
    FOR(i, 0, n){
        ans += i * p[i].s - prefix - (sum(m) - sum(p[i].t));
        prefix += p[i].s;
        if (p[i].t!=0) add(p[i].t, 1);
    }

    cout<<ans<<endl;
}
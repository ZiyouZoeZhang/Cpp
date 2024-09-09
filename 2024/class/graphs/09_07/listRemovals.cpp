//https://cses.fi/problemset/result/10458726/
#include <bits/stdc++.h>
#define FOR(i, a, b)  for(ll i = (a); i < (b); i++)
#define ll long long
#define pb push_back
#define lowbit(x) ((x) & - (x))
using namespace std;

int n, v[200010],tree[200010];

void add(ll x, ll d){
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

int bsearch_1(int l, int r, int pos) {
    while (l < r)
    {
        int mid = l + r >> 1;
        if (sum(mid)>=pos) r = mid;
        else l = mid + 1;
    }
    return l;
}

int main (){
    cin>>n;
    memset(tree, 0, sizeof(tree));
    FOR(i, 1, n+1) cin>>v[i];
    FOR(i, 1, n+1){
        add(i, 1);
    }
    FOR (i, 1, n+1){
        int x;
        cin>>x;
        int a = bsearch_1(1, n+1, x);
        cout<<v[a]<<" ";
        add(a, -1);
    }
    return 0;

}
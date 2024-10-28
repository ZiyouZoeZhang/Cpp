//https://usaco.org/index.php?page=viewproblem2&cpid=1041
//to be reviewed
#include <bits/stdc++.h>
#define FOR(i, a, b)  for(ll i = (a); i < (b); i++)
#define ll long long
#define pb push_back
#define lowbit(x) ((x) & - (x))
#define s second
#define f first
using namespace std;

void setIO(string name = "") {
    ios_base::sync_with_stdio(0); cin.tie(0);
    if((int)(name).size()){
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout);
    }
}

int a[100010], tree[100010], t[100010];
int n, MAXN = 100010;

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
    setIO("haircut");
    cin>>n;
    FOR(i, 1, n+1){
        cin>>a[i]; a[i]++;
        t[a[i]] = t[a[i]] + (i-1) - sum(a[i]);
        add(a[i],1);
    }

    int c = 0;
    FOR(i, 1, n+1){
        cout<<c<<endl;
        c+=t[i];
    }

}

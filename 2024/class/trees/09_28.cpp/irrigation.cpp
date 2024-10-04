//https://codeforces.com/contest/1181/problem/D
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

ll n, m, q;
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

int bsearch_1(int l, int r, int x) {
    while (l < r)
    {
        int mid = (l + r) >> 1;
        if (sum(mid)==x) r = mid;
        else l = mid + 1;
    }
    return l;
}

int bsearch_2(int l, int r, int x)
{
    while (l < r)
    {
        int mid = (l + r + 1) >> 1;
        if (sum(mid)==x) l = mid;
        else r = mid - 1;
    }
    return l;
}

int main (){
    cin>>n>>m>>q;
    int temp[m];
    vector<pair<ll, ll>> qs(q, {0, 0});
    memset(temp, 0, sizeof(temp));
    FOR(i, 0, n) {
        int a; cin>>a;
        temp[--a]++;
    }
    
    vector<pair<int, int>> cities; //num, ind
    FOR(i, 0, m){
        cities.pb({temp[i], i});
    }
    sort(cities.begin(), cities.end(), [](pair<int, int> a, pair<int, int> b){if (b.f!=a.f)return a.f<b.f; else return a.s<b.s;});
    
    FOR(i, 0, q) {cin>>qs[i].f; qs[i].s=i;}
    sort(qs.begin(), qs.end());

    int ans[q];

    ll years = 0, i = 1;
    add(cities[0].s, 1);
    for(auto [y, ind]: qs){
        while(i<m && (years + (cities[i].f-cities[i-1].f)*i) < y){
            add(cities[i].s+1, 1); years += (cities[i].f-cities[i-1].f)*i; i++;
        }
        ans[ind] = bsearch_1(0, m, (y-years)%i);
    }

    for(auto a:ans)cout<<a<<endl;


    return 0;
}
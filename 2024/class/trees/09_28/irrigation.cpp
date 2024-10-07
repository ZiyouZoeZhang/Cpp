//https://codeforces.com/contest/1181/problem/D
//wrong, to be corrected

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
ll cost[500004];

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

int bsearch_1(int l, int r, ll x) {
    while (l < r)
    {
        int mid = (l + r ) >> 1;
        if (cost[mid]==x) r = mid;
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

int bsearch_3(int l, int r, int x) {
    while (l < r)
    {
        int mid = (l + r ) >> 1;
        if (sum(mid)==x) r = mid;
        else l = mid + 1;
    }
    return l;
}

int main (){
    cin>>n>>m>>q; 
    //n = the number of olympiads before the rule was introduced 
    //m = the number of cities in Berland wishing to host the olympiad 
    //q = the number of years Misha's mother is interested in
    int times[m], ans[q], sum = 0;
    memset(times, 0, sizeof(times));

    vector<pair<int, int>> cities; //num, ind
    vector<pair<ll, int>> qs(q, {0, 0}); //questions
   
    FOR(i, 0, n) {
        int a; cin>>a, times[--a]++; //start with index 0;
    }
    FOR(i, 0, m){
        cities.pb({times[i], i});
    }
    sort(cities.begin(), cities.end(), [](pair<int, int> a, pair<int, int> b){if (b.f!=a.f)return a.f<b.f; else return a.s<b.s;});
    FOR(i, 1, m){ //把大家都加到f[i] = cities[i].s的价格
        cost[i] = cost[i-1] + i*(cities[i].f - cities[i-1].f);
    }
    FOR(i, 0, q) {cin>>qs[i].f; qs[i].s=i;} //question, ind
    sort(qs.begin(), qs.end());

    int cur = 0; //ok weird indexing
    for(auto ss: qs){
        ll k = ss.f-n; int ind = ss.s;
        
        int pos = bsearch_1(0, m, k);
        while (cur<pos) add(cities[cur].s+1, 1), cur++;

        int aa = (k-cost[pos-1])%(pos);
        ans[ind] = bsearch_2(1, m+1, aa);
    }

    for(auto a:ans)cout<<a<<endl;
    return 0;
}
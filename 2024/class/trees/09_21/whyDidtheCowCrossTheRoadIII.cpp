//https://usaco.org/index.php?page=viewproblem2&cpid=719
#include <bits/stdc++.h>
#define FOR(i, a, b)  for(ll i = (a); i < (b); i++)
#define ll long long
#define pb push_back
#define f first
#define s second
#define lowbit(x) ((x) & - (x))
using namespace std;

int n;
int tree[100010];

void setIO(string name = "") {
    ios_base::sync_with_stdio(0); cin.tie(0);
    if((int)(name).size()){
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout);
    }
}

void add(ll x, ll d){  //ax = ax + d
	while(x <= 2*n) {
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

int mk[50010];

int main (){

    //setIO("circlecross");
    cin>>n;

    //-----------my version---------
    /*
    vector<pair<int, int>> v (n+1, pair<int, int> {-1, -1});
    FOR(i, 0, 2*n){
        int a;
        cin>>a;
        if (v[a].first==-1) v[a].first = i;
        else v[a].second = i;
    }

    sort(v.begin(), v.end(), [](pair<int, int>a, pair<int, int>b){return a.f<b.f;});
    
    int c = 0;
    FOR(i, 1, n+1){
        c += sum(v[i].s) - sum(v[i].f);
        add(v[i].s, 1);
    }

    cout<<c<<endl;
    */

    //-------easier version--------
    int ans = 0;
    FOR(i, 1, 2*n){
        int a; cin>>a;
        if (!mk[a]) mk[a] = i, add(i,1);
        else {
            add(mk[a], -1);
            ans += sum(i) - sum(mk[a]);
        }

    }
    cout<<ans<<endl;

}
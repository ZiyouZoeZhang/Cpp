//https://cses.fi/problemset/task/2416
#include <bits/stdc++.h>
#define FOR(i, a, b)  for(ll i = (a); i < (b); i++)
#define ll long long
#define pb push_back
#define s second
#define f first
using namespace std;

int n, q;
int v[100010];
int newv[100010];
ll pre[100010];
vector<pair<int, int>> qs;
int dif[100010];


/*
5 3
2 10 4 2 5
3 5
2 2
1 4

2 10 4 2 5
0 0 6 8 5
2 10 10 10 10
       0 2 0
*/

int main (){
    memset(dif, 0, sizeof(dif));
    memset(pre, 0, sizeof(dif));
    cin>>n>>q;

    FOR(i, 0, n){
        cin>>v[i];
        if (i==0) newv[i] = v[i];
        if (i!=0){
            newv[i] = max(newv[i-1], v[i]);
            if (v[i]<newv[i]) dif[i] = newv[i] - v[i];
        }
        pre[i+1] = pre[i] + dif[i];
    }

    FOR(i, 0, q){
        int a, b; cin>>a>>b;
        //qs.pb({a, b});
        ll ans = pre[b] - pre[a-1];
        ans -= (b-a)*(newv[a-1]-v[a-1]);
        cout<<ans<<endl;
    }

    return 0;

}
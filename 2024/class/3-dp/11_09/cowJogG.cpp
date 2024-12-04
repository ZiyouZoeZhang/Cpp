#include <bits/stdc++.h>
#define FOR(i, a, b)  for(ll i = (a); i < (b); i++)
#define ll long long
#define pb push_back
using namespace std;

int find_lis(vector<ll> a) {
    vector<ll> dp;
    for (ll i=a.size()-1; i>=0; i--){//或者修改顺序
        ll pos = upper_bound(dp.begin(), dp.end(), a[i]) - dp.begin(); //递增
        //改成upperbound变 不降
        if (pos == dp.size()) {
            dp.push_back(a[i]);
        } else {
            dp[pos] = a[i];
        }
    }
    return dp.size();
}

int main (){
    ll n, t; cin>>n>>t;
    vector<ll> e(n);
    FOR(i, 0, n){
        int a, b; cin>>a>>b;
        e[i] = a + (t*b);
    }
    cout<<find_lis(e)<<endl;
}
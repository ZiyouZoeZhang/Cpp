//https://cses.fi/problemset/task/2185
//容斥原理

#include <bits/stdc++.h>
#define FOR(i, a, b)  for(ll i = (a); i < (b); i++)
#define ll long long
//#define f first
//#define s second
#define pb push_back
using namespace std;

int main(){
    ll n, k;
    cin>>n>>k;
    vector<ll> v(k);
    ll total = 0;

    FOR(i, 0, k){
        cin>>v[i];
        //total += (n/v[i]);
    }

    FOR(i, 0, k-1){
        FOR(j, i+1, k){
            if (v[i]*v[j]<= n && v[i]*v[j]>0){
                //cout<<v[i]*v[j]<<endl;
                total -= n/(v[i]*v[j]);
            }
                
        }
    }

    FOR(i, 0, k){
        //cin>>v[i];
        total += (n/v[i]);
    }

    cout<<total<<endl;

}
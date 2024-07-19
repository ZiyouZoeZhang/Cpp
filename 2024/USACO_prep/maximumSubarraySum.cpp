//https://cses.fi/problemset/task/1643/
//nice

#include <iostream>
#include <vector>
#include <zlib.h>
//#include <stdc++.h>
#define ll long long
using namespace std;


//I would say best possible solution --  from CPH
ll maxSubarraySum(ll N, vector<ll>v){
    ll sum = v[0], maximum = v[0];
    for (ll i=1; i<N; i++){
        sum = max(v[i], sum+v[i]);
        maximum = max(maximum, sum);
    }
    return maximum;
}

int main (){
    vector<ll>v;
    ll N;
    cin>>N;

    ll n;
    for (ll i=0; i<N; i++){
        cin>>n;
        v.push_back(n);
    }

    cout<<maxSubarraySum(N, v)<<endl;
    return 0;
}

/*

//my implementation using Prefix sum
ll maxSubarraySum(ll N, vector<ll> v){
    vector<ll>p;

    p.push_back(0);
    ll s=0;
    for (ll i=0; i<N; i++){
        p.push_back(s+=v[i]);
    }

    ll m=p[1];
    ll minimum=p[0];
    for (ll i=1; i<N+1; i++){
        m=max(p[i]-minimum, m);
        minimum=min(minimum, p[i]);
    }
    
    return m;
}
*/


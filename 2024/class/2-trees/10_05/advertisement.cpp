//https://cses.fi/problemset/task/1142/

#include <bits/stdc++.h>
#define FOR(i, a, b)  for(ll i = (a); i < (b); i++)
#define ll long long
#define pb push_back
#define s second
#define f first
using namespace std;

ll n, v[200010];

ll getMaxArea() {
    stack<ll> s;
    ll res = 0;
    ll tp = 0, curr = 0;
    for (ll i = 0; i < n; i++) {      
        while (!s.empty() && v[s.top()] >= v[i]) {
            tp = s.top(); 
            s.pop();
            ll width = s.empty() ? i : i - s.top() - 1;
            res = max(res,  (ll)v[tp] * width);
        }
        s.push(i);
    }

    while (!s.empty()) {
        tp = s.top(); s.pop();
        curr = v[tp] * (s.empty() ? n : n - s.top() - 1);
        res = max(res, curr);
    }

    return res;
}

int main (){
    cin>>n;
    FOR(i, 0, n) cin>>v[i];
    cout<<getMaxArea()<<endl;

}
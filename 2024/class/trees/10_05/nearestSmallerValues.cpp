//https://cses.fi/problemset/task/1645
#include <bits/stdc++.h>
#define FOR(i, a, b)  for(ll i = (a); i < (b); i++)
#define ll long long
#define pb push_back
#define s second
#define f first
using namespace std;

int main (){
    int n, v[200010];
    stack<pair<int, int>> s;
    s.push({0, 0});

    cin>>n;
    FOR(i, 0, n) cin>>v[i];

    FOR(i, 0, n) {
        while (!s.empty() && s.top().f>=v[i]) s.pop();
        cout<<s.top().s<<" ";
        s.push({v[i], i+1});
    }

}
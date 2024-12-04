//https://cses.fi/problemset/task/1638/
//done, using dp, but not lcs
#include <bits/stdc++.h>
#define FOR(i, a, b)  for(ll i = (a); i < (b); i++)
#define ll long long
#define pb push_back
using namespace std;

bool v[1010][1010];
ll c[1010][1010];
ll n;
ll MOD = (1e9) + 7;
//ll MOD = 1000000007;

void setIO(string name = "") {
    ios_base::sync_with_stdio(0); cin.tie(0);
    if((int)(name).size()){
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout);
    }
}

int main (){
    //freopen("/Users/zoezhang/Documents/Home/C/2024/class/3-dp/11_16/test.txt", "r", stdin);
    cin>>n;
    memset(c, 0, sizeof(c));
    //memset(v, false, sizeof(v));

    FOR(i, 0, n){
        FOR(j, 0, n){
            char a; cin>>a;
            (a=='.') ? v[i][j] = true : v[i][j] = false;
        }
    }

    if (v[0][0]) c[0][0] = 1;

    FOR(i, 0, n){
        FOR(j, 0, n){
            if (v[i][j]){
                if (i!=0) c[i][j] += c[i-1][j];
                c[i][j] %= MOD;
                if (j!=0) c[i][j] += c[i][j-1]; 
                c[i][j] %= MOD;
            }
        }
    }

    cout<<c[n-1][n-1]<<endl;

    return 0;
}
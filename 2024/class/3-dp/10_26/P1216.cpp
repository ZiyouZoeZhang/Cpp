//https://www.luogu.com.cn/problem/P1216
//triangle
//wrote during class
#include <bits/stdc++.h>
#define FOR(i, a, b)  for(ll i = (a); i < (b); i++)
#define ll long long
#define pb push_back
using namespace std;

int n;
int a[1010][1010];

int main (){
    cin>>n;
    FOR(i, 0, n){
        FOR(j, 0, i+1){
            cin>>a[i][j];
        }
    }

    for (int i = n; i>=0; i--){
        FOR(j, 0, i+1){
            a[i][j] = max(a[i+1][j], a[i+1][j+1]) + a[i][j];
        }
    }

    cout<<a[0][0];
    return 0;
}
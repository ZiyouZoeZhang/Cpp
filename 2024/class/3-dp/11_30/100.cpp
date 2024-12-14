#include <bits/stdc++.h>
#define FOR(i, a, b)  for(int i = (a); i < (b); i++)
#define ll long long
#define f first
#define s second
#define pb push_back
using namespace std;

int main(){

    int n; cin>>n;
    vector<vector<int>> v(n, vector<int>(n, 0));
    vector<vector<int>> psum(n, vector<int>(n, 0));
    FOR(i, 0 ,n){
        FOR(j, 0, n){
            cin>>v[i][j]; 
            if (v[i][j]>=100) {
                if (j!=0) psum[i][j] = psum[i][j-1]+1;
                else psum[i][j] = 1;
            } else psum[i][j] = 0;
        }
    }

}
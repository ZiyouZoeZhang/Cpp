#include <bits/stdc++.h>
#define FOR(i, a, b)  for(int i = (a); i < (b); i++)
#define ll long long
#define f first
//#define s second
#define pb push_back
using namespace std;


int main() {

    freopen("/Users/zoezhang/Documents/Home/C/2024/adventOfCode/day4.txt", "r", stdin);


    ll sum = 0;
    string s;
    vector<string> v;

    while (getline(cin, s)) {
        v.pb(s);
    }

    FOR(i, 1, v.size()-1){
        FOR(j, 1, v[0].size()-1){
            if(v[i][j] == 'A'){
                if ((v[i-1][j-1]=='S' && v[i+1][j+1] == 'M') || (v[i-1][j-1]=='M' && v[i+1][j+1] == 'S')){
                    if ((v[i-1][j+1]=='S' && v[i+1][j-1] == 'M') || (v[i-1][j+1]=='M' && v[i+1][j-1] == 'S')) sum++;
                }
            }
        }
    }

    cout<<sum<<endl;
}
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

    FOR(i, 0, v.size()){
        FOR(j, 0, v[0].size()){
            if(v[i].substr(j, 4)=="XMAS" || v[i].substr(j, 4)=="SAMX"){
                sum++;
            }
        }
    }
    FOR(i, 0, v.size()-3){
        FOR(j, 0, v[0].size()){
            if(v[i][j] == 'X' && v[i+1][j] == 'M' && v[i+2][j] == 'A' && v[i+3][j] == 'S'){

                sum++;
            }
            if(v[i][j] == 'S' && v[i+1][j] == 'A' && v[i+2][j] == 'M' && v[i+3][j] == 'X') sum++, cout<<2<<i<<" "<<j<<endl;
        }
    }

    FOR(i, 0, v.size()-3){
        FOR(j, 0, v[0].size()-3){
            if(v[i][j] == 'X' && v[i+1][j+1] == 'M' && v[i+2][j+2] == 'A' && v[i+3][j+3] == 'S') sum++, cout<<i<<" "<<j<<endl;
            if(v[i][j+3] == 'X' && v[i+1][j+2] == 'M' && v[i+2][j+1] == 'A' && v[i+3][j] == 'S') sum++, cout<<i<<" "<<j<<endl;
            if(v[i][j] == 'S' && v[i+1][j+1] == 'A' && v[i+2][j+2] == 'M' && v[i+3][j+3] == 'X') sum++, cout<<i<<" "<<j<<endl;
            if(v[i][j+3] == 'S' && v[i+1][j+2] == 'A' && v[i+2][j+1] == 'M' && v[i+3][j] == 'X') sum++, cout<<i<<" "<<j<<endl;
        }
    }

    cout<<sum<<endl;


}
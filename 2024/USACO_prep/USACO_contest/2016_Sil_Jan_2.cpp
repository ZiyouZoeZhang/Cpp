//https://usaco.org/index.php?page=viewproblem2&cpid=595
#include <iostream>
#include <vector>
#include <fstream>
#define ll long long
using namespace std;

ofstream fout ("div7.out");
ifstream fin ("div7.in");

vector<ll> v;
vector<ll> p;

int main() {
    ll N;
    fin>>N;
    ll s=0, n;
    p.push_back(0);
    for (ll i=0; i<N; i++){
        fin>>n;
        v.push_back(n);
        p.push_back(s+=n);
    }
    for (ll l=N; l>=0; l--){
        for (ll i=0; i<=N-l; i++){
            ll w=(p[l+i]-p[i]);
            if (w%7==0){
                fout<<l<<endl;
                return 0;
            }
        }
    }
    fout<<0<<endl;
    return 0;
}
#include <bits/stdc++.h>
#define FOR(i, a, b)  for(int i = (a); i < (b); i++)
#define ll long long
#define f first
#define s second
#define pb push_back
using namespace std;

int main (){
    freopen("/Users/zoezhang/Documents/Home/C/2024/adventOfCode/day1.txt", "r", stdin);
    ll a=0, b=0;

    vector<ll>as, bs;
    unordered_map<int, int> m;
    while(cin>>a>>b){
        as.pb(a); bs.pb(b);
        if (m.find(b) == m.end()) m.insert({b, 1});
        else m.find(b)->second+=1;
        //;
    }

    ll sum = 0;
    FOR(i, 0, as.size()){
        if (m.find(as[i])!=m.end()) sum += as[i]*m.find(as[i])->second;
    }

    cout<<sum<<endl;

    /*
    sort(as.begin(), as.end());
    sort(bs.begin(), bs.end());
    ll sum=0;
    FOR(i, 0, 1000)
        sum+=max(as[i],bs[i]) - min(as[i], bs[i]);
    }
    cout<<sum;
    */
}
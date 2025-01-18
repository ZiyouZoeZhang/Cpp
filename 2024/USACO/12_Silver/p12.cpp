#include <bits/stdc++.h>
#define FOR(i, a, b)  for(int i = (a); i < (b); i++)
#define ll long long
//#define f first
//#define s second
#define pb push_back
using namespace std;

int T;

void solve(){
    int N; cin>>N;
    vector<ll> vec(N), pre(N+1, 0), back(N+1, 0);
    ll sum = 0;

    FOR(i, 0, N){
        cin>>vec[i];
        sum+=vec[i];
        if (i!=0) pre[i+1]=vec[i] + pre[i];
        else pre[i+1]=vec[i];
    }

    for(int j=N-1; j>=0; j--){
        if (j==N-1) back[j] = vec[j];
        else back[j] = back[j+1] + vec[j];
    }

    ll num = N/2-1;
    ll eats = 0;

    FOR(i, 0, num+1){
        eats = max(eats, pre[i] + back[N-(num-i)]);
    }

    //2 - east N/2-1

   /*
    FOR(i, 0, N/2-1){
        eats+=vec[b[i]];
    }
*/ 
    cout<<sum-eats<<" "<<eats<<endl;

}

int main(){
    cin>>T;
    int N;
    FOR(i, 0, T){
        solve();
    }

    return 0;

}
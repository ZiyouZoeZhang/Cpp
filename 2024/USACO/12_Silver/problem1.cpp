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
    vector<int> vec(N), b;
    ll sum = 0;
    FOR(i, 0, N){
        cin>>vec[i];
        sum+=vec[i];
    }

    int i=0, j=N-1;
    while(i!=j){
        if (vec[i]>vec[j]) b.pb(i), i++;
        else b.pb(j), j--;
    }
    b.pb(j);
    

    //2 - east N/2-1
    ll eats = 0;
    FOR(i, 0, N/2-1){
        eats+=vec[b[i]];
    }

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
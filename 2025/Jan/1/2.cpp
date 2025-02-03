//final
#include <bits/stdc++.h>
#define FOR(i, a, b)  for(ll i = (a); i < (b); i++)
#define ll long long
#define f first
#define s second
#define pb push_back
using namespace std;

vector<ll> ss(ll N){
    vector<ll> same(N, 0);

    if (N%2!=0){
        same[0] = (N-1)*(N)/2 +1;
        ll count = ((N/2))*2;

        FOR(i, 1, N){
            count -= 2;
            same[i] = same[i-1]-count;
            if(i==N/2){
                count += 2;
            }
        }
        if(N==2){
            same[0] = 2;
            same[1] = 2;
        }
        
    }else{
        same[0] = (N-1)*(N)/2 +1;
        ll count = ((N/2))*2-1;

        FOR(i, 1, N){
            count -= 2;
            same[i] = same[i-1]-count;
            if (i==N/2 -1){
                same[N/2] = same[N/2 -1];
                i++;
            }

        }
    }

    return same;
}


int main(){
    ll N; cin>>N;

    vector<ll> same = ss(N);

    vector<ll> v(N), v2(N);
    vector<vector<ll>> pos(N+10, vector<ll>());
    vector<vector<ll>> pre(N+10, vector<ll>());
    vector<vector<ll>> closer(N+10, vector<ll>());
    //vector<pair<ll, ll>> n[500020];

    FOR(i, 0, N){
        cin>>v[i];
    }

    FOR(i, 0, N){
        cin>>v2[i];
        pos[v2[i]].pb(i);
        closer[v2[i]].pb(min(i+1, N-i)); //place and closer
    }

    FOR(i, 0, closer.size()){
        sort(closer[i].begin(), closer[i].end());
    }

    FOR(i, 0, closer.size()){
        ll cur = 0;
        FOR(j, 0, closer[i].size()){
            pre[i].pb(cur);
            cur+=closer[i][j];
        }
        pre[i].pb(cur);
    }

    ll ans = 0;

    FOR(i, 0, N){
        ll x = upper_bound(closer[v[i]].begin(), closer[v[i]].end(), min(i+1, N-i))-closer[v[i]].begin();

        ans += pre[v[i]][x];
        ans += (closer[v[i]].size()-x)*min(i+1, N-i);

        if (v[i]==v2[i]){
            ans += (same[i]-min(i+1, N-i));
        }
    }

    cout<<ans<<endl;
    return 0;
}
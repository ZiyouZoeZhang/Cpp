#include <bits/stdc++.h>
#define INF 0x3f3f3f3f3f3f3f3f
#define ll long long
using namespace std;

int main (){
    ll N, M, K, Q;
    cin>>N>>M>>K>>Q;

    ll dist[N][N]; //>
   // ll adj[N][N]; 

    for (ll i=1; i<=N; i++){
        for (ll j=1; j<=N; j++){
            if (i==j) dist[i][j] = 0;
            else dist[i][j] = INF;
        }
    }

    for (ll i=0; i<M; i++){
        ll a, b, w;
        cin>>a>>b>>w;
        //adj[a][b]=w;
        dist[a][b]=w;
    }

    for (ll k=1; k<=N; k++){
        for (ll i=1; i<=N; i++){
            for (ll j=1; j<=N; j++){
                dist[i][j] = min (dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    for (ll i=0; i<Q; i++){
        ll a, b;
        cin>>a>>b;
        cout<<dist[a][b];
    }

    return 0;

    
}
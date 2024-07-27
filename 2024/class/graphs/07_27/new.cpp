#include <bits/stdc++.h>
#define INF 0x3f3f3f3f3f3f3f3f
#define ll long long
using namespace std;

int main (){
    ll N, M, Q;
    cin>>N>>M>>Q;

    ll dist[501][501];
//    ll adj[N][N];

memset(dist, INF, 501);

    for (ll i=1; i<=M; i++){
        for (ll j=1; j<=M; j++){
            if (i==j) dist[i][j] = 0;
            else dist[i][j] = INF;
        }
    }

    for (ll i=0; i<M; i++){
        int a, b, w;
        cin>>a>>b>>w;
        //cout<<a<<b<<w;
        dist[a][b]=w;
        dist[b][a]=w;
    }

    for (ll k=1; k<=M; k++){
        for (ll i=1; i<=M; i++){
            for (ll j=1; j<=M; j++){
                dist[i][j] = min (dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    for (ll i=0; i<Q; i++){
        ll a, b;
        cin>>a>>b;
        cout<<endl<<dist[a][b]<<endl;
    }

    return 0;
}
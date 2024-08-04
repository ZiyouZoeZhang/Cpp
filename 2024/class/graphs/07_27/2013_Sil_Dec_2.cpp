//vacation planning
//https://usaco.org/index.php?page=viewproblem2&cpid=362
//https://www.luogu.com.cn/problem/P3094

//if INF isn't negative
//passed!

#include<bits/stdc++.h>
#define INF 0x3f3f3f3f3f3f3f3f
#define ll long long
//#define cin fin
//#define cout fout
using namespace std;
ll N, M, K, Q;
ll dist[200][200]; 

//ofstream fout ("vacation.out");
//ifstream fin ("vacation.in");

void floyd(){
    for (ll i=0; i<N; i++){
        for (ll j=0; j<N; j++){
            if (i==j) dist[i][j] = 0;
            else dist[i][j] = INF;
        }
    }

    for (ll i=0; i<M; i++){
        ll a, b, c;
        cin>>a>>b>>c;
        a--; b--;
        dist[a][b] = min(dist[a][b], c);
    }

    for (ll k=0; k<N; k++){
        for (ll i=0; i<N; i++){
            for (ll j=0; j<N; j++){
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
}

int main (){
    cin>>N>>M>>K>>Q;

    floyd();

    ll count=0;
    ll total=0;
    
    for (ll i=0; i<Q; i++) {
        ll a, b;
        cin>>a>>b;
        a--; b--;
        
        ll mi = INF;
        for (ll k = 0; k < K; k++) {
            mi = min(mi, dist[a][k] + dist[k][b]);
        }
        
        if (mi != INF) {
            count++;
            total+= mi;
        }
    }
    
    cout<<count<<endl<<total<<endl;
    return 0;
}
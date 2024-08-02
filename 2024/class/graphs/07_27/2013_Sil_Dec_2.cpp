//vacation planning
//https://usaco.org/index.php?page=viewproblem2&cpid=362
#include<bits/stdc++.h>
#define INF 0x3f3f3f3f
#define cin fin
#define cout fout
using namespace std;
int N, M, K, Q;
int dist[200][200]; 

ofstream fout ("vacation.out");
ifstream fin ("vacation.in");

void floyd(){
    for (int i=0; i<N; i++){
        for (int j=0; j<N; j++){
            if (i==j) dist[i][j] = 0;
            else dist[i][j] = INF;
        }
    }

    for (int i=0; i<M; i++){
        int a, b, c;
        cin>>a>>b>>c;
        a--; b--;
        dist[a][b] = min(dist[a][b], c);
    }

    for (int k=0; k<N; k++){
        for (int i=0; i<N; i++){
            for (int j=0; j<N; j++){
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
}

int main (){
    cin>>N>>M>>K>>Q;
    floyd();

    int count=0;
    int total=0;
    
    for (int i=0; i<Q; i++) {
        int a, b;
        cin>>a>>b;
        a--; b--;
        
       int mi = INF;
        for (int k = 0; k < K; k++) {
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
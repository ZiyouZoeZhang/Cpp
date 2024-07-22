#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;

ofstream fout ("piggyback.out");
ifstream fin ("piggyback.in");

vector<int> adj[40010];
int B, E, P, N, M;

vector<int> bfs(int x) {
    vector<int> dist (40010, INF);
    queue<int>q;
    q.push(x);
    dist[x]=0;
    while (!q.empty()){
        int a=q.front(); q.pop();
        for (auto b: adj[a]){
            if (dist[b]==INF){
                dist[b]=dist[a]+1;
                q.push(b);
            }
        }
    }
    return dist;
}

int main () {
    fin>>B>>E>>P>>N>>M;

    for (int i=0; i<M; i++){
       int a, b;
       fin>>a>>b;
       adj[a].push_back(b);
       adj[b].push_back(a); 
    }

    vector<int> distB = bfs(1);
    vector<int> distE = bfs(2);
    vector<int> distP = bfs(N);

    int m=INF;
    for (int i=1; i<=N ;i++){
        m = min(m, (distB[i]*B)+ (distE[i]*E) + (distP[i]*P));
    }
    
    fout<<m<<endl;
}
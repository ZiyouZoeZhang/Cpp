//https://cses.fi/problemset/task/1193
//define INF 0x3f3f3f3f

#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define f first
#define s second
using namespace std;

int adj[1010][1010];
int dist[1010][1010];
int parent[1010][1010];
int N, M;
pair<int, int> start, ending;

int dx[] = {0, 1, 0,  -1};
int dy[] = {1, 0, -1, 0};
char d[] = {'U', 'L', 'D', 'R'};

void bfs (pair<int, int> x){
    queue<pair<int, int>> q;
    q.push(x);
    dist[x.f][x.s] = 0;

    while (!q.empty()){
        pair<int, int> a = q.front(); q.pop();
        for (int i=0; i<4; i++){
            if (dist[a.f+dx[i]][a.s+dy[i]]==INF && adj[a.f+dx[i]][a.s+dy[i]]==1){ //not visited & valid
                dist[a.f+dx[i]][a.s+dy[i]]=dist[a.f][a.s]+1;
                parent[a.f+dx[i]][a.s+dy[i]]=i;
                q.push(make_pair(a.f+dx[i], a.s+dy[i]));
            }
        }
    }
}

int main (){
    memset(dist, INF, sizeof(dist));
    memset(adj, INF, sizeof(adj));
    cin>>N>>M;
    for (int i=0; i<N; i++){
        for (int j=0; j<M; j++){//o-> no, 1-> yes
            char a;
            cin>>a;
            a=='#' ? adj[i][j]=0 : adj[i][j]=1;
            if (a=='A') start=make_pair(i, j);
            if (a=='B') ending=make_pair(i, j);
        }
    }

    bfs(start);

    if (dist[ending.f][ending.s] == INF){
        cout<<"NO"<<endl;
        return 0;
    }
    cout<<"YES"<<endl;
    
    cout<<dist[ending.f][ending.s]<<endl;
    stack<int> stck;
    int cx = ending.f, cy=ending.s;
    while (dist[cx][cy]!=0){
        stck.push(parent[cx][cy]);
        int temp = cx;
        cx-=dx[parent[cx][cy]];
        cy-=dy[parent[temp][cy]];
    }

    while (!stck.empty()){
        cout<<d[3-stck.top()];
        stck.pop();
    }
    cout<<endl;
    return 0;
}
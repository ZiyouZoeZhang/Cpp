//https://usaco.org/index.php?page=viewproblem2&cpid=717
#include<bits/stdc++.h>
#define INF 0x3f3f3f3f
#define INFL  0x3f3f3f3f3f3f3f3f
#define ll long long
using namespace std;

int adj[100][100];
ll dist[100][100];
int vis[100][100] = {false};

int dx[16]={-3,-2,-2,-1,-1,-1,0,0,0,0,1,1,1,2,2,3};
int dy[16]={0,-1,1,-2,0,2,-3,-1,1,3,-2,0,2,-1,1,0};
int N, T;

ofstream fout ("visitfj.out");
ifstream fin ("visitfj.in");

int dij(int x, int y){

    priority_queue<tuple<int, int, int>> q; //priority, x, y;
    q.push(make_tuple(0, x, y));
    dist[x][y]=0;
    while (!q.empty()){
        int ax = get<1>(q.top()), ay = get<2>(q.top()); q.pop();
        if (vis[ax][ay]) continue;
        vis[ax][ay]= true;

        //if very close to final place
        //looking at ax, ay and the distance to final N-1, N-1
        if ((N-1 - ax)+(N-1 - ay)<3) {
            dist[N-1][N-1]= dist[ax][ay] + (((N-1 - ax)+(N-1 - ay))*T);
            return 0;
        }

        //else
        for (int i=0; i<16; i++) {
            int bx = ax+dx[i], by = ay+dy[i];
            if (bx>=0 && bx<N && by>=0 && by<N) {
                dist[bx][by] = min (dist[bx][by], dist[ax][ay] + 3*T + adj[bx][by]);
                q.push (make_tuple(-dist[bx][by], bx, by));
            } 
        }
    }
    return 0;
}

int main(){
    memset(dist, INF, sizeof(dist[0][0]) * 100 * 100);

    cin>>N>>T;

    for (int i=0; i<N; i++){
        for (int j=0; j<N; j++){
            int g;
            cin>>g;
            adj[i][j]=g;
        }
    }

    dij(0, 0);

    cout<<dist[N-1][N-1]<<endl;
    return 0;
}
//https://usaco.org/index.php?page=viewproblem2&cpid=717
#include<bits/stdc++.h>
#define INF 0x3f3f3f3f
#define INFL  0x3f3f3f3f3f3f3f3f
#define ll long long
using namespace std;

int adj[100][100];
ll dist[100][100];
int vis[100][100] = {false};
int cou[100][100] = {4};


int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int N, T;

void dij(int x, int y){

    priority_queue<tuple<int, int, int>> q; //priority, x, y;
    q.push(make_tuple(0, x, y));
    cou[x][y]=0;
    dist[x][y]=0;
    while (!q.empty()){
        int ax = get<1>(q.top()), ay = get<2>(q.top()); q.pop();
        if (vis[ax][ay]) continue;
        vis[ax][ay]= true;
        for (int i=0; i<4; i++) {
            int bx=ax+dx[i], by = ay+dy[i];
            if (bx>=0 && bx<N && by>=0 && by<N){
                if (cou[ax][ay]==2){
                    /*
                    if (dist[ax][ay] + T + adj[bx][by] <= dist[bx][by]){
                        dist[bx][by] = dist[ax][ay] + T + adj[bx][by];
                        cou[bx][by]=0;
                        //q.push (make_tuple(-dist[bx][by], bx, by));
                    }
                    */
                    
                    cou[bx][by]=0;
                    dist[bx][by] = min (dist[bx][by], dist[ax][ay] + T + adj[bx][by]);
                } else {
                    //dist[bx][by] = dist[ax][ay] + T;
                    //cou[bx][by]=cou[ax][ay]+1;
                    //q.push (make_tuple(-dist[bx][by], bx, by));


                    /*if (dist[ax][ay] + T <= dist[bx][by]){
                        dist[bx][by] = dist[ax][ay] + T;
                        cou[bx][by]=+1;
                        //q.push (make_tuple(-dist[bx][by], bx, by));
                    }*/
                    
                    cou[bx][by]=cou[ax][ay]+1;
                    dist[bx][by] = min (dist[bx][by], dist[ax][ay] + T);
                }
                q.push (make_tuple(-dist[bx][by], bx, by));
            } 
        }
    }
}

int main(){

    memset(dist, INF, sizeof(dist[0][0]) * 100 * 100);
    memset(cou, 4, sizeof(cou[0][0]) * 100 * 100);

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
#include<bits/stdc++.h>
using namespace std;
//https://cses.fi/problemset/task/1192/
int N, M;
char adj[1000][1000];
bool vis[1000][1000];

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void dfs(int i, int j){
    if (i>-1 && i<N && j>-1 && j<M && adj[i][j] == '.' && !vis[i][j]) {
        vis[i][j] = true;
        for (int x = 0; x<4; x++){
            dfs(i+dx[x], j+dy[x]);
        }
    }
    return;
}

int main(){
    cin>>N>>M;
    memset(vis, false, N);
    for (int i=0; i<N; i++){
        for (int j=0; j<M; j++){
            cin>>adj[i][j];
        }
    }

    int c = 0;
    for (int i=0; i<N; i++){
        for (int j=0; j<M; j++){
            if (adj[i][j] == '.' && !vis[i][j]){
                dfs(i, j);
                c++;
            }
        }
    }
    cout<<c<<endl;
}
//https://cses.fi/problemset/task/1668
#include<bits/stdc++.h>
using namespace std;
vector<int> adj[100010];
bool vis[100010];
int col[100010];
int N, M;
bool yes = true;

void dfs(int a, int i){
    if ( col[a]!= 0 && col[a] != i ) {yes=false;}
    if ( col[a]!= 0 ) {return;}
    col[a] = i;
    for (auto b: adj[a]) {
        (i==1) ? dfs(b, 2) : dfs(b, 1);
    }
}

int main (){
    cin>>N>>M;
    memset(vis, false, N);
    memset(col, 0, N);
    for (int i=0; i<M; i++){
        int a, b;
        cin>>a>>b;
        adj[--a].push_back(--b);
        adj[b].push_back(a);
    }

    for (int i=0; i<N; i++){
        if (col[i] != 0) {continue;}
        dfs(i, 1);
    }

    if (!yes) cout<<"IMPOSSIBLE"<<endl;
    else {
        for (int i=0; i<N; i++){
            cout<<col[i]<<" ";
        }
        cout<<endl;
    }

    return 0;
}

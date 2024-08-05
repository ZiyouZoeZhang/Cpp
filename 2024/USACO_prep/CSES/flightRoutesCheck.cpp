#include<bits/stdc++.h>
using namespace std;
//https://cses.fi/problemset/task/1682/

vector<int> adj[100010][2];
bool vis[100010];
int N, M;

void dfs(int a, int x){
    if (vis[a]) {return;}
    vis[a] = true;
    for (auto b: adj[a][x]) dfs(b, x);
}

int main (){
    cin>>N>>M;
    memset(vis, false, N);
    for (int i=0; i<M; i++){
        int a, b;
        cin>>a>>b;
        adj[--a][0].push_back(--b);
        adj[b][1].push_back(a);
    }

    dfs(0,0);

    for (int i=0; i<N; i++){
        if (!vis[i]){
            cout<<"NO"<<endl;
            cout<<"1 "<<i+1<<endl;
            return 0;
        }
    }

    memset(vis, false, N);
    dfs(0,1);
    for (int i=0; i<N; i++){
        if (!vis[i]){
            cout<<"NO"<<endl;
            cout<<i+1<<" 1"<<endl;
            return 0;
        }
    }

    cout<<"YES"<<endl;

    return 0;

}
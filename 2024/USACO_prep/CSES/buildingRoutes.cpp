//https://cses.fi/problemset/task/1666
//done!
#include <bits/stdc++.h>
using namespace std;
int N, M;
vector<int> adj[100010];
vector<int> output;
bool vis[100010];

void dfs(int i){
    if (vis[i]){return;}
    vis[i] = true;
    for (auto v: adj[i]) dfs(v);
}

int main (){
    cin>>N>>M;
    for (int i=0; i<M; i++){
        int a, b;
        cin>>a>>b;
        adj[--a].push_back(--b);
        adj[b].push_back(a);
    }
    
    memset(vis, false, N);

    for (int i=0; i<N; i++){
        if (!vis[i]){
            output.push_back(i);
            dfs(i);
        }
    }
    cout<<output.size()-1<<endl;
    for (int i=1; i<output.size(); i++){
        cout<<"1 "<<output[i]+1<<endl;
    }
}


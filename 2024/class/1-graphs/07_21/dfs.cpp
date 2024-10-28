#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> adj[100010]; //adjacent list
bool visited[100010];

int main (){
    cin>>n>>m;
    for (int i=0; i<m; i++){
        int a, b;
        adj[a].push_back(b);
    }
    return 0;
}

void dfs_recursive(int x){ // x-> starting position
    if (visited) return;
    for (auto i: adj[x]){
        dfs_recursive(i);
    }
    visited[x]=true;
    return;
}

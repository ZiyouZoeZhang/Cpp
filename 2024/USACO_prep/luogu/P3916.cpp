//https://www.luogu.com.cn/problem/P3916
//reverse dfs
#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<int> adj[100010]; //adjencency list
vector<int> v(100010, -1); //val of max reached 

void dfs1(int i, int cur){
    if (v[i] != -1) {return;}
    v[i] = cur;
    for (auto j: adj[i]) dfs1(j, cur);
}

int main (){
    cin>>N>>M;

    for (int i=0; i<M; i++){
        int a, b;
        cin>>a>>b;
        adj[b].push_back(a);
    }

    for (int i=N; i>0; i--){
        if (v[i] == -1) dfs1(i, i);
    }

    for (int i=1; i<=N; i++){
        cout<<v[i]<<" ";
    }

    return 0;
}
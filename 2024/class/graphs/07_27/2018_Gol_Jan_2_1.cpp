//https://www.luogu.com.cn/problem/P4186
//https://usaco.org/index.php?page=viewproblem2&cpid=790
//cow at large
//after modification

#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;

ofstream fout ("atlarge.out");
ifstream fin ("atlarge.in");

int main (){

    int N, K;
    cin>>N>>K;

    vector<vector<int>> adj(N); //adjacency vector
    vector<bool> vis(N, false);
    queue<int> q;

    for (int i=0; i<N-1; i++){
        int a, b;
        cin>>a>>b;
        adj[--a].push_back(--b);
        adj[b].push_back(a);
    }
   
    //prep
    int depth[N];
    int depth1[N];

    memset(depth, INF, N);
    memset(depth1, INF, N);

    q.push(K); //initial starting point of bessie
    vis[K]=true;
    depth[K] = 0;

    //bfs
    while (!q.empty()){
        int a = q.front(); q.pop();
        for (auto b: adj[a]) {
            if (depth[a] + 1 < depth[b]){
                depth[b] = depth[a]+1;
                q.push(b);
            }
        }
    }

    //放叶子结点
    for (int i=0; i<N; i++) {
        if (adj[i].size()==1){
            q.push(i);
            depth1[i] = 0;
        }
    }
    //找叶子结点倒每个节点的距
    while (!q.empty()){
        int a = q.front(); q.pop();
        for (auto b: adj[a]) {
            if (depth1[a] + 1 < depth1[b]){
                depth1[b] = depth1[a] + 1;
                q.push(b);
            }
        }
    }
    
    //code
    int c = 0; //count of how many bessie are caught by farmers
    q.push(K); //initial starting point of bessie
    vis[K]=true;

    while (!q.empty()){
        int a = q.front(); q.pop();
        if (depth[a] >= depth1[a]) {
            c++;
            continue;
        }
        if (vis[a]) continue;
        vis[a] = true;
        for (auto b: adj[a]){
            q.push(b);
        }
    }

    cout<<c<<endl; //end
}
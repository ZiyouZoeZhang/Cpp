//https://cses.fi/problemset/task/1667 
#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define ll long long
using namespace std;

vector<int> adj[200010];
bool visited[200010];
int dist[200010];
int parent[200010];
int n, m;

void bfs(int x){
    queue<int> q;
    dist[x]=1;
    q.push(x);
    while (!q.empty()) {
        int a=q.front(); q.pop();
        for (auto b: adj[a]){
            if (dist[b]!=INF) continue; //visited /updated
            dist[b]=dist[a]+1;
            parent[b]=a;
            q.push(b);
        }
    }
}


void bfs2(int x){
    queue<int> q;
    q.push(q);
    while (!q.empty()){
        int a=q.top(); q.pop();
        for (auto b: adj[a]){
            if (dist[b]!=INF){//unprocessed
                dist[b]=dist[a]+1;
                q.push(b);
                parent[b]=a;
            }
        }
    }
}


int main(){
    memset(dist, INF, sizeof(dist));
    //updated
    cin>>n>>m;
    for (int i=0; i<m; i++){
        int a, b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    bfs(1);

    if (dist[n]==INF){
        cout<<"IMPOSSIBLE"<<endl; 
        return 0;
    }
    
    cout<<dist[n]<<endl;

    stack<int> s;
    s.push(n);
    while (s.top()!=1){
        s.push(parent[s.top()]);
    }

    while (!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }

}




/*
//https://cses.fi/problemset/task/1667 
#include <bits/stdc++.h>
using namespace std;
 
vector<int> adj[200010];
int dist[200010];
int parent[200010];
 
int main() {
 int N, M;
 cin >> N >> M;
    memset(dist,0x3f,sizeof(dist)); //将数组dist中所有元素的值设置为0x3f3f3f3f
 
 for(int i = 0 ; i < 200010; i++){
  dist[i] = 0x3f3f3f3f;
 }
 
 while (M--) {
  int a, b;
  cin >> a >> b;
  adj[a].push_back(b);
        adj[b].push_back(a);
 }
 queue<int> q;
 dist[1] = 0;
 q.push(1);
 while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (int t : adj[x]){
            if (dist[t] == 0x3f3f3f3f) {
                dist[t] = dist[x] + 1;
                parent[t] = x;
                q.push(t);
            }    
        }
 }
 if (dist[N] == 0x3f3f3f3f) cout << "IMPOSSIBLE";
 else {
  cout << dist[N] + 1 << "\n";
  vector<int> v;
        v.push_back(N);
  while (v.back() != 1) v.push_back(parent[v.back()]);
  reverse(begin(v), end(v));
  for (int t : v) cout << t << " ";
 }
}

*/
/*
Part1  图基础知识复习。
    1、图的组成与分类，
    2、图的三种存储方法（邻接表，邻接矩阵，边表）；
    3、pair结构，
    4、图的2种遍历方法；
Part2  无权图的最短距离。 
    1、BFS算法实现；
    2、基于BFS算法获取最短距离轨迹；
Part3 有全图的最短距离之Dijkstra算法。
    1、算法步骤与C++实现；
    2、应用场景；
    3、时间复杂度分析；
    4、基于起点与终点以及边为单位拆分最短距离；
    5、改造Dijkstra算法使其经过最小权值边；
    6、最短距离中的添加辅助线（边）应用。
*/

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
 //parent
 while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (int t : adj[x]){
            if (dist[t] == 0x3f3f3f3f) {
                dist[t] = dist[x] + 1;
                parent[t] = x;
                q.push(t);
                //parent[]
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

#include <bits/stdc++.h>

using namespace std;

#define ii pair<int, int>
#define f first
#define s second
#define mp make_pair

int n, m;
char A[1000][1000];
bool vis[1000][1000];

// previousStep stores the previous direction that we moved in to arrive that
// this cell
int previousStep[1000][1000];

// 0 = up, 1 = right, 2 = down, 3 = left
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
string stepDir = "URDL";

int main() {
 cin >> n >> m;

 queue<ii> q;
 ii begin, end;
 for (int i = 0; i < n; i++) {
  for (int j = 0; j < m; j++) {
   cin >> A[i][j];
   if (A[i][j] == 'A') {
    begin = mp(i, j);
   } else if (A[i][j] == 'B') {
    end = mp(i, j);
   }
  }
 }

 q.push(begin);
 vis[begin.f][begin.s] = true;

 while (!q.empty()) {
  ii u = q.front();
  q.pop();
  for (int i = 0; i < 4; i++) {
   ii v = mp(u.f + dx[i], u.s + dy[i]);
   if (v.f < 0 || v.f >= n || v.s < 0 || v.s >= m) continue;
   if (A[v.f][v.s] == '#') continue;
   if (vis[v.f][v.s]) continue;
   vis[v.f][v.s] = true;
   previousStep[v.f][v.s] = i;
   q.push(v);
  }
 }

 if (vis[end.f][end.s]) {
  cout << "YES" << endl;
  vector<int> steps;
  while (end != begin) {
   int p = previousStep[end.f][end.s];
   steps.push_back(p);
   // undo the previous step to get back to the previous square
   // Notice how we subtract dx/dy, whereas we added dx/dy before
   end = mp(end.f - dx[p], end.s - dy[p]);
  }
  reverse(steps.begin(), steps.end());

  cout << steps.size() << endl;
  for (char c : steps) { cout << stepDir[c]; }
  cout << endl;
 } else {
  cout << "NO" << endl;
 }

 return 0;
}
/*

Part1 第1次课程内容的复习。
    1、无权图的最短距离及轨迹算法（BFS）； 
    2、有权图单源最短距离算法（Dijkstra）；
    3、最短距离的拆分思路；
Part2  第1次课程课后作业题讲解。
    1、边表的存储以及遍历；
    2、FloodFill算法学习；
    3、基于优先级队列结构计算平面最短距离以及记忆化存储思路；
    4、图结构中的辅助线添加思路；
Part3、有全图的最短距离之Floyd-Warshall算法。
    1、存储、算法步骤与C++实现；
    2、应用场景；
    3、时间复杂度分析；
    4、例题Shortest Routes II/Vacation Planning分析；
Part4、Dijkstra算法的扩展
    1、最短距离的父节点存储以及轨迹；
    2、字典序最短距离；
    3、相同距离的处理。
*/

#include <bits/stdc++.h>
#define INF 0x3f3f3f3f3f3f3f3f
#define ll long long
using namespace std;

int main (){
    ll N, M, K, Q;
    cin>>N>>M>>K>>Q;

    ll dist[N][N]; //>
   // ll adj[N][N]; 

    for (ll i=1; i<=N; i++){
        for (ll j=1; j<=N; j++){
            if (i==j) dist[i][j] = 0;
            else dist[i][j] = INF;
        }
    }

    for (ll i=0; i<M; i++){
        ll a, b, w;
        cin>>a>>b>>w;
        //adj[a][b]=w;
        dist[a][b]=w;
    }

    for (ll k=1; k<=N; k++){
        for (ll i=1; i<=N; i++){
            for (ll j=1; j<=N; j++){
                dist[i][j] = min (dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    for (ll i=0; i<Q; i++){
        ll a, b;
        cin>>a>>b;
        cout<<dist[a][b];
    }

    return 0;

    
}
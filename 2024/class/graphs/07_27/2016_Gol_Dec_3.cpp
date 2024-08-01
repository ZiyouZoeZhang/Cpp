//https://usaco.org/index.php?page=viewproblem2&cpid=671
//非常难评。。。

#include <bits/stdc++.h>
#define f first
#define s second
#define ll long long
//#define INF 0x3f3f3f3f3f3f3f3f
#define INF 0x3f3f3f3f
using namespace std;

int N;
pair<int, int> L, B;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

int main (){
    cin>>N;
    N+=2;
    vector<pair<int, int>> v1;
    for (int i=0; i<N; i++){
        int x, y;
        cin>>x>>y;
        v1.push_back(make_pair(x, y));
    }
    L = v1[0]; B = v1[1];

    //compression
    map<int, int> mx, my;
    sort(v1.begin(), v1.end());
    int a=0;
    for (int i=0; i<N; i++) if (mx.find(v1[i].f) == mx.end()) mx[v1[i].f]=a++;
    int b=0;
    sort(v1.begin(), v1.end(), [](const pair<int, int>a, const pair<int, int>b){return a.s<b.s;});
    for (int i=0; i<N; i++) if (my.find(v1[i].s) == my.end()) my[v1[i].s]=b++;
/*
    vector<pair<int, int>> v(N);

    for (int i=0; i<N; i++){
        v[i].f = mx[v1[i].f];
        v[i].s = my[v1[i].s];
    }
*/
    //-------
    
    vector<vector<int>> adj (a, vector<int>(b, 0));
    vector<vector<vector<int>>> dis (a, vector<vector<int>>(b, vector<int>(4, INF)));
    for (int i=0; i<N; i++){
        //cout<<mx[v1[i].f]<<" "<<my[v1[i].s]<<endl;
        adj[mx[v1[i].f]][my[v1[i].s]] = 1;
    }

    queue<tuple<int, int, int>> q;
    dis[mx[L.f]][my[L.s]][0] = 0;
    dis[mx[L.f]][my[L.s]][3] = 0;
    q.push({mx[L.f], my[L.s], 0});
    q.push({mx[L.f], my[L.s], 3});

    while (!q.empty()){
        int ax = get<0>(q.front()), ay = get<1>(q.front()), aw = get<2>(q.front()); q.pop();
        for (int i=0; i<4; i++){
            int bx = ax+dx[i], by = ay+dy[i];
            if((bx>-1 && bx<a && by>-1 && by<b) && dis[bx][by][i]==INF) {//not visited && valid
                if (adj[bx][by]==0 || i==aw){
                    dis[bx][by][i] = min (dis[bx][by][i], dis[ax][ay][aw]);
                    q.push({bx, by, i});
                }
                else if (dx[i]!=-dx[aw] || dy[i]!=-dy[aw]) {

                    dis[bx][by][i] = min (dis[bx][by][i], dis[ax][ay][aw]+1); 
                    q.push({bx, by, i});
                }
            }
        }
        
    }

    int minimum = INF;
    for (int i=0; i<4; i++){
        minimum = min(minimum, dis[mx[B.f]][my[B.s]][i]);
    }
    cout<<minimum<<endl;

    
    return 0;


    
}
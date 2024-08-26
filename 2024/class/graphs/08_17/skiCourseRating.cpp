//https://usaco.org/current/current/index.php?page=viewproblem2&cpid=384
//doesn't work yayy
#include <bits/stdc++.h>
#define ll long long
#define f first
#define s second
using namespace std;

ifstream fin ("/Users/zoezhang/Documents/Home/C/2024/class/graphs/08_17/1.in");

/*
struct p {
    int d;
    int i;
    int j;
    bool operator<(p const& other) {
        return d < other.d;
    }
}*/

struct comp {
    bool operator()(const pair<int, pair<int, int>> & a, const pair<int, pair<int, int>> & b)
    {
        return a.f>b.f;
    }
};

int N, M, T;
vector<vector<ll>> v1;
vector<vector<bool>> v2;
vector<vector<int>> v3;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

bool outOfBounds (int i, int j){
    return (i<0 || i>=N || j<0 || j>=M);
}

int rate(int x, int y){
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, comp> pq;
    vector<vector<bool>> vis(N, vector<bool>(M, false));
    pq.push({0, {x, y}});

    int c = 0;
    int d = 0;

    while (c<T){
        d = max(d, pq.top().f);
        int i = pq.top().s.f, j = pq.top().s.s; pq.pop();
        if (vis[i][j]) continue;
        if (d>=v3[i][j]) return d;
        vis[i][j] = true;
        c++;

        for (int d = 0; d<4; d++){
            int newi = i+dx[d], newj = j+dy[d];
            if (!outOfBounds(newi, newj)){
                pq.push( {max(v1[i][j], v1[newi][newj]) - min(v1[i][j], v1[newi][newj]) ,{newi, newj} } );
            }
        }
    }
    return d;
}

int main (){
    cin>>N>>M>>T;

    v1.resize(N, vector<ll> (M));
    v2.resize(N, vector<bool> (M));
    v3.resize(N, vector<int> (M, 0x3f3f3f3f));

    for (int i=0; i<N; i++){
        for (int j=0; j<M; j++){
            cin>>v1[i][j];
        }
    }

    ll total = 0;

    for (int i=0; i<N; i++){
        for (int j=0; j<M; j++){
            int a; cin>>a; 
            v2[i][j] = (a==1) ? true : false;
            if (a ==1){
                v3[i][j] = rate(i, j);
                total += v3[i][j];
            }
        }
    }
    cout<<total<<endl;
    return 0;
}
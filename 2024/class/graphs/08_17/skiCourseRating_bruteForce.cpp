#include <bits/stdc++.h>
#define ll long long
#define f first
#define s scond
using namespace std;

int N, M, T;
vector<vector<ll>> v1;
vector<vector<bool>> v2;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

bool outOfBounds (int i, int j){
    return (i<0 || i>=N || j<0 || j>=M);
}

int rate(int x, int y){
    int c = 0, d = 0;
    //priority_queue<tuple<int, int, int>> pq; //difference, pre_value, x, y
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
    //bool vis[N][M];
    vector<vector<bool>> vis(N, vector<bool>(M, false));
    //memset(vis, false, N*M);

    pq.push({0, x, y});

    while (c<T) {
        d = max(d, (get<0>(pq.top())));
        int i = get<1>(pq.top()), j = get<2>(pq.top()); 
        pq.pop();

        if (vis[i][j]) continue;
        vis[i][j] = true;
        c++;

        for (int a=0; a<4; a++){
            int newi = i+dx[a], newj = j+dy[a];
            if (!outOfBounds(newi, newj)){
                pq.push({(max(v1[i][j], v1[newi][newj]) - min(v1[i][j], v1[newi][newj])), newi, newj});
            }
        }
    }

    return d;
}

int main (){
    cin>>N>>M>>T;

    v1.resize(N, vector<ll> (M));
    v2.resize(N, vector<bool> (M));

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
                total += rate(i, j);
            }
        }
    }
    cout<<total<<endl;
    return 0;
}
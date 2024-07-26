//https://usaco.org/index.php?page=viewproblem2&cpid=1063
#include<bits/stdc++.h>
#define f first
#define s second
#define ll long long
using namespace std;

int main (){
    int N;
    cin>>N;

    vector<pair<int, int>> v1;
    for (int i=0; i<N; i++){
        int x, y;
        cin>>x>>y;
        v1.push_back(make_pair(x, y));
    }

    //compression
    map<int, int> mx, my;
    sort(v1.begin(), v1.end());
    for (int i=0; i<N; i++) mx[v1[i].f]=i;
    sort(v1.begin(), v1.end(), [](const pair<int, int>a, const pair<int, int>b){return a.s<b.s;});
    for (int i=0; i<N; i++) my[v1[i].s]=i;

    vector<pair<int, int>> v(N);

    for (int i=0; i<N; i++){
        v[i].f = mx[v1[i].f] + 1;
        v[i].s = my[v1[i].s] + 1;
    }
    //-------

    //prefix sum
    vector<vector<int>> ps (N+1, vector<int>(N+1, 0));
    for (int i=0; i<N; i++){
        ps[v[i].f][v[i].s]++;
    }

    for (int i=1; i<N+1; i++){
        for (int j=1; j<N+1; j++){
            ps[i][j] = ps[i][j] + ps[i-1][j] + ps[i][j-1] - ps[i-1][j-1];
        }
    }

    //final
    ll sum = 0;
    sort(v.begin(), v.end());
    for (int i=0; i<N; i++){
        for (int j=i+1; j<N; j++){
            //boundaries v[i].f and v[j].f
            int x1 = min( v[i].f, v[j].f )-1;
            int x2 = max( v[i].f, v[j].f );
            int y1 = min( v[i].s, v[j].s )-1;
            int y2 = max( v[i].s, v[j].s );

            //cout<<x1<<"  "<<x2<<"  "<<y1<<"  "<<y2<<endl;

            //cout<<ps[x2][N]<<"  "<<ps[x1][N]<<"  "<<ps[x2][y2]<<"  "<<ps[x1][y2]<<endl;
            //cout<<ps[x2][y1]<<"  "<<ps[x1][y1]<<endl;

            int up = ps[x2][N] - ps[x1][N] - ps[x2][y2] + ps[x1][y2];
            int down = ps[x2][y1] - ps[x1][y1];

            sum += (up+1)*(down+1);
        }
    }
    sum+=N+1;

    cout<<sum<<endl;

    return 0;
}
#include <bits/stdc++.h>
#define FOR(i, a, b)  for(int i = (a); i < (b); i++)
#define ll long long
#define f first
#define s second
#define pb push_back
using namespace std;

vector<vector<int>> vec;
vector<pair<int, int>> in;
vector<vector<bool>> cycle, vis;
vector<int> ans;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int N, D;

int temp = 0;

bool out(int x, int y){
    if (x>=0 && x<N && y>=0 && y<N) return false;
    return true;
}

int init(){
    //for possible optimization
    vis.resize(N, vector<bool>(N, false));

    queue<pair<int, int>> q;

    FOR(i, 0, N){
        FOR(j, 0, N){
            if (i==0 || j==0 || i==N-1 || j==N-1){
                if (vec[i][j]==5 || out(i+dx[vec[i][j]],j+dy[vec[i][j]])){
                    //cout<<i<<"    "<<j<<"    "<<vec[i][j]<<"  "<<dx[vec[i][j]]<<endl;
                    q.push({i, j});
                }
                //dfs_recursive(i, j);
            }
        }
    }

    while(!q.empty()){ // everything that is in here is valid
        int x = q.front().f, y = q.front().s; q.pop();
        if (vis[x][y]) continue;
        vis[x][y] = true; // the ones visited are not cycles
        cycle[x][y] = false;

        temp++;
        FOR(i, 0, 4){
            if (out(x+dx[i], y+dy[i])) continue;
            if (vis[x+dx[i]][y+dy[i]]) continue;
            if (vec[x+dx[i]][y+dy[i]]==5) q.push({x+dx[i],y+dy[i]});
            if (i==0 && vec[x+dx[i]][y+dy[i]]==2) q.push({x+dx[i],y+dy[i]}); // x, y 被指 -> valid
            if (i==1 && vec[x+dx[i]][y+dy[i]]==3) q.push({x+dx[i],y+dy[i]});
            if (i==2 && vec[x+dx[i]][y+dy[i]]==0) q.push({x+dx[i],y+dy[i]});
            if (i==3 && vec[x+dx[i]][y+dy[i]]==1) q.push({x+dx[i],y+dy[i]});
            
        }
    }
    return temp=(N*N)-temp;
}


int rm(int i, int j){
    int rmd = 0;

    queue<pair<int, int>> q; //queue -> to be deleted
    q.push({i, j});

    while(!q.empty()){
        int x = q.front().f, y = q.front().s; q.pop();
        if (!cycle[x][y]) continue;
        rmd++;
        cycle[x][y] = false;

        FOR(i, 0, 4){
            if (out(x+dx[i], y+dy[i])) continue;
            if (!cycle[x+dx[i]][y+dy[i]]) continue;
            if (vec[x+dx[i]][y+dy[i]]==5) q.push({x+dx[i],y+dy[i]}); // x, y 被指 -> valid
            if (i==0 && vec[x+dx[i]][y+dy[i]]==2) q.push({x+dx[i],y+dy[i]}); 
            if (i==1 && vec[x+dx[i]][y+dy[i]]==3) q.push({x+dx[i],y+dy[i]});
            if (i==2 && vec[x+dx[i]][y+dy[i]]==0) q.push({x+dx[i],y+dy[i]});
            if (i==3 && vec[x+dx[i]][y+dy[i]]==1) q.push({x+dx[i],y+dy[i]});
        }
    }
    return (temp-=rmd);
}

int main (){
    cin>>N>>D;
    vec.resize(N, vector<int>(N, 5));
    cycle.resize(N, vector<bool>(N,true));

    FOR(i, 0, D){
        int a, b; 
        string c;
        cin>>a>>b>>c;
        in.pb({--a, --b});
        if (c=="U") vec[a][b]=0;
        if (c=="R") vec[a][b]=1;
        if (c=="D") vec[a][b]=2;
        if (c=="L") vec[a][b]=3;
    }

    //ans.resize(D);
    ans.pb(init());

    for(int i=D-1; i>=0; i--){
        ans.pb(rm(in[i].f, in[i].s));
    }

    for(int i=D-1; i>=0; i--){
        cout<<ans[i]<<endl;
    }
}
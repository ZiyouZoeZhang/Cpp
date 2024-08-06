//https://usaco.org/index.php?page=viewproblem2&cpid=740
//nope, 85 ~ 95 weird
#include<bits/stdc++.h>
using namespace std;
int N;
char adj[20][20];
bool vis[20][20];
int comp[20][20];

struct pcl {
    int x1, x2, y1, y2;
};

bool check(int x1, int x2, int y1, int y2){ //
    vector<set<int>> v(26);

    for (int i=x1; i<x2; i++){
        for (int j=y1; j<y2; j++){
            cout<<adj[i][j]<<" ";
            v[adj[i][j] - 'A'].insert(comp[i][j]);
        }
    }

    cout<<endl<<endl;
    bool single = false, more = false;
    int color = 0;
    for (auto i: v){
        if (i.size()!=0){
            color++;
            if (i.size()==1) single = true;
            if (i.size()>1) more = true;
        } 
    }

    return (color == 2 && single && more);
}

bool isInside(pcl a, pcl b){
    return (a.x1 >= b.x1 && a.x2 <= b.x2 && a.y1 >= b.y1 && a.y2 <= b.y2);
}

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void dfs(int i, int j, int co){
    if (i>-1 && i<N && j>-1 && j<N && comp[i][j] == -1) {
        comp[i][j] = co;
        for (int x = 0; x<4; x++){
            if (adj[i][j] == adj[i + dx[x]][j + dy[x]]) dfs(i + dx[x], j + dy[x], co);
        }
    }
}

int main (){
    cin>>N;
    memset(vis, false, 20*20);
    memset(comp, -1, 20*20);
    for (int i=0; i<N; i++)
        for (int j=0; j<N; j++)
            cin>>adj[i][j];

    int co = 0;
    for (int i=0; i<N; i++){
        for (int j=0; j<N; j++){
            if (comp[i][j] == -1) dfs(i, j, co++);
        }
    }
    
    vector<pcl> v;
    for (int x1 = 0; x1<N; x1++){
        for (int x2 = x1+1; x2<=N; x2++){
            for (int y1 = 0; y1 < N; y1++){
                for (int y2 = y1+1; y2 <= N; y2++){
                    if (x1 ==0 && x2 == 3 && y1==0 && y2 ==4){
                        cout<<"";
                    }
                    if (check(x1, x2, y1, y2)){
                        pcl i; i.x1 = x1; i.x2 = x2; i.y1 = y1; i.y2 = y2;
                        v.push_back(i);
                    }
                }
            }
        }
    }
    
    bool valid = true;
    int c;
    for (int i=0; i<v.size(); i++){
        for (int j=0; j<v.size(); j++){
            if (i!=j && !isInside(v[i], v[j])) { //i is not contained by any other PCl
                valid = false;
            }
        }
        if (valid) c++;
    }

    cout<<c<<endl;
    return 0;
}


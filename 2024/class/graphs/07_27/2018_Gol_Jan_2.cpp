//https://www.luogu.com.cn/problem/P4186
//65 points
#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;

int main (){
    int N, K;
    cin>>N>>K;
    vector<vector<int>> adj(N+1);
    
    for (int i=0; i<N-1; i++){
        int a, b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<bool> visb(N+1, false);
    vector<bool> visf(N+1, false);
    queue<int> qb;
    queue<int> qf;

    //prep b
    qb.push(K);
    visb[K]=true;

    //prep f
    for (int i=0; i<N+1; i++){
        if (adj[i].size()==1){
            qf.push(i); 
            visf[i]=true;
        }
    }

    int c = 0; //count

    //bfs
    while(!qb.empty()){
        //movw b
        qb.push(INF); //分割线
        while (qb.front()!=INF){
            int a=qb.front(); qb.pop();
            for (auto b: adj[a]){
                if (visb[b]) continue;
                if (!visf[b]){ //not visited by farmer
                    visb[b]=true;
                    qb.push(b);
                } else { //encoutering farmer
                    c++;
                }
            }
        }
        qb.pop();

        //move farmers
        qf.push(INF); //分割线
        while (qf.front() != INF){
            int a=qf.front(); qf.pop();
            for (auto b: adj[a]) {
                if (visf[b]) continue;
                visf[b] = true;
                qf.push(b);
            }
        }
        qf.pop();
    }

    cout<<c<<endl;
}
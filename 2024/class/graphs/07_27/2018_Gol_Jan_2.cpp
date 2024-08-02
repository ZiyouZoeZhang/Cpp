//https://www.luogu.com.cn/problem/P4186
//https://usaco.org/index.php?page=viewproblem2&cpid=790
//cow at large
//65 points
#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;

ofstream fout ("atlarge.out");
ifstream fin ("atlarge.in");

int main (){
    
    int N, K;
    fin>>N>>K;

    vector<vector<int>> adj(N+1); //adjacency vector

    vector<bool> visb(N+1, false); //visited bessie 
    vector<bool> visf(N+1, false); //visited farmer
    queue<int> qb; //queue bessie
    queue<int> qf; //queue farmer

    for (int i=0; i<N-1; i++){
        int a, b;
        fin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
   
    //prep
    qb.push(K); //initial starting point of bessie
    visb[K]=true;

    for (int i=0; i<N+1; i++){
        if (adj[i].size()==1){ //finds the end of tree 边缘节点
            qf.push(i); //initial starting point of farmers
            visf[i]=true;
        }
    }

    //code
    int c = 0; //count of how many bessie are caught by farmers

    //bfs
    while(!qb.empty()){ //while not every bessie is caught

        //bfs bessie
        int sb = qb.size(); //every bessie walks 1 step
        while (sb-->0){
            int a=qb.front(); qb.pop();
            for (auto b: adj[a]){ //from node a to every connected node (b)
                if (visb[b]) continue; //if visited by bessie, continue
                if (!visf[b]){ //if not visited by farmer
                    visb[b]=true; //get visited by bessie
                    qb.push(b);
                } else { //if visited by farmer
                    c++; //count ++
                }
            }
        }

        //bfs farmer
        int sf = qf.size(); //every farmer walks 1 step
        while (sf-->0){
            int a=qf.front(); qf.pop();
            for (auto b: adj[a]) {
                if (visf[b]) continue; //if already visited by farmer, continue
                visf[b] = true; //gets visited
                qf.push(b);
            }
        }
    }
    
    fout<<c<<endl; //end
}
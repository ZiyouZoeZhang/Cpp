//https://usaco.org/index.php?page=viewproblem2&cpid=671
#include <bits/stdc++.h>
#define ff first
#define ss second
#define ll long long
#define INF 0x3f3f3f3f
#define mk make_pair
using namespace std;

unordered_map<int, priority_queue<int>> vx;
unordered_map<int, priority_queue<int>> vy;

struct hash_pair {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const
    {
        // Hash the first element
        size_t hash1 = hash<T1>{}(p.first);
        // Hash the second element
        size_t hash2 = hash<T2>{}(p.second);
        // Combine the two hash values
        return hash1
               ^ (hash2 + 0x9e3779b9 + (hash1 << 6)
                  + (hash1 >> 2));
    }
};

int N;
pair<int, int> L, B;

unordered_map<pair<int, int>, vector<pair<int, int>>, hash_pair> adj;
unordered_map<pair<int, int>, int, hash_pair> dist;

int main (){
    cin>>N>>L.ff>>L.ss>>B.ff>>B.ss;
    vx[L.ff].push(L.ss);
    vy[L.ss].push(L.ff);
    vx[B.ff].push(B.ss);
    vy[B.ss].push(B.ff);
    for (int i=0; i<N; i++){
        int x, y;
        cin>>x>>y;
        vx[x].push(y);
        vy[y].push(x);
    }

    //memset(adj, INF, sizeof(adj)*1000010*4);
    //memset(dist, INF, sizeof(dist)*1000010*2);
/*
    for (auto x: vx){
        int py = x.ss.top(); x.ss.pop();
        while (!x.ss.empty()){
            int y = x.ss.top(); x.ss.pop();
            adj[mk(x.ff, y)].push_back(mk(x.ff, py));
            adj[mk(x.ff, py)].push_back(mk(x.ff, y));
        }
    }
*/
    for (auto y: vy){
        int px = y.ss.top(); y.ss.pop(); 
        while (!y.ss.empty()){
            int x = y.ss.top(); y.ss.pop();
            if (y.ff==2){
            cout<<""<<endl;
        }
            adj[mk(x, y.ff)].push_back(mk(px, y.ff));
            adj[mk(px, y.ff)].push_back(mk(x, y.ff));
        }
    }

    return 0;


    
}
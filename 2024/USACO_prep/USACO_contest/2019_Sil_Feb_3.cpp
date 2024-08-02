//https://usaco.org/index.php?page=viewproblem2&cpid=920
//not yet done

#include<bits/stdc++.h>
#define f first
#define s second
#define ll long long
using namespace std;

vector<pair<int, int>> adj[100000];
vector<int> comps[100000];
vector<int> comp(100000, -1);
vector<int> color(100000, -1);

void dfs(int i, int cur){ //color
    if (comp[i]!=-1) {return;}
    comp[i] = cur;
    for (auto j: adj[i]){
        int c = (j.s == 'S') ? color[i] : 1-color[i];
        color[j.f] = (color[j.f] != -1 && c != color[j.f]) ? 3 : c;
        dfs(j.f, cur);
    }
}
/*
void bin(ll n) {
    if (n > 1) bin(n / 2);
    cout << n % 2;
}
*/

int main (){
    int N, M;
    cin>>N>>M;

    for (int i=0; i<M; i++){
        char c;
        int a, b;
        cin>>c>>a>>b;
        adj[--a].push_back({--b, c});
        adj[b].push_back({a, c});
    }

    int cur = 0;
    for (int i=0; i<N; i++){
        if (comp[i]==-1){
            color[i] = 0;
            dfs(i, cur++);
        }
    }

    for (auto i: color){
        if (i==3){
            cout<<0<<endl;
            return 0;
        }
    }

    for (int i=0; i<N; i++){
        comps[comp[i]].push_back(i);
    }

    ll rec = -1;
    while (comps[++rec].size()>0);


   // bin(pow(2, rec));
    cout<<(1<<rec)<<endl;
}
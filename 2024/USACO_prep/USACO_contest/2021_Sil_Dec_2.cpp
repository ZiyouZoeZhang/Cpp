//https://usaco.org/index.php?page=viewproblem2&cpid=1159
//not yet done

#include<bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
#define INFl 0x3f3f3f3f3f3f3f3f
using namespace std;

vector<int> adj[100000]; //yes my amazing adjencency vector
vector<int> comps[100000]; //all componnents
int comp[100000]; //returns index of component

void dfs(int i, int curcomp){
    if (comp[i]!=-1) {return;}
    comp[i] = curcomp;
    for (auto j: adj[i]) dfs(j, curcomp);
}

ll cost(int a, int b) {
    ll minimum = INFl;
    for (int i : comps[a]) {
        auto it = upper_bound(comps[b].begin(), comps[b].end(), i);
        if (it != comps[b].begin()) {
            minimum = min(minimum, (ll)abs(*prev(it) - i));
        }
        if (it != comps[b].end()) {
            minimum = min(minimum, (ll)abs(*it - i));
        }
    }
    return minimum * minimum;
}

void cal() {
    int N, M;
    cin>>N>>M;

    for (int i=0; i<N; i++) {
        adj[i].clear();
        comps[i].clear();
        comp[i] = -1;
    }

    for (int i=0; i<M; i++){
        int a, b;
        cin>>a>>b;
        adj[--a].push_back(--b);
        adj[b].push_back(a);
    }

    int curcomp = 0;
    for (int i=0; i<N; i++){
        if (comp[i] == -1) dfs(i, curcomp++);
    }

    for (int i=0; i<N; i++) comps[comp[i]].push_back(i);

    //now cost
    ll minimum = cost(comp[0], comp[N-1]);
    for (int i = 1; i < curcomp; i++) {
        minimum = min(minimum, cost(comp[0], i) + cost(i, comp[N-1]));
    }
    cout<<minimum<<endl;
}

int main (){
    int T;
    cin>>T;
    while(T-->0) cal();
    return 0;
}
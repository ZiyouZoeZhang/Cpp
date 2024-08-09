//https://www.luogu.com.cn/problem/P6004
//https://usaco.org/index.php?page=viewproblem2&cpid=992
//does not work

#include <bits/stdc++.h>
#define ll long long
#define s second
#define f first
using namespace std;

struct DisjointSets {

	vector<int> parents;
	vector<int> sizes;

	DisjointSets(int size) : parents(size), sizes(size, 1) {
		for (int i = 0; i < size; i++) { parents[i] = i; }
	}
	/** @return the "representative" node in x's component */
	int find(int x) {
		return parents[x] == x ? x : (parents[x] = find(parents[x]));
	}
	/** @return whether the merge changed connectivity */
	bool unite(int x, int y) {
		int x_root = find(x);
		int y_root = find(y);
		if (x_root == y_root) { return false; }
		if (sizes[x_root] < sizes[y_root]) { swap(x_root, y_root); }
		sizes[x_root] += sizes[y_root];
		parents[y_root] = x_root;
		return true;
	}
	/** @return whether x and y are in the same connected component */
	bool connected(int x, int y) { return find(x) == find(y); }
};

struct p {
    ll w;
    int u, v;
};

int N, M;
int cow[100010];
vector<vector<int>> comps;
vector<pair<int, int>> adj[100010]; //weighen, v
DisjointSets d = DisjointSets(100010);

void sortIntoComps(){
    int c = 0;
    bool vis[N];
    memset(vis, false, N);
    for (int i=0; i<N; i++){
        if (!vis[i]) {
            int cur = i;
            vector <int> temp;
            while (cur != cow[cur] && !vis[cur]){
                vis[cur] = true;
                temp.push_back(cur);
                //cout<<cur<<" ";
                cur = cow[cur];
            }
            //temp.push_back(cur);
            if (temp.size()!= 0){
                comps.push_back(temp);
            }
        }
    }
    //cout<<endl;
}

ll kruskal(int x){
    vector<p> v;
    for (auto u: comps[x]){
        for (auto i: adj[u]){
            p a;
            a.w = i.f; a.v = i.s; a.u = u;
            v.push_back(a);
        }
    }
    sort(v.begin(), v.end(), [](p a, p b){return b.w< a.w;});

    ll ans = 0x3f3f3f3f;
    int count = 0;
    for (int i=0; i<v.size(); i++){
        if (!d.connected(v[i].u, v[i].v)){
            d.unite(v[i].u, v[i].v);
            ans = min(ans, v[i].w);
            count++;
            //cout<<v[i].w<<" "<<v[i].u<<" "<<v[i].v<<endl;
        }
        if (count == N-1) {break;}
    }
    return ans;
}

int main (){
    cin>>N>>M;
    for (int i=0; i<N; i++){
        cin>>cow[i];
        cow[i]--;
    }

    for (int i=0; i<M; i++){
        ll u, v, w;
        cin>>u>>v>>w;
        adj[--u].push_back({w, --v});
        adj[v].push_back({w, u});
    }

    sortIntoComps();
    ll mx = 0x3f3f3f3f;
    for (int i=0; i<comps.size(); i++){
        mx = min(mx, kruskal(i));
    }
    if (mx == 0x3f3f3f3f) cout<<"-1"<<endl;
    else cout<<mx<<endl;
    return 0;
}
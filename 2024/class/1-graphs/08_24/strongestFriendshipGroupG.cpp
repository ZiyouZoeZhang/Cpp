//https://usaco.org/index.php?page=viewproblem2&cpid=1259
#include <bits/stdc++.h>
#define ll long long
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

int N,M;

vector<int> adj [100005];
int sz[100005];
bool del[100005];

void update(int u, int x){
    sz[u]--;
    if (!del[u] && sz[u]<x){
        del[u] = true;
        for (auto v: adj[u]){
            if (!del[v]) update(v, x);
        }
    }
}

ll cal(int x){
    for (int u=0; u<N; u++){
        if (!del[u] && sz[u]<x){
            del[u] = true;
            for (auto v: adj[u]){
                if (!del[v]) update(v, x);
            }
        }
    }

    DisjointSets d(N);
    for (int u=0; u<N; u++){
        for (auto v: adj[u]){
            if (!del[v] && !del[u]) d.unite(u, v);
        }
    }

    int  mx = 0;
    for (int i=0; i<N; i++){
        mx = max(mx, d.sizes[i]);
    }

    return mx;
}

int main (){
    memset(sz, 0, sizeof(sz));
    memset(del, false, sizeof(del));

    cin>>N>>M;
    for (int i=0; i<M; i++){
        int a, b;
        cin>>a>>b;
        adj[--a].push_back(--b);
        adj[b].push_back(a);
        sz[a]++;
        sz[b]++;
    }

    ll mx = 0;
    for (int i=1; i<sqrt(M); i++){
        mx = max(mx, cal(i)*i);
    }

    cout<<mx<<endl;

    return 0;
}
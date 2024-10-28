//https://usaco.org/index.php?page=viewproblem2&cpid=531
#include <bits/stdc++.h>
#define ll long long
using namespace std;

ofstream fout ("superbull.out");
ifstream fin ("superbull.in");

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

int N;
vector<int> v;
vector<p> adj;

ll kruskal(){
    ll ans = 0;
    int count = 0;
    DisjointSets d = DisjointSets(N);
    for (int i=0; i<adj.size(); i++){
        if (!d.connected(adj[i].u, adj[i].v)){
            d.unite(adj[i].u, adj[i].v);
            ans += adj[i].w;
            count++;
        }
        if (count == N-1) {return ans;}
    }
    return ans;
}

int main (){
    fin>>N;
    for (int i=0; i<N; i++){
        int a;
        fin>>a;
        v.push_back(a);
    }

    for (int i=0; i<N; i++){
        for (int j=i+1; j<N; j++){
            p a;
            a.u = i; a.v = j; a.w = v[i]^v[j];
            adj.push_back(a);
        }
    }

    sort(adj.begin(), adj.end(), [](p a, p b){return b.w < a.w;});
    fout<<kruskal()<<endl;
}
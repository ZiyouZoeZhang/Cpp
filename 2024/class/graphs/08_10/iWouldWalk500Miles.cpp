#include <bits/stdc++.h>
using namespace std;

ofstream fout ("walk.out");
ifstream fin ("walk.in");

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
    int w;
    short x, y;
};

int N, K;
vector<p> adj;

int dis(int x, int y){
    return (((long long)2019201913*(x+1)) + ((long long)2019201949*(y+1)))%2019201997;
}

int main (){
    fin>>N>>K;
    for (int i=0; i<N; i++){
        for (int j = i+1; j<N; j++){
            p a;
            a.w = dis(i, j); a.x = i; a.y = j;
            adj.push_back(a);
        }
    }

    sort(adj.begin(), adj.end(), [](p a, p b){return a.w < b.w;}); //least to greatest

    DisjointSets d = DisjointSets(N);
    int groups = N;
    int i = 0;
    while (groups>=K){
        while (d.connected(adj[i].x, adj[i].y)) i++;
        d.unite(adj[i].x, adj[i].y);
        groups--;
    }

    fout<<adj[i].w<<endl;
    return 0;
}
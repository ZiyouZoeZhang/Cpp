//https://usaco.org/index.php?page=viewproblem2&cpid=1211
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

struct p {
    ll w;
    int u, v;
};

int N;
vector<pair<int, int>> v;
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
    cin>>N;
    for (int i=0; i<N; i++){
        int x, y;
        cin>>x>>y;
        v.push_back({x, y});
    }

	sort(v.begin(), v.end());

    for (int i=0; i<N; i++){
        for (int j=i+1; j<N; j++){
			if (j==i+50) {break;} //very important 剪枝
            p a;
            a.u = i; a.v = j; a.w =pow((v[i].first- v[j].first), 2)+ pow((v[i].second-v[j].second), 2);
            adj.push_back(a);
        }
    }

    sort(adj.begin(), adj.end(), [](p a, p b){return b.w > a.w;});
	cout<<kruskal()<<endl;
}
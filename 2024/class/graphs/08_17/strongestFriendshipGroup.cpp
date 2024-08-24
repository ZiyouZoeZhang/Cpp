//this also doesn't!
#include <bits/stdc++.h>
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

vector<int> adj [10010];

int main (){
    cin>>N>>M;
    for (int i=0; i<M; i++){
        int u, v;
        cin>>u>>v;
        adj[--u].push_back(--v);
        adj[v].push_back(u);
    }

    priority_queue<pair<int, int>> pq;

    for (int i=0; i<N; i++){
        pq.push({adj[i].size()-1, i});
    }

    DisjointSets d(N);

    int ans = 0;

    while (!pq.empty()){
        auto [friends, u]= pq.top(); pq.pop();
        //int friends = d.sizes[d.find(pq.top().first)];
        for (auto v: adj[u]){
            //only connect if the point is in the group already, also maximize the number of friends of cows in the group
            d.unite(v, u);
            friends = min (friends, d.sizes[d.find(v)]-1);
            //cout<<adj[pq.top().second][i]<<" "<<pq.top().second;
        }

        ans = max(ans, friends * d.sizes[d.find(u)]);
        cout<<ans<<" "<<u<<endl;
    }

    cout<<endl<<ans<<endl;
}
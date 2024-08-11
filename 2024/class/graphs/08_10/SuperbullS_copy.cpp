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

long long prim(const vector<vector<pair<int, int>>> &neighbors) {
	const int n = neighbors.size();  // just a shorthand
	long long min_cost = 0;
	vector<long long> dist(n, std::numeric_limits<long long>().max());
	dist[0] = 0;
	std::priority_queue<pair<long long, int>> q;
	q.push({0, 0});
	vector<bool> visited(n);
	int added = 0;
	while (added < n) {
		if (q.empty()) { return -1; }
		auto [curr_cost, v] = q.top();
		q.pop();
		curr_cost *= -1;
		if (dist[v] < curr_cost) { continue; }
		added++;
		visited[v] = true;
		min_cost += curr_cost;
		for (auto &[next, n_cost] : neighbors[v]) {
			if (!visited[next] && n_cost < dist[next]) {
				dist[next] = n_cost;
				q.push({-n_cost, next});
			}
		}
	}
	return min_cost;
}

int main (){
    cin>>N;
    for (int i=0; i<N; i++){
        int x, y;
        cin>>x>>y;
        v.push_back({x, y});
    }

    vector<vector<pair<int, int>>> neighbors;

    for (int i=0; i<N; i++){
        vector<pair<int, int>> temp;
        for (int j=i+1; j<N; j++){
            //p a;
            //a.u = i; a.v = j; a.w =pow((v[i].first- v[j].first), 2)+ pow((v[i].second-v[j].second), 2);
            //adj.push_back(a);
            temp.push_back({j, pow((v[i].first- v[j].first), 2)+ pow((v[i].second-v[j].second), 2)});
        }
        neighbors.push_back(temp);
    }
    for (int i=0; i<N; i++){
        sort(neighbors[i].begin(), neighbors[i].end(), [](pair<int, int> a, pair<int, int>  b){return a.second < b.second;});
    }

    //sort(adj.begin(), adj.end(), [](p a, p b){return b.w > a.w;});
    cout<< prim(neighbors)<<endl;
}
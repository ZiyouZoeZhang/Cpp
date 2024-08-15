#include <bits/stdc++.h>
using namespace std;

struct DisjointSets {

	vector<ll> parents;
	vector<ll> sizes;

	DisjointSets(ll size) : parents(size), sizes(size, 1) {
		for (ll i = 0; i < size; i++) { parents[i] = i; }
	}
	/** @return the "representative" node in x's component */
	ll find(ll x) {
		return parents[x] == x ? x : (parents[x] = find(parents[x]));
	}
	/** @return whether the merge changed connectivity */
	bool unite(ll x, ll y) {
		ll x_root = find(x);
		ll y_root = find(y);
		if (x_root == y_root) { return false; }
		if (sizes[x_root] < sizes[y_root]) { swap(x_root, y_root); }
		sizes[x_root] += sizes[y_root];
		parents[y_root] = x_root;
		return true;
	}
	/** @return whether x and y are in the same connected component */
	bool connected(ll x, ll y) { return find(x) == find(y); }
};


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

}

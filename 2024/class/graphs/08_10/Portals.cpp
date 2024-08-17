//https://usaco.org/index.php?page=viewproblem2&cpid=1138
//92 points
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

vector<pair<int, vector<int>>> v;
int N;

int main (){
    cin>>N;

    DisjointSets d = DisjointSets((2*N + 10));

    for (int i=0; i<N; i++){
        int a; cin>>a;
        vector<int> temp(4);
        for (int i=0; i<4; i++){
            cin>>temp[i];
        }
        d.unite(temp[0], temp[1]);
        d.unite(temp[2], temp[3]);
        v.push_back({a, temp});
    }

    sort(v.begin(), v.end(), [](pair<int, vector<int>> a, pair<int, vector<int>> b){return a.first<b.first;});

    int ans = 0;
    for (int i=0; i<v.size(); i++){
        if (d.unite(v[i].second[0], v[i].second[2])) ans += v[i].first;
    }
    
    cout<<ans<<endl;
    return 0;
}
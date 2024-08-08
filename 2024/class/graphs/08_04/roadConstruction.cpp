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

int N, M;

int main (){
    cin>>N>>M;
    DisjointSets d = DisjointSets(N);
    int mx = 0;
    for (int i=0; i<M; i++){
        int a, b;
        cin>>a>>b;  
        if (d.unite(--a, --b)){
            mx = max(mx, d.sizes[d.find(a)]);
            N--;
        }
        cout<<N<<" "<<mx<<endl;
    }

    return 0;
}
//https://usaco.org/index.php?page=viewproblem2&cpid=968
#include <bits/stdc++.h>
#define FOR(i, a, b)  for(ll i = (a); i < (b); i++)
#define ll long long
#define pb push_back
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

void setIO(string name = "") {
    ios_base::sync_with_stdio(0); cin.tie(0);
    if((int)(name).size()){
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout);
    }
}

int n, m;
vector<int> adj[100010];
char v[100010];


int main (){
    setIO("milkvisits");
    cin>>n>>m;
    FOR(i, 0, n) cin>>v[i];
    DisjointSets d(n);

    FOR(i, 0, n-1){
        int a, b; cin>>a>>b;
        if (v[--a]==v[--b]) {
            //adj[a].pb(b); adj[b].pb(a);
            d.unite(b, a);
        }
    }
  
    FOR(i, 0, m){
        int a, b;
        char c;
        cin>>a>>b>>c;
        if (d.connected(--a, --b) && v[a]==c) cout<<1;
        else if (!d.connected(a, b)) cout<<1;
        else cout<<0;
    }

    cout<<endl;
}
//https://usaco.org/index.php?page=viewproblem2&cpid=789
//done!!
#include <bits/stdc++.h>
#define ll long long
#define f first
#define s second
using namespace std;

ofstream fout ("mootube.out");
ifstream fin ("mootube.in");

struct hash_pair {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const
    {
        // Hash the first element
        size_t hash1 = hash<T1>{}(p.first);
        // Hash the second element
        size_t hash2 = hash<T2>{}(p.second);
        // Combine the two hash values
        return hash1
               ^ (hash2 + 0x9e3779b9 + (hash1 << 6)
                  + (hash1 >> 2));
    }
};

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
    int u, v;
    ll w;
};

int N, Q;
vector<p> adj;
vector<pair<ll, int>> Qs; //ki, vi
vector<pair<ll, int>> Qsi;

int main (){
    fin>>N>>Q;
    for (int i=0; i<N-1; i++){
        p a;
        fin>>a.u>>a.v>>a.w;
        a.u--; a.v--;
        adj.push_back(a);
    }

    for (int i=0; i<Q; i++){
        ll a, b;
        fin>>a>>b;
        Qs.push_back({a, --b});
        Qsi.push_back({a, b});
    }

    sort(adj.begin(), adj.end(), [](p a, p b){return b.w < a.w;});
    sort(Qs.begin(), Qs.end(), [](pair<ll, int> a, pair<ll, int> b){return b.f < a.f;});

    DisjointSets d = DisjointSets(N);
    unordered_map<pair<ll, int>, int, hash_pair> m;

    int cur = 0;
    for (int i=0; i<Q; i++){ 
        //connect while weighten >= k
        while (cur<N-1 && adj[cur].w >= Qs[i].f){
            d.unite(adj[cur].u, adj[cur].v);
            cur++;
        }
        m[Qs[i]] = d.sizes[d.find(Qs[i].s)]-1;
    }
    for (int i=0; i<Q; i++){
        fout<<m[Qsi[i]]<<endl;
    }

    //return 0;
}
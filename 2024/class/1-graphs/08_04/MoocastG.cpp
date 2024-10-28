//https://usaco.org/index.php?page=viewproblem2&cpid=669
#include <bits/stdc++.h>
#define f first
#define s second
#define ll long long
using namespace std;
int N;

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

struct p{
    ll w;
    int u, v;
};

vector<pair<int, int>> coord;
vector<p> v;


ll kruskal(){
    ll ans = 0;
    int count = 0;
    DisjointSets d = DisjointSets(N);
    for (int i=0; i<v.size(); i++){
        if (!d.connected(v[i].u, v[i].v)){
            d.unite(v[i].u, v[i].v);
            //ans += v[i].w;
            ans = max (ans, v[i].w);
            count++;
            //cout<<v[i].w<<" "<<v[i].u<<" "<<v[i].v<<endl;
        }
        if (count == N-1) {break;}
    }
    return ans;
}

int main (){
    cin>>N;
    for (int i=0; i<N; i++){
        int a, b;
        cin>>a>>b;
        coord.push_back({a, b});
    }

    for (int i=0; i<N-1; i++){
        for (int j=i+1; j<N; j++){
            p a;
            a.u = i; a.v = j; a.w = pow((coord[i].f - coord[j].f), 2) + pow((coord[i].s - coord[j].s), 2);
            v.push_back(a);
        }
    }

    sort(v.begin(), v.end(), [](p u, p v){return u.w<v.w;});
    cout<<kruskal()<<endl;
    return 0;
}

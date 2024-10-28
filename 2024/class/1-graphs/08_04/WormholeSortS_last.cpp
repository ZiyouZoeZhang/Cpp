//https://www.luogu.com.cn/problem/P6004
//https://usaco.org/index.php?page=viewproblem2&cpid=992
//done!!

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

struct p{
    ll w;
    int u, v;
};

int N, M;
vector<p> con;
vector<int> cows;

int main (){
    cin>>N>>M;
    for (int i=0; i<N; i++){
        int a;
        cin>>a;
        cows.push_back(--a);
    }

    for (int i=0; i<M; i++){
        p a;
        cin>>a.u>>a.v>>a.w;
        a.u--; a.v--;
        con.push_back(a);
    }

    sort(con.begin(), con.end(), [](p a, p b){return b.w<a.w;});

    DisjointSets d = DisjointSets(N);
    int cow = 0;
    int index = 0;
    while (cow<N){
        while (index < M && !d.connected(cows[cow], cow)){
            d.unite(con[index].u, con[index].v);
            index++;
        }
        cow++;
    }
    if (index == 0) cout<<"-1"<<endl;
    else cout<<con[index-1].w<<endl;
}
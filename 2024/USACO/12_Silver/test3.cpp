#include <bits/stdc++.h>
#define FOR(i, a, b)  for(int i = (a); i < (b); i++)
#define ll long long
//#define f first
//#define s second
#define pb push_back
using namespace std;

/*
void dfs_recursive(int x, int y){ // x-> starting position
    if (vis[x][y]) return;
    vis[x][y]=true;
    temp++;

    FOR(i, 0, 4){
        //out or not pointing to cell --> continue
        if (out(x+dx[i], y+dy[i])) continue;
        if (i==0 && vec[x+dx[i]][y+dy[i]]==2) continue;
        if (i==1 && vec[x+dx[i]][y+dy[i]]==3) continue;
        if (i==2 && vec[x+dx[i]][y+dy[i]]==0) continue;
        if (i==3 && vec[x+dx[i]][y+dy[i]]==1) continue;
        dfs_recursive(x+dx[i], y+dy[i]);
    } 

    return;
}*/


/*
struct DisjointSets {

	vector<int> parents;
	vector<int> sizes;

	DisjointSets(int size) : parents(size), sizes(size, 1) {
		for (int i = 0; i < size; i++) { parents[i] = i; }
	}
	/** @return the "representative" node in x's component 
	int find(int x) {
		return parents[x] == x ? x : (parents[x] = find(parents[x]));
	}
	/** @return whether the merge changed connectivity 
	bool unite(int x, int y) {
		int x_root = find(x);
		int y_root = find(y);
		if (x_root == y_root) { return false; }
		if (sizes[x_root] < sizes[y_root]) { swap(x_root, y_root); }
		sizes[x_root] += sizes[y_root];
		parents[y_root] = x_root;
		return true;
	}
	/** @return whether x and y are in the same connected component 
	bool connected(int x, int y) { return find(x) == find(y); }
};*/
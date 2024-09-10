//https://www.luogu.com.cn/problem/P1027
//first version, yoo it doesn't work, wait for my Dij next version
#include <bits/stdc++.h>
#define FOR(i, a, b)  for(int i = (a); i < (b); i++)
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

int dist(pair<int, int> a, pair<int, int> b){
    return sqrt(pow((a.first - b.first), 2) + pow((a.second - b.second) , 2));
}

pair<int, int> findEdge(vector<pair<int, int>> v){
    int d = 0, a, b, c;
    if (dist(v[0], v[1]) > d){d = dist(v[0], v[1]); a = 0; b = 2; c = 1;}
    if (dist(v[0], v[2]) > d){d = dist(v[0], v[2]); a = 0; b = 1; c = 2;}
    if (dist(v[1], v[2]) > d){d = dist(v[1], v[2]); a = 1; b = 0; c = 2;}

    //a += c
    pair<int, int> f;
    f.first = v[a].first + (v[c].first - v[b].first);
    f.second = v[a].second + (v[c].second - v[b].second);
    return f;
}

int main (){
    int n, s, t, a, b;
    vector<vector<int>> perm = {{0, 1}, {0, 2}, {0, 3}, {1, 2}, {1, 3}, {2, 3}};
    cin>>n;
    while (n-->0){
        priority_queue<pair<int, pair<int, int>>> pq; //dist, a, b;
        cin>>s>>t>>a>>b;
        FOR(i, 0, s){
            int t;
            vector<pair<int, int>> v(3);
            FOR(j, 0, 3) cin>>v[j].first>>v[j].second;
            v.pb(findEdge(v));
            FOR(j, 0, 6){
                pq.push({dist(v[perm[j][0]], v[perm[j][1]]), {i*4 + perm[j][0], i*4 + perm[j][1]}});
            }
            cin>>t;
        }

        DisjointSets d(s*4);

    }

    
}
//https://usaco.org/index.php?page=viewproblem2&cpid=646
#include <bits/stdc++.h>
using namespace std;

struct DisjointSets {

	vector<int> parents;
	vector<int> sizes;
    vector<bool> alive;

	DisjointSets(int size) : parents(size), sizes(size, 1), alive(size, false) {
		for (int i = 0; i < size; i++) { parents[i] = i;}
	}
    /*
    bool oneComp(int N){
        int c = -1;
        for (int i=0; i < N; i++){
            if (alive[i] && c==-1) c = find(i);
            if (alive[i] && c!=-1 && c!= find(i)) return false;
        }
        return true;
    }
    */
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
vector<int> adj[200010];
stack<int> s;

int main(){
    cin>>N>>M;
    for (int i=0; i<M; i++){
        int a, b;
        cin>>a>>b;
        adj[--a].push_back(--b);
        adj[b].push_back(a);
    }
    for (int i=0; i<N; i++){
        int a;
        cin>>a;
        s.push(--a);
    }

    DisjointSets d = DisjointSets(N);
    stack<bool> b;

    int c = 0;
    while (!s.empty()){
        int a = s.top(); s.pop();
        bool one = false;
        d.alive[a] = true;
        c++;
        for (auto b: adj[a]) {
            if (d.alive[b] && d.unite(a, b)) c--;
        }
        b.push(c==1);
    }
    
    while (!b.empty()){
        bool a = b.top(); b.pop();
        if (a) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }

}
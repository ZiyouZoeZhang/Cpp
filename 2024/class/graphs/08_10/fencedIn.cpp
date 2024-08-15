//https://usaco.org/index.php?page=viewproblem2&cpid=623
//bugging
#include <bits/stdc++.h>
#define ll long long
using namespace std;

ofstream fout ("fencedin.out");
ifstream fin ("fencedin.in");

struct p {
    ll w;
    ll u;
    ll v;
};

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

ll A, B, N, M;
vector<p> adj;

ll kruskal(ll num){
    ll ans = 0;
    ll count = 0;
    DisjointSets d = DisjointSets(num+1000);
    for (ll i=0; i<adj.size(); i++){
        if (!d.connected(adj[i].u, adj[i].v)){
            d.unite(adj[i].u, adj[i].v);
            ans += adj[i].w;
            count++;
            //cout<<adj[i].u<<" "<<adj[i].v<<" "<<adj[i].w<<endl;
        }
        if (count == num-1) {return ans;}
    }
    return ans;
}

int main (){
    cin>>A>>B>>N>>M;
    vector<ll> Ns(N+100, 0x3f3f3f3f3f3f3f3f); //horizontal
    vector<ll> Ms(M+100, 0x3f3f3f3f3f3f3f3f); //vertical
    
    for (ll i=0; i<N; i++){
        cin>>Ns[i];
    }
    for (ll i=0; i<M; i++){
        cin>>Ms[i];
    }

    N++; M++;
    Ns.push_back(A);Ms.push_back(B);
    sort(Ns.begin(), Ns.end());
    sort(Ms.begin(), Ms.end());

    ll c = 0;
    for (ll i=0; i<N; i++){
        for (ll j=0; j<M-1; j++){
            p a;
            (i==0) ? a.w = Ns[i] : a.w = Ns[i] - Ns[i-1];
            a.u = c; a.v = c+1;
            adj.push_back(a);
            c++;
        }
        c++;
    }

    c=0;
    for (ll i=0; i<N-1; i++){
        for (ll j=0; j<M; j++){
            p a;
            (j==0) ? a.w = Ms[j] : a.w = Ms[j] - Ms[j-1];
            a.u = c; a.v = c+M;
            adj.push_back(a);
            c++;
        }
    }

    sort(adj.begin(), adj.end(), [](p a, p b){return a.w < b.w;});

    cout<<kruskal(((A+1)*(B+1)))<<endl;
}   
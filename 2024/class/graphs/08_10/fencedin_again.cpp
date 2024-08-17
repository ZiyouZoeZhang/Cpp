//https://usaco.org/index.php?page=viewproblem2&cpid=623
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

int main (){
    cin>>A>>B>>N>>M;
    vector<ll> Ns(N); //horizontal
    vector<ll> Ms(M); //vertical
    
    for (ll i=0; i<N; i++){
        cin>>Ns[i];
    }
    for (ll i=0; i<M; i++){
        cin>>Ms[i];
    }

    Ns.push_back(0);Ms.push_back(0);
    Ns.push_back(A);Ms.push_back(B);
    sort(Ns.begin(), Ns.end());
    sort(Ms.begin(), Ms.end());

    for (ll i=0; i<=N; i++){
        for (ll j=0; j<M; j++){
            adj.push_back({(Ns[i+1] - Ns[i]),j*(N+1)+i,j*(N+1)+N+i+1});
        }
    }

    for (ll i=0; i<=M; i++){ //垂直 
        for (ll j=0; j<N; j++){ //水平
            adj.push_back({(Ms[i+1] - Ms[i]),i*(N+1)+j,i*(N+1)+j+1});
        }
    }

    sort(adj.begin(), adj.end(), [](p a, p b){return a.w < b.w;});
    long long num = (N+1)*(M+1);
    DisjointSets dsu(num);
    long long ans = 0;
    for(auto [w,u,v] : adj){
        if(dsu.unite(u,v)){
            ans += w;
        }
    }
    cout << ans << endl;
}
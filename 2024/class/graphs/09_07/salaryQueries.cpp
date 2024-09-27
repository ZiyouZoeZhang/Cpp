//https://cses.fi/problemset/task/1144
//very strange.. this versio  works however

#include <bits/stdc++.h>
#define FOR(i, a, b)  for(ll i = (a); i < (b); i++)
#define ll long long
#define pb push_back
#define lowbit(x) ((x) & - (x))
using namespace std;

const int MX = 4e5 + 5;
 
ll bit[MX];
vector<int> uq;
int n, q;
 
void upd(int i, int val) {
	for (; i <= MX; i += i & (-i)) { bit[i] += val; }
}
 
void add(int x, int b) {
	int ind = upper_bound(uq.begin(), uq.end(), x) - uq.begin();
	upd(ind, b);
}
 
ll sum(int x) {
	ll res = 0;
	for (; x; x -= x & (-x)) { res += bit[x]; }
	return res;
}

int main() {
	cin>>n>>q;

	vector<int> v(n);
    vector<array<int, 3>> qs;

    FOR(i, 0, n){ cin >> v[i]; uq.pb(v[i]);}
	FOR(i, 0, q) {
		char a;
		int b, c;
		cin>>a>>b>>c;

		qs.push_back({a == '?', b, c});
		if (a=='!') uq.push_back(c);
	}
	sort(uq.begin(), uq.end());
	uq.erase(unique(uq.begin(), uq.end()), uq.end());

	for (int i = 0; i < n; i++) { add(v[i], 1); }
	for (auto q : qs) {
		q[1]--;
		if (q[0] == 0) {
			add(v[q[1]], -1);
			v[q[1]] = q[2];
			add(v[q[1]], 1);
		} else {
            ll a = sum(upper_bound(uq.begin(), uq.end(), q[1]) - uq.begin());
            ll b = sum(upper_bound(uq.begin(), uq.end(), q[2]) - uq.begin());
            cout<<b-a<<endl;
		}
	}
}
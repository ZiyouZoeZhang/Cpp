//https://usaco.org/index.php?page=viewproblem2&cpid=764
//not my code
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
	//freopen("shuffle.in", "r", stdin);
	//freopen("shuffle.out", "w", stdout);

	ll n;
	cin >> n;
	vector<ll> a(n);
	vector<ll> cows_after_shuffle(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		a[i]--;
		cows_after_shuffle[a[i]]++;
	}

	ll ans = n;
	queue<ll> no_cows;

	// Calculate positions that are empty after one shuffle.
	for (int i = 0; i < n; i++) {
		if (cows_after_shuffle[i] == 0) {
			no_cows.push(i);
			ans--;
		}
	}

	while (!no_cows.empty()) {
		ll curr = no_cows.front();
		no_cows.pop();

		// Position `curr` cannot contribute any cows.
		if (--cows_after_shuffle[a[curr]] == 0) {
			// If `a[curr]` has no cows, insert it into the queue.
			no_cows.push(a[curr]);
			ans--;
		}
	}
	cout << ans << endl;
}
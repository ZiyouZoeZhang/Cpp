#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("248.in", "r", stdin);
	int n;
	cin >> n;

	vector<int> a(n);
	for (int i = 0; i < n; i++) { cin >> a[i]; }

	// dp[i][j] = final element the range i..j gets merged into,
	// otherwise it's -1 if it cannot be merged into a single element
	vector<vector<int>> dp(n, vector<int>(n, -1));

	int ans = 0;
	for (int len = n - 1; len >= 0; len--) {
		dp[len][len] = a[len];
		for (int r = len; r < n; r++) {
			for (int k = len; k < r; k++) {
				if (dp[len][k] != -1 and dp[len][k] == dp[k + 1][r]) {
					dp[len][r] = dp[len][k] + 1;
				}
			}
			ans = max(ans, dp[len][r]);
		}
	}

	freopen("248.out", "w", stdout);
	cout << ans << endl;
}
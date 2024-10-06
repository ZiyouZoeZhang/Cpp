//gpt's version of the irrigation code, however wrong
#include <bits/stdc++.h>
#define FOR(i, a, b)  for(ll i = (a); i < (b); i++)
#define ll long long
#define pb push_back
#define MAXN 500005  // Adjusted to match the constraints

using namespace std;

int main (){
    ios_base::sync_with_stdio(0); cin.tie(0);

    ll n, m, q;
    cin >> n >> m >> q;

    vector<ll> temp(m, 0);
    FOR(i, 0, n) {
        ll a; cin >> a;
        temp[a-1]++;
    }

    // Map counts to city indices
    map<ll, vector<ll>> counts_map;
    FOR(i, 0, m){
        counts_map[temp[i]].push_back(i);
    }

    // Extract unique counts and sort them
    vector<ll> counts;
    for(auto &p : counts_map) {
        counts.push_back(p.first);
    }
    sort(counts.begin(), counts.end());

    // Prepare cumulative counts and minimal cities
    vector<ll> cnt_counts;  // Number of cities at each count
    vector<vector<ll>> minimal_cities;  // Cities at each count

    for(auto &c : counts) {
        cnt_counts.push_back(counts_map[c].size());
        sort(counts_map[c].begin(), counts_map[c].end());
        minimal_cities.push_back(counts_map[c]);
    }

    ll k = counts.size();
    vector<ll> s_cum(k, 0);  // Cumulative sum of counts
    vector<ll> t(k, 0);      // Times when minimal count increases

    // Compute cumulative counts and times when counts change
    s_cum[0] = cnt_counts[0];
    t[0] = 0;
    for(int i = 1; i < k; ++i) {
        ll delta = counts[i] - counts[i-1];
        t[i] = t[i-1] + delta * s_cum[i-1];
        s_cum[i] = s_cum[i-1] + cnt_counts[i];
    }
    // Since the counts may have gaps, we need to add additional events
    const ll INF = 1e18;
    t.push_back(INF);

    // Read and process queries
    FOR(_, 0, q) {
        ll y; cin >> y;
        y -= n;  // Adjust query to start from time 0
        if (y <= 0) {
            // Before or at initial counts, not considered in the problem
            cout << "-1\n";  // Or handle as per problem statement
            continue;
        }
        y--;  // Zero-based indexing for time

        // Find the interval where y falls
        int idx = upper_bound(t.begin(), t.end(), y) - t.begin() - 1;
        ll rem = y - t[idx];
        ll pos = rem % cnt_counts[idx];
        cout << minimal_cities[idx][pos] + 1 << '\n';  // Output the city index (1-based)
    }
    return 0;
}
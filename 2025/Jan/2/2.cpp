//final
#include <bits/stdc++.h>
#define FOR(i, a, b)  for(int i = (a); i < (b); i++)
#define ll long long
#define f first
#define s second
#define pb push_back
using namespace std;


int find(std::vector<int>& nums, int M) {
    int N = nums.size();

    vector<int> enums = nums;
    FOR(i, 0, N){
        enums.pb(nums[i] + M);
    }

    vector<long long> pre(enums.size());
    pre[0] = enums[0];
    for (int i = 1; i < enums.size(); ++i) {
        pre[i] = pre[i - 1] + enums[i];
    }

    ll ans = LLONG_MAX;
    int bestX = 0;

    for (int i = 0; i < N; ++i) {
        int mid = i + N / 2;
        ll rightSum = pre[i + N - 1] - pre[mid - 1];
        ll leftSum = (mid > i ? pre[mid - 1] : 0) - (i > 0 ? pre[i - 1] : 0);

        long long cost = (mid - i) * 1LL * enums[mid] - leftSum;

        cost += rightSum - (i + N - mid) * 1LL * enums[mid];

        if (cost < ans) {
            ans = cost;
            bestX = enums[mid] % M;
        }
    }

    return ans;
}

void solve(){
    int N, M;
    cin>>N>>M;

    vector<int> v(N), nums(N);

    FOR(i, 0, N){
        cin>>nums[i];
        v[i] = ((nums[i] % M) + M) % M;
    }

    sort(v.begin(), v.end());
    cout<<find(v, M)<<endl;
}

int main(){
    int T;
    cin>>T;
    FOR(i, 0, T){
        solve();
    }
    return 0;
}
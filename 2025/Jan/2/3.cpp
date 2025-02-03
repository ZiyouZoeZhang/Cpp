//final
#include <bits/stdc++.h>
#define FOR(i, a, b)  for(ll i = (a); i < (b); i++)
#define ll long long
#define f first
#define s second
#define pb push_back
using namespace std;


ll find(vector<ll> nums, ll M) {
    ll N = nums.size();



    vector<ll> nnums = nums;
    FOR(i, 0, N){
        nnums.pb(nums[i] + M);
    }

    ll ans = 0;
    FOR(i, 0, N){
        ans += abs(nums[N/2]-nums[i]);
    }
    ll cand = ans;

    FOR(l, 1, N){
        ll mid = N/2 + l, r = l + N -1;

        if (N%2==0){
            //even
            cand += (nnums[mid]-nnums[mid-1]);
        }

        cand -= (nnums[mid-1]-nnums[l-1]);
        cand += (nnums[r]-nnums[mid]);

        ans = min(ans, cand);
    }

    return ans;
}

void solve(){
    ll N, M;
    cin>>N>>M;

    vector<ll> v(N), nums(N);

    FOR(i, 0, N){
        cin>>nums[i];
        v[i] = ((nums[i] % M) + M) % M;
    }

    sort(v.begin(), v.end());
    cout<<find(v, M)<<endl;
}

int main(){
    ll T;
    cin>>T;
    FOR(i, 0, T){
        solve();
    }
    return 0;
}
//missing mian body
#include <bits/stdc++.h>
#define FOR(i, a, b)  for(int i = (a); i < (b); i++)
#define ll long long
#define f first
#define s second
#define pb push_back
using namespace std;

void solve(){
    int N, M;
    cin>>N>>M;

    vector<int> v(N), nums(N);

    FOR(i, 0, N){
        cin>>nums[i];
        v[i] = ((nums[i] % M) + M) % M;
    }

    sort(v.begin(), v.end());


    int x = v[N / 2];
    ll ans = 0;

    FOR(i, 0, N){
        ans += min(min(abs(v[i]-x), abs(M-v[i]+x)), abs(v[i]+(M-x)));
    }

    cout<<ans<<endl;

/*
    for (int k = -1; k <= 1; ++k) { // Try values near the median
        int candidateX = medianMod + k * M; 
        long long totalDistance = 0;

        FOR (i, 0, N) {
            int num = nums[i];
            totalDistance += std::abs(num - candidateX);
        }

        if (totalDistance < minDistance) {
            minDistance = totalDistance;
            x = candidateX;
        }
    }

    ll ans = 0;
    FOR(i, 0, N){
        ans += min(abs(v[i]-x), abs(x-v[i]));
    }

    cout<<ans<<endl;
    */
}

int main(){
    int T;
    cin>>T;
    FOR(i, 0, T){
        solve();
    }
    return 0;
}
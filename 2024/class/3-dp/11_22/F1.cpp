
#include <bits/stdc++.h>
#define FOR(i, a, b)  for(int i = (a); i < (b); i++)
#define ll long long
#define f first
#define s second
#define pb push_back
using namespace std;

const int N = 1e5 + 10;
int a[N];
int dp[512 + 10];

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];

    for (int i = 1; i <= 512; i++) dp[i] = 1000;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= 512; j++) {
            if (dp[j] < a[i])//当a[i]比dp[j]的值大，说明a [i]可以
            //更新这个严格递增序列。
                dp[j ^ a[i]] = min(dp[j ^ a[i]], a[i]);
        }
    }

    vector <int> ans;
    for (int i = 0; i <= 512; i++) {
        if (dp[i] != 1000) ans.push_back(i);
    }
    cout << ans.size() << endl;
    for(int i = 0 ; i < ans.size(); i ++) cout << ans[i] << " ";
    cout << endl;
    return 0;
}
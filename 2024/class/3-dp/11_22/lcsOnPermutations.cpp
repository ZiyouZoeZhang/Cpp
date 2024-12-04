//https://codeforces.com/gym/102951/problem/C
//passed

#include <bits/stdc++.h>
#define FOR(i, a, b)  for(int i = (a); i < (b); i++)
#define ll long long
#define f first
#define s second
#define pb push_back
using namespace std;


/**
 * 找到第二个序列中每个元素在第一个序列中的位置，这个位置构成一个新的序列
 * 需找这个序列中的longest increasing subsequence，这便是这两个sequence的longest common subsequence
 * 把lcs 转化成了 lis
 */


int find_lis(vector<int> a) {
    vector<int> dp;
    for (int i=0; i<a.size(); i++){//或者修改顺序
        int pos = lower_bound(dp.begin(), dp.end(), a[i]) - dp.begin(); 
        //lower_bound 递增 - 同样的元素会被替换
        //upperbound变 不降
        if (pos == dp.size()) {  // we can have a new, longer increasing subsequence!
            dp.push_back(a[i]);
        } else {  // oh ok, at least we can make the ending element smaller
            dp[pos] = a[i];
        }
    }
    return dp.size();
}

int main(){
    int n; cin>>n;
    unordered_map<int, int>m;
    FOR(i, 0, n){
        int a; cin>>a;
        m.insert({a, i});
    }

    vector<int> v;
    FOR(i, 0, n){
        int a; cin>>a;
        v.pb(m.find(a)->second);
    }
    cout<<find_lis(v);
}
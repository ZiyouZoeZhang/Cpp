#include <bits/stdc++.h>
using namespace std;

int find_lis(vector<int> a) {
    vector<int> dp;
    for (int i=0; i<a.size(); i++){//或者修改顺序
        int pos = upper_bound(dp.begin(), dp.end(), a[i]) - dp.begin(); 
        //lower_bound 递增 - 同样的元素会被替换
        //改成upperbound变 不降
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
    vector<int> a;
    for (int i=0; i<n; i++){
        int b; cin>>b;
        a.push_back(b);
    }
    cout<<find_lis(a)<<endl;
    return 0;
}
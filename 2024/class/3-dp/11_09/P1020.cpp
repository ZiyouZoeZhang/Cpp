//导弹拦截系统

#include <bits/stdc++.h>
using namespace std;

int find_lis(vector<int> a) {
    vector<int> dp;
    for (int i=0; i<a.size(); i++){//或者修改顺序
        int pos = lower_bound(dp.begin(), dp.end(), a[i]) - dp.begin(); //递增
        //改成upperbound变 不降
        if (pos == dp.size()) {  // we can have a new, longer increasing subsequence!
            dp.push_back(a[i]);
        } else {  // oh ok, at least we can make the ending element smaller
            dp[pos] = a[i];
        }
    }
    return dp.size();
}

int find_lis_2(vector<int> a) {
    vector<int> dp;
    for (int i=a.size()-1; i>=0; i--){//或者修改顺序
        int pos = upper_bound(dp.begin(), dp.end(), a[i]) - dp.begin(); //递增
        //改成upperbound变 不降
        if (pos == dp.size()) {  // we can have a new, longer increasing subsequence!
            dp.push_back(a[i]);
        } else {  // oh ok, at least we can make the ending element smaller
            dp[pos] = a[i];
        }
    }
    return dp.size();
}

int main (){
    int x;
    vector<int> a;
    while (cin>>x){
        a.push_back(x);
    }
    
    cout<<find_lis_2(a)<<endl;
    cout<<find_lis(a)<<endl;
    
    return 0;

}
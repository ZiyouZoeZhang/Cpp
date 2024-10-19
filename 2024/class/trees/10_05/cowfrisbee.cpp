//https://www.luogu.com.cn/problem/solution/P8094
#include <bits/stdc++.h>
using namespace std;
long long n,ans=0;
long long a[300005];
stack<long long>s;
int main() {
    cin>>n;
    for (int i=1;i<=n;i++)cin>>a[i];
    for (int i=1;i<=n;i++){
        while (!s.empty()&&a[s.top()]<a[i]){
            ans+=i-s.top()+1;
            s.pop();
        }
        if (!s.empty())ans+=i-s.top()+1;
        s.push(i);
    }
    cout<<ans<<endl;
    return 0;
}
//use nearest smallest values
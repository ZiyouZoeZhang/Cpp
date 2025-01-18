//#include </Library/Developer/CommandLineTools/SDKs/MacOSX14.4.sdk/usr/include/c++/v1/bits/stdc++.h>
#include <bits/stdc++.h>
#define FOR(i, a, b)  for(int i = (a); i < (b); i++)
#define ll long long
//#define f first
//#define s second
#define pb push_back
using namespace std;

int gcd(int a, int b) { 
    return b == 0 ? a : gcd(b, a%b);  
}

int main(){
    int n; cin>>n;
    vector<int> v(n);
    FOR(i, 0, n){
        cin>>v[i];
    }

    sort(v.begin(), v.end(), [](int a, int b) {return a > b; });

    int ans = 0;

    FOR(i, 0, n-1){
        if (v[i]<=ans) {break;}
        FOR(j, i+1, n){
            if (v[j]<=ans) {break;}
            ans = max(ans, gcd(v[i], v[j]));
        }
    }

    cout<<ans<<endl;

}
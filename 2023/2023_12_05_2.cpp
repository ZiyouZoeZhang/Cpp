//trial and did not work

//http://www.usaco.org/current/data/sol_prob2_silver_dec20.html

#include <unordered_map>
#include <vector>
#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;
ll C=0, N;
vector<ll>x;
vector<ll>y;
unordered_map<ll, ll>xyR;
unordered_map<ll, ll>yx;
void perm();
bool cal(vector<ll>a);

int main(){
    cin>>N;
    for (ll i=0; i<N; i++){
        ll a, b;
        cin>>a>>b;
        x.push_back(a);
        y.push_back(b);
        yx.insert(make_pair(b,a));
    }
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    for (ll i=0; i<N; i++){
        xyR.insert(make_pair((yx.find(y[i])->second), i));
    }
    perm();
    cout<<C<<endl;
    return 0;

}

void perm() {
    C+=N+1;
    for (ll r=2; r<=N; r++){
        vector<bool> v(N);
        fill(v.end() - r, v.end(), true);
        do {
            vector<ll>a;
            for (ll i = 0; i < N; ++i) {
                if (v[i]) {
                    a.push_back(i);
                }
            }
            if (cal(a)) C++;
        } while (next_permutation(v.begin(), v.end()));
    }
}

bool cal(vector<ll>a){
    ll yMin=0, yMax=0;
    for (int i=0; i<a.size(); i++){
        yMin=min(yMin,xyR.find(x[a[i]])->second);
        yMax=max(yMin,xyR.find(x[a[i]])->second);
    }
    ll c=0;
    for (ll i=a[0]; i<a[a.size()-1]; i++){
        if (i==a[c]) c++;
        else if (xyR.find(x[i])->second > yMin && xyR.find(x[i])->second < yMax) return false;
    }
    return true;
}
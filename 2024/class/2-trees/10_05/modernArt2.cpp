//https://usaco.org/index.php?page=viewproblem2&cpid=743
//double check this
#include <bits/stdc++.h>
#define FOR(i, a, b)  for(ll i = (a); i < (b); i++)
#define ll long long
#define pb push_back
#define s second
#define f first
using namespace std;

int n, v[100010];
bool vis[100010], ss[100010], ee[100010];

void setIO(string name = "") {
    ios_base::sync_with_stdio(0); cin.tie(0);
    if((ll)(name).size()){
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout);
    }
}

int main (void){
    setIO("art2");
    cin>>n;
    memset(vis, false, sizeof(vis));
    memset(ss, false, sizeof(ss));
    memset(ee, false, sizeof(ee));

    v[0] = 0; v[n+1] = 0;
    FOR(i, 1, n+2){
        cin>>v[i];
        if (!vis[v[i]]){ ss[i] = true; vis[v[i]] = true;}
    }
    
    for (int i=n+1; i>=0; i--){
        if (vis[v[i]]) {ee[i] = true; vis[v[i]] = false;}
    }

    stack<int> s;
    int ans = 0;

    FOR(i, 0, n+2){
        if (ss[i]) s.push(v[i]);
        ans = max(ans, (int)s.size());
        if (ee[i]) {
            if (s.top()==v[i]) s.pop();
            else {
                cout<<-1<<endl;
                return 0;
            }
        }
    }
    cout<<ans-1<<endl;
    //if (s.size()==0) cout<<ans-1<<endl;
    //else cout<<-1<<endl;
    return 0;
}
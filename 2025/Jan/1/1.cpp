//final // barely half
#include <bits/stdc++.h>
#define FOR(i, a, b)  for(int i = (a); i < (b); i++)
#define ll long long
#define f first
#define s second
#define pb push_back
using namespace std;

vector<int> ss(int N){
    vector<int> same(N, 0);

    if (N%2!=0){
        same[0] = (N-1)*(N)/2 +1;
        int count = ((N/2))*2;

        FOR(i, 1, N){
            count -= 2;
            same[i] = same[i-1]-count;
            if(i==N/2){
                count += 2;
            }
        }
        if(N==2){
            same[0] = 2;
            same[1] = 2;
        }
        
    }else{
        same[0] = (N-1)*(N)/2 +1;
        int count = ((N/2))*2-1;

        FOR(i, 1, N){
            count -= 2;
            same[i] = same[i-1]-count;
            if (i==N/2 -1){
                same[N/2] = same[N/2 -1];
                i++;
            }

        }
    }

    return same;
}


int main(){
    int N; cin>>N;

    vector<int> same = ss(N);

    vector<int> v(N), v2(N);
    vector<vector<int>> pos(N+10, vector<int>());
    //vector<pair<int, int>> n[500020];

    FOR(i, 0, N){
        cin>>v[i];
    }

    FOR(i, 0, N){
        cin>>v2[i];
        pos[v2[i]].pb(i);
    }

    ll ans = 0;
    FOR(i, 0, N){
        FOR(j, 0, pos[v[i]].size()){
            if(i == pos[v[i]][j]){
                ans += same[i];
                //special
            } else {
                //cout<<min(min(i+1, N-i), min(pos[v[i]][j]+1, N-pos[v[i]][j]))<<endl;
                ans += min(min(i+1, N-i), min(pos[v[i]][j]+1, N-pos[v[i]][j]));
            }
        }
    }

    cout<<ans<<endl;
    return 0;
}
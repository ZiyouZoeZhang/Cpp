#include <bits/stdc++.h>
#define FOR(i, a, b)  for(int i = (a); i < (b); i++)
#define ll long long
#define f first
#define s second
#define pb push_back
using namespace std;

int main(){
    int N;
    cin>>N;

    vector<vector<int>> ini(N, vector<int>(N)), locs(N); //only rows

    vector<int> c(N+N+2, 0);
    vector<int> mp(N+N+2, -1);
    vector<bool> nums((N+N+2), false);

    FOR(i, 0, N){
        FOR(j, 0, N){
            cin>>ini[i][j];
            c[ini[i][j]]++;
            locs[ini[i][j]].pb(i);
        }
    }

    priority_queue<pair<int, int>> rows, later;
    FOR(i, 0, N){
        int minc = N+5;
        FOR(j, 0, N){
            minc = min(minc, c[ini[i][j]]);
        }
        rows.push({minc, i});
    }

    int mx = 0;
    while(!rows.empty() && !later.empty()){
        int i, x;
        if (!rows.empty()) {i = rows.top().s; x=rows.top().f; rows.pop();}
        else {i = later.top().s; later.pop();}

        int tt = 0;
        FOR(j, 0, N){
            if(mp[ini[i][j]]==-1) tt++;
        }

        //if (tt>1) later.push(i);


        FOR(j, 0, N){
            if(mp[ini[i][j]]==-1){
                int count = c[ini[i][j]];

                if (!nums[1+count]){
                    nums[1+count] = true;
                    mp[ini[i][j]] = 1+count;
                } else {
                    nums[N+N+1-count] = true;
                    mp[ini[i][j]] = N+N+1-count;
                }
            }

        }

        /*
        if(rows.top().f<mx) rows.pop();
        else {
            int i = rows.top().s; rows.pop();
            FOR(j, 0, N){
                bits.push({c[ini[i][j]], ini[i][j]});
            }
        }
        */
    }







/*
    FOR(i, 0, N){
        int mn = N+N+2, mxx = 0;
        FOR(j, 0, N){
            if (mp[ini[i][j]]==-1) {
                int count = c[ini[i][j]];
                if (!nums[1+count] && (mn == N+N+2 || abs(mn-(1+count))<=N) && (mxx == 0 || abs(mxx-(1+count))<=N)){
                    nums[1+count] = true;
                    mp[ini[i][j]] = 1+count;
                } else {
                    nums[N+N+1-count] = true;
                    mp[ini[i][j]] = N+N+1-count;
                }
            }

            mn = min(mn, mp[ini[i][j]]);
            mxx = max(mn, mp[ini[i][j]]);
            cout<<mp[ini[i][j]]<<" ";
        }
        cout<<endl;
    }
*/ 

    return 0;


}
//final
#include <bits/stdc++.h>
#define FOR(i, a, b)  for(int i = (a); i < (b); i++)
#define ll long long
#define pb push_back
using namespace std;

vector<vector<int>> tt(int N, vector<vector<int>> ini, vector<int> c, vector<vector<int>> locs, int row, int lowv, int p){
    vector<bool> visr(N+N+5, false);
    vector<bool> taken(N+N+5, false);
    vector<int> mp(N+N+2, -1);

    mp[ini[row][p]] = 2;

    FOR(q, 0, N){
        int mn = N+5, y = 0;
        FOR(j, 0, N){
            if (c[ini[row][j]]!=lowv-1 && c[ini[row][j]]<mn) {
                mn = c[ini[row][j]];
                y = j;
            }

            if(mp[ini[row][j]]!=-1) continue;

            if (!taken[c[ini[row][j]]+1] && (c[ini[row][j]]+1) > lowv){
                mp[ini[row][j]] = c[ini[row][j]] + 1;
                taken[c[ini[row][j]]+1] = true;
            }
            else {
                mp[ini[row][j]] = N+N+1-c[ini[row][j]];
                taken[N+N+1-c[ini[row][j]]] = true;
            }
            
        }

        lowv++;

        visr[row] = true;
        FOR(i, 0, locs[ini[row][y]].size()){
            if (!visr[locs[ini[row][y]][i]]) {
                row = locs[ini[row][y]][i];
                break;
            }
        }
    }

    vector<vector<int>> ans(N, vector<int>(N));

    FOR(i, 0, N){
        FOR(j, 0, N){
            ans[i][j] = mp[ini[i][j]];
        }
    }

    return ans;
}


int solve(int N, vector<vector<int>> ini, vector<int> c, vector<vector<int>> locs){

    vector<vector<int>> ff, ss;
    bool had = false;

    int row, lowv=100;
    FOR(i, 0, N){
        FOR(j, 0, N){
            if(c[ini[i][j]]==1){
                row = i;
                lowv = 2;
                if (!had) {
                    ff = tt(N, ini, c, locs, row, lowv, j); 
                    had = true;
                } else {
                    ss = tt(N, ini, c, locs, row, lowv, j);
                }
            }
        }
    }


    int which = 0;
    if (ss.empty()) which = 1;
    FOR(i, 0, N){
        FOR(j, 0, N){
            if (j==N-1){
                if (which == 0){
                    if (ff[i][j]==ss[i][j]){
                        cout<<ff[i][j];
                    } else if (ff[i][j]>ss[i][j]){
                        which = 2;
                    } else {
                        which = 1;
                    }
                }

                if (which == 1){
                    cout<<ff[i][j];
                } else if (which == 2){
                    cout<<ss[i][j];
                }

                continue;
            }

            if (which == 0){
                if (ff[i][j]==ss[i][j]){
                    cout<<ff[i][j]<<" ";
                } else if (ff[i][j]>ss[i][j]){
                    which = 2;
                } else {
                    which = 1;
                }
            }

            if (which == 1){
                cout<<ff[i][j]<<" ";
            } else if (which == 2){
                cout<<ss[i][j]<<" ";
            }
        }

        cout<<endl;
    }


/*
    cout<<endl<<endl;

    FOR(i, 0, N){
        FOR(j, 0, N){
            cout<<ff[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl<<endl;

    FOR(i, 0, N){
        FOR(j, 0, N){
            cout<<ss[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<endl;
*/
    return 0;

}

int main(){
    int N;
    cin>>N;

    vector<vector<int>> ini(N, vector<int>(N)), locs(N+N+5); //only rows

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

    solve(N, ini, c, locs);

    return 0;


}
//https://usaco.org/index.php?page=viewproblem2&cpid=691
//Hoof Paper Scissors

#include <bits/stdc++.h>
#define FOR(i, a, b)  for(ll i = (a); i < (b); i++)
#define ll long long
#define pb push_back
using namespace std;

void setIO(string name = "") {
    ios_base::sync_with_stdio(0); cin.tie(0);
    if((int)(name).size()){
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout);
    }
}

int N;
char v[100010];
int v2[100010][3];
char v4[3] = {'P', 'S', 'H'};
int v3[3] = {0, 0, 0};

int main (){
    setIO("hps");
    cin>>N;
    FOR(i, 0, N){
        cin>>v[i];
        FOR(j, 0, 3){
            if (v4[j] == v[i]){
                v[i] = j;
                v3[j]++;
                FOR(z, 0, 3){
                    v2[i][z] = v3[z];
                }
                break;
            }
        }
    }

    int mx = 0;

    FOR(i, 0, N){
        FOR(z, 0, 3){
            mx = max(v2[i][v[i]]+v2[N-1][z]-v2[i][z], mx);
        }
    }

    cout<<mx<<endl;


    return 0;


}
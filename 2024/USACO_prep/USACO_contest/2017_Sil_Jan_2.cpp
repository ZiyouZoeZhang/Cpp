//https://usaco.org/index.php?page=viewproblem2&cpid=691
//Hoof Paper Scissors
//fake dp - supposed to be dp, however is not...

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

int N, v2[100010][3];
char a, v4[3] = {'P', 'S', 'H'};

int main (){
    //setIO("hps");
    cin>>N;
    FOR(i, 1, N+1){
        cin>>a;
        FOR(j, 0, 3){
            v2[i][j] = v2[i-1][j];
            if (v4[j] == a) v2[i][j]++;
        }
    }

    int mx = 0;
    FOR(i, 1, N+1){
        mx = max(mx,max(v2[i][0],max(v2[i][1],v2[i][2]))/*前面最多的*/+max(v2[N][0]-v2[i][0],max(v2[N][1]-v2[i][1],v2[N][2]-v2[i][2])/*后面最多的*/));
    }

    cout<<mx<<endl;
    return 0;
}
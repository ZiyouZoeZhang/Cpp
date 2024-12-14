#include <bits/stdc++.h>
#define FOR(i, a, b)  for(int i = (a); i < (b); i++)
#define ll long long
#define f first
//#define s second
#define pb push_back
using namespace std;

int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

int N, M;

bool out(int x, int y){
    if ((x>=0 && x<N && y>=0 && y<M)) return true;
    return false;
}

int main() {

    freopen("/Users/zoezhang/Documents/Home/C/2024/adventOfCode/day6.txt", "r", stdin);

    string s;
    vector<string> v;

    while (getline(cin, s)) {
        v.pb(s);
    }
    N = v.size(), M = v[0].size();

    int x, y, state = -1;
    FOR(i, 0, N){
        FOR(j, 0, M){
            if (v[i][j] == '^'){
                x = i; y = j;
                v[i][j] = 'X';
                state = 0;
                break;
            }
        }
        if (state==0) {break;}
    }

    ll ans = 1;

    while (out(x+dx[state], y+dy[state])){
        if (v[x+dx[state]][y+dy[state]] == '#'){
            state ++;
            if (state==4) state=0;
        } else {
            x += dx[state]; y+= dy[state];
            if (v[x][y] == '.'){
                v[x][y] = 'X';
                ans ++;
            }
        }
    }

    cout<<ans<<endl;

}

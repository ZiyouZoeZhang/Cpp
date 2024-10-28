//https://cses.fi/problemset/task/1147
//2 test cases wrong
#include <bits/stdc++.h>
#define FOR(i, a, b)  for(ll i = (a); i < (b); i++)
#define ll long long
#define pb push_back
#define s second
#define f first
using namespace std;
 
int n, m;
int ini[1000][1000];
int pre[1000][1000];
int bck[1000][1000];
 
int main (){
    clock_t tStart = clock();
 
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("/Users/zoezhang/Documents/Home/C/2024/class/trees/10_19/input.in", "r", stdin);
    cin>>n>>m;
 
    FOR(i, 0, n){
        FOR(j, 0, m){
            char a; cin>>a;
            (a=='.') ? ini[i][j]=1 : ini[i][j]=0; // 1 true = valid = can plant
        }
    }
    
    FOR(i, 0, n){
        int c = 0;
        FOR(j, 0, m){
            (ini[i][j]) ? c++ : c=0;
            pre[i][j] = c;
        }
    }
 
    FOR(i, 0, n){
        int c = 0;
        for (int j=m-1; j>=0; j--){
            (ini[i][j]) ? c++ : c=0;
            bck[i][j] = c;
        }
    }
 
    int mx = 0;
 
    FOR(i, 0, n){
        FOR(j, 0, m){
            //cout<<j<<" ";
            int mi = pre[i][j], z = i, back = 0x3f3f3f3f;
            while (z<n && ini[z][j]) {
                back = min(back, bck[z][j]);
                mi = min(mi, pre[z++][j]);
                mx = max(mx, (int)((z-i)*(mi+back-1)));
            }
            if (j!=0 && ini[i][j-1]) j = j;
            else j+=back;
        }
        //cout<<endl;
    }
    cout<<mx<<endl;
 
    printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
 
}

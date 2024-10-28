//https://cses.fi/problemset/task/1147
//correct but efficiency is crazy
#include <bits/stdc++.h>
#define FOR(i, a, b)  for(ll i = (a); i < (b); i++)
#define ll long long
#define pb push_back
#define s second
#define f first
using namespace std;
 
int n, m;
int noTree[1000][1000];
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
            (a=='.') ? noTree[i][j]=1 : noTree[i][j]=0; // 1 true = valid = can plant
        }
    }
    
    FOR(i, 0, n){
        int c = 0;
        FOR(j, 0, m){
            (noTree[i][j]) ? c++ : c=0;
            pre[i][j] = c;
        }
    }
 
    FOR(i, 0, n){
        int c = 0;
        for (int j=m-1; j>=0; j--){
            (noTree[i][j]) ? c++ : c=0;
            bck[i][j] = c;
        }
    }
 
    int mx = 0;

    //int status = 0; //0 -> add 1, 1 -> add 1, 2 -> add back
 
    FOR(i, 0, n){
        FOR(j, 0, m){
            int mi = pre[i][j], z = i, back = 0x3f3f3f3f;
            while (z<n && noTree[z][j]) {
                back = min(back, bck[z][j]);
                mi = min(mi, pre[z++][j]);
                mx = max(mx, (int)((z-i)*(mi+back-1)));
            }
            if (j!=0 && !noTree[z][j-1]) j+= back-1;
            //cout<<j<<" ";
        }
        //cout<<endl;
    }
 
    cout<<endl<<mx<<endl;
 
    printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);

}
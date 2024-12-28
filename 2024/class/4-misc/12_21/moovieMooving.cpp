#include<bits/stdc++.h>
using namespace std;
const int INF=0x3f3f3f3f;
const int N=20;
int n,m,res=INF,x,y;
int f[1<<N],len[N];
vector<int> v[N];
int main(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++){
        scanf("%d%d",&len[i],&x);
        while(x--){
   scanf("%d",&y);
   v[i].push_back(y);
  }
    }
    for(int x=0;x<(1<<n);x++){
        if(f[x]>=m){
   res=min(res,__builtin_popcount(x));
   continue;
  }
        for(int i=0;i<n;i++){
            if(x&(1<<i)) continue;
            vector<int>::iterator it=upper_bound(v[i].begin(),v[i].end(),f[x]);
            if(it==v[i].begin()) continue;
            it--;
            f[x|(1<<i)]=max(f[x|(1<<i)],*it+len[i]);
        }
    }
    printf("%d\n",res==INF?-1:res);
    return 0;
}


/*#include <bits/stdc++.h>
#define FOR(i, a, b)  for(int i = (a); i < (b); i++)
#define ll long long
//#define f first
//#define s second
#define pb push_back
#define INF 0x3f3f3f3f;
using namespace std;


struct movie{
    int d, c;
    vector<int> t;
};

movie v[20];
int n, l;
int dp[(1<<20)+10]; // end time

int main(){
    cin>>n>>l;
    FOR(i, 0, n){
        cin>>v[i].d>>v[i].c;
        FOR(j, 0 , v[i].c){
            int a; cin>>a;
            v[i].t.pb(a);
        }
    }



}*/
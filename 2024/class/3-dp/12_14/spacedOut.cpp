#include<bits/stdc++.h>
using namespace std;
#define inf 1000000010
const int maxn=510;
int n,a[maxn][maxn],b[maxn][maxn],sum[maxn][maxn];
long long query(int maxx){
    long long ans=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(a[i][j]<maxx)b[i][j]=0,sum[i][j]=0;
            else sum[i][j]=sum[i][j-1]+1,b[i][j]=1;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(b[i][j]==0)continue;
            long long Min=inf;
            for(int k=i;k>=1;k--){
                Min=min(Min,(long long)sum[k][j]);
                ans+=Min;
            }
        }
    }
    return ans;
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            scanf("%d",&a[i][j]);
        }
    }
    printf("%lld",query(100)-query(101));
    return 0;
}
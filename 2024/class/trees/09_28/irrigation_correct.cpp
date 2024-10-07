#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=500001;
int n,m,q,c[N];
ll a[N],k;
int main(){
    scanf("%d%d%d",&n,&m,&q);
    for(int x,i=1;i<=n;++i)
        scanf("%d",&x),a[i]=(ll)(c[x]++)*m+x;
    sort(a+1,a+n+1);
    for(int i=1;i<=n;++i)a[i]-=i;
    while(q--){
        scanf("%lld",&k);
        k+=lower_bound(a+1,a+n+1,k-n)-a-1-n;
        printf("%lld\n",(k-1)%m+1);
    }
}
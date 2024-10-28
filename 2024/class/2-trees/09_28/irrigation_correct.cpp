//to be studied

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=500001;
int n,m,q,c[N];
ll a[N],k;
int main(){
    cin>>n>>m>>q;
    for(int x,i=1;i<=n;++i){
        cin>>x; //olympiad hold in city x; m cities in Berland
        a[i] = (c[x]++)*m+x; //year[i]= (count+1)*cities+citynum
    }
    sort(a+1,a+n+1); //sort years
    for(int i=1;i<=n;++i){
        a[i]-=i; 
    }
    while(q--){
        cin>>k;
        k+=lower_bound(a+1,a+n+1,k-n)-(a+1)-n;
        cout<<(k-1) % m + 1;
    }
}
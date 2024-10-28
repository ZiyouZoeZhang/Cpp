//list removals, trying to be short/302 ch currently
#include <bits/stdc++.h>
#define z int
#define F for(z i=1;i<=n;i++)
#define K std::cin
z n=1,v[z(1e6)],T[z(1e6)]={0};void w(z x,z d){while(x<=n){T[x]+=d;x+=x&-x;}}z main(){K>>n;F{K>>v[i];w(i,1);}F{z x,l=1,r=n+1;K>>x;while(l<r){z M=(l+r)/2,Z=0,a=M;while(a>0){Z+=T[a];a-=a&-a;}Z<x?l=M+1:r=M;}std::cout<<v[l]<<" ";w(l,-1);}}
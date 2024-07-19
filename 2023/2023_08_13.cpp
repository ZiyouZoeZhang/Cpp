/*
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, M;
vector<int> vec;

void first(){
    int x, y, k;
    cin>>x>>y>>k;
    for(int i=x-1; i<=y-1; i++) vec[i]+=k;
    return;
}

int second(){
    int x, y;
    cin>>x>>y;
    int ans=0;
    for(int i=x-1; i<=y-1; i++) ans+=vec[i];
    return ans;
}

int main(){
    cin>>N>>M;
    for (int i=0; i<N; i++){
        int n;
        cin>>n;
        vec.push_back(n);
    }
    for (int i=0; i<M; i++){
        int n;
        cin>>n;
        if (n==1) first();
        else cout<<second()<<endl;
    }
    return 0;
}
*/


#include<iostream>
#include<cstdio>
#define MAXN 1000001
#define ll long long
using namespace std;
unsigned ll n,m,a[MAXN],ans[MAXN<<2],tag[MAXN<<2];

inline ll ls(ll x)
{
    return x<<1;//*2
}

inline ll rs(ll x)
{
    return x<<1|1;//*2+1
}


void scan()
{
    cin>>n>>m;
    for(ll i=1;i<=n;i++)
    scanf("%lld",&a[i]);
}


inline void push_up(ll p) // 更新ans
{
    ans[p]=ans[ls(p)]+ans[rs(p)];
}

void build(ll p,ll l,ll r) //建树 //new node index, left range index, right range index
{
    tag[p]=0;
    if(l==r){ans[p]=a[l]; return;} //l==r==p
    ll mid=(l+r)>>1;
    build(ls(p),l,mid);
    build(rs(p),mid+1,r);
    push_up(p);
} 

inline void f(ll p,ll l,ll r,ll k) //first
{
    tag[p]=tag[p]+k;
    ans[p]=ans[p]+k*(r-l+1);
}

inline void push_down(ll p,ll l,ll r) //更新tag
{
    ll mid=(l+r)>>1;
    f(ls(p),l,mid,tag[p]);
    f(rs(p),mid+1,r,tag[p]);
    tag[p]=0;
}

inline void update(ll nl,ll nr,ll l,ll r,ll p,ll k) //case 1
{
    if(nl<=l&&r<=nr)
    {
        ans[p]+=k*(r-l+1);
        tag[p]+=k;
        return ;
    }
    push_down(p,l,r);
    ll mid=(l+r)>>1;
    if(nl<=mid)update(nl,nr,l,mid,ls(p),k);
    if(nr>mid) update(nl,nr,mid+1,r,rs(p),k);
    push_up(p);
}

ll query(ll q_x,ll q_y,ll l,ll r,ll p) //查询
{
    ll res=0;
    if(q_x<=l&&r<=q_y)return ans[p];
    ll mid=(l+r)>>1;
    push_down(p,l,r);
    if(q_x<=mid)res+=query(q_x,q_y,l,mid,ls(p));
    if(q_y>mid) res+=query(q_x,q_y,mid+1,r,rs(p));
    return res;
}
//2-5 (10)
//
int main()
{
    ll a1,b,c,d,e,f;
    scan();
    build(1,1,n);
    while(m--)
    {
        scanf("%lld",&a1); //long long
        switch(a1)
        {
            case 1:{
                scanf("%lld%lld%lld",&b,&c,&d);
                update(b,c,1,n,1,d);
                break;
            }
            case 2:{
                scanf("%lld%lld",&e,&f);
                printf("%lld\n",query(e,f,1,n,1));
                break;
            }
        }
    }
    return 0;
}
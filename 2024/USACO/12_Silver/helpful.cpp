#include <bits/stdc++.h>
#define FOR(i, a, b)  for(int i = (a); i < (b); i++)
#define ll long long
#define f first
#define s second
#define pb push_back
using namespace std;






//BIT Binary Indexed tree
//区间加单点值 和 区间加区间和

#define lowbit(x) ((x) & - (x))
int n, tree[100000];

void add(int x, int d){
    while (x <= n) {
        tree[x] += d;
        x += lowbit(x);
    }
}

int sum(int x){
    int sum = 0;
    while (x>0){
        //cout<<x<<" "
        sum += tree[x]; 
        x -= lowbit(x);
    }
    return sum;
}

void BIT(){
    cin>>n;

    //to get the sum of 1+...+n
    while (lowbit(n)!=0){
        cout<<n<<" "; //add sum += tree[n]
        n = n-lowbit(n);
    }

    //to change index x, += c
    int x, c;
    cin>>n>>x>>c;
    while(x<=n){
        cout<<x<<" "; //tree[x]+=c;
        x+=lowbit(x);
        
    }
    return;
}
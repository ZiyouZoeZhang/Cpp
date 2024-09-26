//https://usaco.org/index.php?page=viewproblem2&cpid=693
#include <bits/stdc++.h>
#define FOR(i, a, b)  for(ll i = (a); i < (b); i++)
#define ll long long
#define pb push_back
#define lowbit(x) ((x) & - (x))
using namespace std;

int n;
int arr[100010], tree[100010];

void setIO(string name = "") {
    ios_base::sync_with_stdio(0); cin.tie(0);
    if((int)(name).size()){
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout);
    }
}

void add(ll x, ll d){  //ax = ax + d
	while(x <= n) {
	   tree[x] += d;  
       x += lowbit(x); 
	}
}

ll sum(ll x){
    ll sum = 0;
    while (x>0){
        sum += tree[x]; 
        x -= lowbit(x);
    }
    return sum;
}


int main (){
    setIO("bphoto");
    cin>>n;
    priority_queue<pair<int, int>> pq;
    memset(tree, 0, sizeof(tree));
    FOR(i, 0, n){
        cin>>arr[i];
        pq.push({arr[i], i+1});
    }

    int c = 0;
    while(!pq.empty()){
        int h=pq.top().first, i=pq.top().second; pq.pop();

        int l=sum(i), r = sum(n)-l;
        if (max(l, r) > 2*min(l, r)) {
            c++;
            //cout<<l<<" "<<i<<" "<<r<<endl;
        }

        add(i, 1);
    }

    cout<<c<<endl;

    
}
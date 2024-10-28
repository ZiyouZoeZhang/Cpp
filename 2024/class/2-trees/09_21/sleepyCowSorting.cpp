//https://usaco.org/index.php?page=viewproblem2&cpid=898
#include <bits/stdc++.h>
#define FOR(i, a, b)  for(ll i = (a); i < (b); i++)
#define ll long long
#define pb push_back
#define lowbit(x) ((x) & - (x))
using namespace std;

int n, done;
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
    setIO("sleepy");
    cin>>n;
    memset(tree, 0, sizeof(tree));
    FOR(i, 0, n) cin>>arr[i];
    for (int i=n-1; i>0; i--) {
        add(arr[i], 1);
        if (arr[i-1]>arr[i]) {
            done = i; break;
        }
    }

    int total = done;
    cout<<total<<endl;

    FOR(i, 0, done){
        //for each needs to be moved, there are a total of ....
        cout<<total + sum(arr[i])-1<<" ";
        add(arr[i], 1);
        total --;
    }

}

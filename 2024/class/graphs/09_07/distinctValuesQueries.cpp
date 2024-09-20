//https://cses.fi/problemset/task/1734
#include <bits/stdc++.h>
#define FOR(i, a, b)  for(ll i = (a); i < (b); i++)
#define ll long long
#define pb push_back
#define lowbit(x) ((x) & - (x))
using namespace std;

int n, q;
ll tree[200050];

void add(ll x, ll d){  //ax = ax + d
	while(x <= 200050) {
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



int main(){
    memset(tree, 0, sizeof(tree));
    cin>>n>>q;
    set<int> s;
    int size = 0;
    FOR(i, 1, n+1){
        int a; cin>>a;
        size = s.size();
        s.insert(a);
        if (s.size()!=size){
            add(i, 1);
        }
    }

    int a, b;
    FOR(i, 0, q){
        cin>>a>>b;
        //find their index number first;

        //lowerbound ab, 

        //cout<<*s.upper_bound(a)<<endl;
        //cout<<*s.lower_bound(a)<<endl;

        //cout<<upper_bound(v.begin(), v.end(), b)-v.begin()<<" "<<lower_bound(v.begin(), v.end(), a)-v.begin()<<endl;
        cout<<sum(b)<<" "<<sum(a-1)<<endl;
        
    }

}
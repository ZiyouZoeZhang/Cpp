//https://cses.fi/problemset/task/1734
#include <bits/stdc++.h>
#define FOR(i, a, b)  for(ll i = (a); i < (b); i++)
#define ll long long
#define pb push_back
#define lowbit(x) ((x) & - (x))
using namespace std;

//a data structure, set but easy to find

//allocate a "new number" (index) to each number
//before trying to find something, 
//  find the correcsponding index number first, 
//  then use that to find the sum

int n, q, n1;
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

//now upper bound & lower bound;



int main(){
    memset(tree, 0, sizeof(tree));
    cin>>n>>q;
    set<int> s;
    FOR(i, 0, n){
        int a; cin>>a;
        s.insert(a);
    }
    n1 = s.size();
    vector<int> v;
    int i=1;
    for (auto itr: s){
        add(i++, 1);
        v.pb(itr);
    }

    int a, b;
    FOR(i, 0, q){
        cin>>a>>b;
        //find their index number first;

        //lowerbound ab, 

        //cout<<*s.upper_bound(a)<<endl;
        //cout<<*s.lower_bound(a)<<endl;

        //cout<<upper_bound(v.begin(), v.end(), b)-v.begin()<<" "<<lower_bound(v.begin(), v.end(), a)-v.begin()<<endl;
        cout<<sum(upper_bound(v.begin(), v.end(), b)-v.begin()) - sum(lower_bound(v.begin(), v.end(), a)-v.begin())<<endl;

        
        
    }

}
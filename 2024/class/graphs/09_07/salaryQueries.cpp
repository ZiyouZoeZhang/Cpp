//https://cses.fi/problemset/task/1144
// little things to be edited -> watch cloud recordings later

#include <bits/stdc++.h>
#define FOR(i, a, b)  for(ll i = (a); i < (b); i++)
#define ll long long
#define pb push_back
#define lowbit(x) ((x) & - (x))
using namespace std;
 
int n, q, tree[20000010], salary[200010];
 
void add(ll x, ll d){  //ax = ax + d
	while(x <= 20000010) {
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
    memset(salary, 0, sizeof(salary));
    memset(tree, 0, sizeof(tree));
    cin>>n>>q;
    FOR (i, 1, n+1) {
        cin>>salary[i];
        add(salary[i], 1);
    }
 
    FOR (i, 0, q){
        char a; cin>>a;
        int b, c; cin>>b>>c;
        if (a=='!'){ //employee b salary to c
            add(salary[b], -1);
            salary[b] = c;
            add(salary[b], 1);
        } else { //count salary between a and b
            cout<<(sum(c)-sum(b-1))<<endl;
        }
 
    }
}
//https://cses.fi/problemset/task/1734

int n, q;
int d[200010];
int tree[200010];

#include <bits/stdc++.h>
#define FOR(i, a, b)  for(ll i = (a); i < (b); i++)
#define ll long long
#define pb push_back
#define lowbit(x) ((x) & - (x))
using namespace std;

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

int main (){
    cin>>n>>q;

    FOR(i, 0, n) cin>>d[i]; //query input

    vector<vector<pair<int, int>>> qq(n+10);
    vector<int> ans(n+1);

    FOR(i, 1, q+1){ //问题们
        int a, b; cin>>a>>b;
        qq[a].pb({b, i}); //把同一个起点放在同一个数组元素中，然后开始“挪动” 起点的位置
    }

    map<int, int>last; //每一个元素最后一次出现的位置在哪里？
    for (int i = n-1; i>=0; i--){
        int val = d[i]; //current wal
        if (last.count(val) > 0){ //出现过
            add(last[val], -1); //之前的位置
        } 
        add(i, 1); //当前的位置
        last[val] = i;

        /*
        for (auto [a, b]: qq[i]) { //i 作为起点，a是终点，b是位置
            ans[b] = sum(a); 
        }
        */
        for (auto s: qq[i]){
            int a = s.first, b= s.second;
            ans[b] = sum(a);
        }
    }
    
    FOR(i, 1, q+1) {
        cout<<ans[i]<<endl;
    }

    return 0;

}


/*
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

}
*/
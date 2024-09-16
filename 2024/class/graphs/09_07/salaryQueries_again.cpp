//https://cses.fi/problemset/task/1144
//like shit...
#include <bits/stdc++.h>
#define FOR(i, a, b)  for(ll i = (a); i < (b); i++)
#define ll long long
#define pb push_back
#define f first
#define s second
#define lowbit(x) ((x) & - (x))
using namespace std;

int n, q, tree[100000010], salary[200010];
unordered_map<int, int> um;

void add(ll x, ll d){  //ax = ax + d
	while(x <= 100000010) {
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

void change(int b, int c){
    add(um[salary[b]], -1);
    salary[b] = c;
    add(um[salary[b]]+1, 1);
}

void output(int b, int c){
    cout<<(sum(c)-sum(b-1))<<endl;
}

int main (){
    memset(salary, 0, sizeof(salary));
    memset(tree, 0, sizeof(tree));
    cin>>n>>q;

    vector<pair<char, pair<int, int>>> input(q);
    set<int> unique;

    FOR (i, 1, n+1) {
        cin>>salary[i];
        unique.insert(salary[i]); //add to set
    }
    FOR(i, 0, q){
        cin>>input[i].f>>input[i].s.f>>input[i].s.s; //char, a, b
        if (input[i].f=='!') unique.insert(input[i].s.s); //add to set
    }
    
    //make the conversion where I input the salary, you give the index number!
    //salary -> int
    int i=1; for (auto a: unique) {um[a]=i; i++;} //indx starting from 0 

    //continued -> preprare tree
    FOR(j, 1, n+1) {
        add(um[salary[j]], 1);
    }
    FOR(j, 0, 7+1) cout<<(sum(um[j]+1)-sum(um[j]))<<endl;

    for (auto i: input) {
        char a = i.f; int b= i.s.f, c = i.s.s;
        if (a=='!') change(b, c);
        else output(um[b], um[c]);
    }
}



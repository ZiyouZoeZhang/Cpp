//https://usaco.org/index.php?page=viewproblem2&cpid=1014
#include <bits/stdc++.h>
#define FOR(i, a, b)  for(int i = (a); i < (b); i++)
#define pb push_back
using namespace std;

int n, m, k;
vector<int> v, ans;
vector<bool> vis;

void Floyd(int x){ //处理环的
    int a = v[x];
    int b = v[v[x]];
    while (a!=b){
        a = v[a];
        b = v[v[b]];
    } 
    a = x;
    while (a!=b){
        a = v[a];
        b = v[b];
    }
    int first = a; //where the cycle starts

    queue<int> q;

    int length = 1; 
    int cur = x;
    int cyl = false;
    while (cur==first && cyl){
        q.push(cur);
        cur = v[cur];
        if (cur == first && !cyl) cyl = true;
        if (cyl) length++; 
    }

    int lengout = q.size()-length;

    int to = v[x];
    FOR(i, 0, (k-lengout)%length) to = v[to];

    while(!q.empty()){
        ans[q.front()] = to;
        to = v[to];
        vis[q.front()] = true;
        q.pop(); 
    }

    return;
}

int main (){
    cin>>n>>m>>k;

    v.resize(n);
    ans.resize(n, 0);
    vis.resize(n, false);
    FOR(i, 0, n) v[i] = i;

    FOR(i, 0, m){
        int l, r;
        cin>>l>>r;
        swap(v[--l], v[--r]);
    }

    FOR (i, 0, m){
        if (!vis[i]) Floyd(i);
    }

    FOR (i, 0, n){
        cout<<ans[i]++<<" ";
    }
}


/*
5 4 2
1 2
2 3
3 4
4 5
*/
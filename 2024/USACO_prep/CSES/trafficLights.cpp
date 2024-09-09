//https://cses.fi/problemset/task/1163

//not done

#include <bits/stdc++.h>
#define FOR(i, a, b)  for(int i = (a); i < (b); i++)
#define pb push_back
using namespace std;

int main (){
    int x, n;
    cin>>x>>n;

    set<pair<int, int>> s;
    priority_queue<int> pq;

    s.insert({x, x});
    pq.push(x);

    FOR(i, 0, n){
        int a;
        cin>>a;

        //s.lower_bound(a);
    }


}
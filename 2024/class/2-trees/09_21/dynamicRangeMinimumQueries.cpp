//https://cses.fi/problemset/task/1649
/**
 * example of how the template for segement tree (and the sum) 
 * and be easily modified to know the minimum value in a given subsequence
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll tree[400010];
ll arr[400010];
int n, q;
 
void add(int k, ll x) {
    k += n;
    tree[k] += x;
    for (k /= 2; k >= 1; k /= 2) {
        tree[k] = min(tree[2*k], tree[2*k+1]);
    }
}
ll sum(int a, int b) {
    a += n; b += n;
    ll mi = 0x3f3f3f3f;
    while (a <= b) {
        if (a%2 == 1) mi = min(mi, tree[a++]);
        if (b%2 == 0) mi = min(mi, tree[b--]);
        a /= 2; b /= 2;
    }
    return mi;
}
 
int main(){
    cin>>n>>q;
    for (int i=0; i <n; i++){
        cin>>arr[i];
        add(i,arr[i]);
    }
    for (int i=1; i <= q; i++){
        int a, b, c;
        cin>>a>>b>>c;
        if (a == 1){
            b--;
            add(b, c - arr[b]);
            arr[b] = c;
        }
        else {
            b--;
            c--;
            cout<<sum(b, c) << endl;
        }
    }
}
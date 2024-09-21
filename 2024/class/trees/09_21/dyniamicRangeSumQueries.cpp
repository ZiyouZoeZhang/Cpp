//study this code
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
ll tree[400010];
ll arr[400010];
int n, q;
 
void add(int k, ll x) {
    k += n;
    tree[k] += x;
    for (k /= 2; k >= 1; k /= 2) {
        tree[k] = tree[2*k]+tree[2*k+1];
    }
}
ll sum(int a, int b) {
    a += n; b += n;
    ll s = 0;
    while (a <= b) {
        if (a%2 == 1) s += tree[a++];
        if (b%2 == 0) s += tree[b--];
        a /= 2; b /= 2;
    }
    return s;
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
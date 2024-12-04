//https://usaco.org/index.php?page=viewproblem2&cpid=574
#include <bits/stdc++.h>
#define FOR(i, a, b)  for(ll i = (a); i < (b); i++)
#define ll long long
#define pb push_back
using namespace std;
int t, a, b;
int canReach[5000010];

int main (){
    cin>>t>>a>>b;
    memset(canReach, 0, sizeof(canReach));
    canReach[a] = true; canReach[b] = true;
    for (int i=a; i<=t; i++) {if (canReach[i-a]) canReach[i] = true;}
    for (int i=b; i<=t; i++) {if (canReach[i-b]) canReach[i] = true;}
    for(int i=0; i<=t; i++) {if (canReach[i]/2) canReach[i] = true;}
    for (int i=a; i<=t; i++) {if (canReach[i-a]) canReach[i] = true;}
    for (int i=b; i<=t; i++) {if (canReach[i-b]) canReach[i] = true;}
    for (int i=t; i>=0; i--) {if (canReach[i]) cout<<i<<endl;}

    return 0;
}
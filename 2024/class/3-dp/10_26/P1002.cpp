#include <bits/stdc++.h>
#define FOR(i, a, b)  for(ll i = (a); i < (b); i++)
#define ll long long
#define pb push_back
#define s second
#define f first
using namespace std;


int f(int x, int y){


    return f(x+1, y) + f(x, y+1)
}
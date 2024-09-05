//test of whether the binary search for "substring.cpp" works
//https://usaco.org/index.php?page=viewproblem2&cpid=838
#include <bits/stdc++.h>
#define FOR(i, a, b)  for(int i = (a); i < (b); i++)
#define pb push_back
using namespace std;

bool check(int x){
    return false;

}

vector<bool> ok = {true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, false, false, false, false, };


int main (){
    int n = ok.size();
    //int x = n-1;

    int x = -1; 
    for (int b = n; b >= 1; b /= 2) {
        while (ok[x+b]) {
            x += b; 
            cout<<x<<" ";
        }

    } 
    int k = x;
    cout<<endl<<k<<endl;
/*
    for (int b = n-1; b >=1 ; b /= 2) {
        while (!ok[x-b]){ 
            int a = x-b;
            x -= b;
        }
        cout<<endl<<x;
        
    }
*/
    return 0;
}
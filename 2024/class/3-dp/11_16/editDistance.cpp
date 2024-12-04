/**
 * edit Distance / levenshtein distance
 *  the "edit distance" between 2 Strings
 * Valid operations
 * - insert a character
 * - remove a character
 * - edit a character
 * 
 * very important concept:
 * 
 */


#include <bits/stdc++.h>
#define FOR(i, a, b)  for(ll i = (a); i < (b); i++)
#define ll long long
#define pb push_back
using namespace std;

int main (){
    string a, b;
    cin>>a>>b;

    int dp[a.size()+1][b.size()+1];
    memset(dp, 0x3f3f3f3f, sizeof(dp));

    dp[0][0] = 0;

    FOR(i, 0, a.size()+1){
        FOR(j, 0, b.size()+1){
            if (i!=0) dp[i][j] = min(dp[i][j], dp[i-1][j] + 1);
            if (j!=0) dp[i][j] = min(dp[i][j], dp[i][j-1] + 1);
            if (i!=0 && j!=0) {
                int new_cost = dp[i-1][j-1] + (a[i-1] != b[j-1]);
                dp[i][j] = min(dp[i][j], new_cost);
            }
        }
    }

    cout<<dp[a.size()][b.size()]<<endl;
    return 0;

}
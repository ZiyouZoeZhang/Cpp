#include <bits/stdc++.h>
#define FOR(i, a, b)  for(int i = (a); i < (b); i++)
#define ll long long
#define f first
#define s second
#define pb push_back
using namespace std;


int main (){
    string s;
    cin>>s;

    vector<vector<int>> dp(s.size()+1, vector<int>(s.size()+1, 0));
    //dp[i][j] - ways to empty the subtsring [i,j]
    //to find - loop k (between i, j), where s[i] == s[k]
    //now to remove s[i] & s[k], we need to remove s[i+1] & s[k-1], with cost dp[i+1][k-1]
    //now to remove [k+1, j]], with dp[k+1][j]
    

}
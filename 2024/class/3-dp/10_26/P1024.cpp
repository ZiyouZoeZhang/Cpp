//not done yet
#include <bits/stdc++.h>
using namespace std;

int dp[100010];

int main(){

}

int f(int a){
    if (a==1){
        dp[a]=1;
        return dp[a];
    } 
    if (dp[a]!=0){
        return dp[a];
    }
    for (int i=0; i<(a/=2)+1;)
}
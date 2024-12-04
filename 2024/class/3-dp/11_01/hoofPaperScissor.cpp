#include <bits/stdc++.h>
using namespace;

/**
 * 首先确定dp的维度和限制条件，
 * 这道题比如就是dp[i][j][k] -> 轮次，变化次数，当先手势
 * 
 * dpli］ ljl ［k］：前i轮已经变换了j次手势且最后的手势是k的情况下最多获胜的轮次。
 * i：轮次
 * j：变换手势的次数
 * k：最后出的手势，Q/1/2，0>>1>>2>>0，H:0,S:1,P:2
 * dp [i][j][0] = max (dp [it][j-1][1], dp[it][j-1][2]+H[i]-H[it])
 * dp [i][j][1] = max (dp [it][j-1][2], dp[it][j-1][0]+S[i]-S[it])
 * dp [i][j][2] = max (dp [it][j-1][0], dp[it][j-1][1]+P[i]-P[it])
 * 
 * dp[i][j][k]: 前i轮已经变换了j次手势且最后的手势是k的情况下最多获胜的轮次。

i:轮次
j:变换手势的次数
k:最后出的手势，0/1/2, 0>>1>>2>>0, H:0,S:1,P:2

dp[i][j][0] = max(dp[i][j][0],max(dp[it][j-1][1], dp[it][j-1][2])+H[i]-H[it]);
dp[i][j][1] = max(dp[i][j][1],max(dp[it][j-1][0],dp[it][j-1][2])+S[i]-S[it]);
dp[i][j][2] = max(dp[i][j][2],max(dp[it][j-1][0],dp[it][j-1][1])+P[i]-P[it]);


------------it--------------------i
            1                     1
           j-1                    j
           0/2                    0



for(int i = 0; i < = m ;i++){
 ans = max(ans,max(dp[n][i][0],dp[n][i][1],dp[n][i][2]))
}

cout << ans << endl;
*/

int main (){
    

}
//https://usaco.org/index.php?page=viewproblem2&cpid=670
#include <bits/stdc++.h>
#define FOR(i, a, b)  for(ll i = (a); i < (b); i++)
#define ll long long
#define f first
#define s second
#define pb push_back
using namespace std;

int dist(int x1, int y1, int x2, int y2){
    return (pow((x2-x1), 2)+pow((y2-y1), 2));
}

int dist(pair<int, int>a, pair<int, int>b){
    cout<<(pow((a.f - b.f), 2)+pow((a.s - b.s), 2))<<endl;
    return (pow((a.f - b.f), 2)+pow((a.s - b.s), 2));
}


int main (){
    //each cow could either come from the same breed (but num -1) or from the other breed (any num)
    /**
     * 两个品种的序列 - 循环序列1，循环序列2
     * 
     */
    int H, G;
    cin>>H>>G;
    vector<pair<int, int>> Hs(H), Gs(G);
    FOR(i, 0, H) cin>>Hs[i].f>>Hs[i].s;
    FOR(i, 0, G) cin>>Gs[i].f>>Gs[i].s;

    //int dp[H+1][G+1][2]; // 0-H, 1-G
    vector<vector<vector<int>>> dp(H+1, vector<vector<int>>(G+1, vector<int> (2, 0x3f3f3f3f)));
    //memset(dp, 0x3f3f3f3f, sizeof(dp));

   dp[1][0][0] = 0; //站在第一个元素的位置，还没有到达第二个元素 - 初始化位置，total distace 为0


    FOR(i, 0, H+1){
        FOR(j, 0, G+1){
            /*
            FOR(z, 0, 2){
                if (i!=0) dp[i][j][z]  = min (dp[i][j][z], dp[i-1][j][z]+dist(Hs[i-1], Hs[i]));
                if (j!=0) dp[i][j][z]  = min (dp[i][j][z], dp[i][j-1][!z]+dist(Gs[j-1], Hs[i]));
            }
            */

            if (i>1){
                dp[i][j][0] = min(dp[i][j][0], dp[i-1][j][0] + dist(Hs[i-2],Hs[i-1]));
            }
            if (j>1){
                dp[i][j][1] = min(dp[i][j][1], dp[i][j-1][1] + dist(Gs[j-2], Gs[j-1]));
            }

            if (i!=0 && j!=0){
                dp[i][j][0] = min(dp[i][j][0], dp[i-1][j][1] + dist(Gs[j-1], Hs[i-1]));
                dp[i][j][1] = min(dp[i][j][1], dp[i][j-1][0] + dist(Gs[j-1], Hs[i-1]));
            }



        }
    }
    cout<<dp[H][G][0]<<endl;


}
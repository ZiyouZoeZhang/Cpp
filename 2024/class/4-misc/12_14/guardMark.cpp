//https://usaco.org/index.php?page=viewproblem2&cpid=494
#include <bits/stdc++.h>
#define FOR(i, a, b)  for(int i = (a); i < (b); i++)
#define ll long long
//#define f first
//#define s second
#define pb push_back
#define INF 0x3f3f3f3f;
using namespace std;

int n, h;
struct cow{
    int h, w, s;
};
cow d[21];
//dp[s]:放入牛塔的牛的集合为s时可以支持的载重。
int dp[(1<<20)+10]; //how much it could still hold.

int main(){
    cin>>n>>h; //N<=20, 状态压缩

    FOR(i, 0, n){
        //height, weight stregth
        cin>>d[i].h>>d[i].s>>d[i].w;
    }

    //对于没有牛 - 都有一个选中vs.不选中

    memset(dp, -1, sizeof(dp));

    dp[0] = 1000000000;
    int ans = -1;

    FOR(s, 0, (1<<n)){ //subset
        int height = 0;
        FOR(j, 0, n){
            if (s&(1<<j)){ //if j-th digit is true;
                height += d[j].h;
                dp[s] = max(dp[s], min( dp[s^(1<<j)] - d[j].w, d[j].s)); //假设移除j，那么j以下元素会增加 d[j].w 的“余额”
            }
        }
        if (height >= h){
            ans = max(ans, dp[s]);
        }
    }

    if (ans > -1){
        cout<<ans<<endl;
    } else {
        cout<<"Mark is too tall"<<endl;
    }

}

/*2 10
3 3 2
7 2 0*/
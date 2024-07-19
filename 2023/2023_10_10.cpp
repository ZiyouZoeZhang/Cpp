//01背包
#include<iostream>
#include<vector>
using namespace std;

//modified version

vector<int> wgt;
vector<int> val;
vector<vector<int> > dp;

int main(){
    int c, n, t, v; //c=capacity, n=number of things
    cin >>c>>n;

    wgt.resize(n);
    val.resize(n);
    dp.resize(n + 1, vector<int>(c + 1, 0));

    for (int i = 0; i < n; ++i) {
        cin >> t >> v;
        wgt[i] = t;
        val[i] = v;
    }

    for (int i=1; i<=n; ++i) {
        for (int j=1; j<=c; ++j) {
            if (wgt[i-1]>j) {
                dp[i][j] = dp[i-1][j]; // Cannot include the item
            } else {
                dp[i][j] = max(dp[i-1][j], val[i-1] + dp[i-1][j-wgt[i-1]]); // Maximum of including or excluding the item
            }
        }
    }

    cout<<dp[n][c]<<endl; // Maximum value that can be obtained
    return 0;
}

//older version

/*
#include<iostream>
#include<vector>
using namespace std;
int check(int i, int c);
vector<int> wgt;
vector<int> val;
vector<vector<int> >dp;

int main(){
    int c, n, t, v; //c=capacity, n=number of things
    cin>>c>>n;
    dp.resize(n+1, vector<int>(c+1));
    while (n-->0){
        cin>>t>>v;
        wgt.push_back(t);
        val.push_back(v);
    }
    cout<<check(val.size(), c);
    return 0;
}

int check(int n, int c) {
    int max_val=0;
    for (int i=1; i<=n; i++){ //item intex = [i-1], dp index [i][j]
        for (int j=1; j<=c; j++){
            if(wgt[i-1]>j) dp[i][j] = dp[i-1][j]; //装不下
            else { //装得下
                if (dp[i-1][j]>dp[i-1][j]+val[i-1]+dp[i-1][j-wgt[i-1]]) dp[i][j] = dp[i-1][j]; //不装了
                else { //装一下吧
                    dp[i][j]=val[i-1]+dp[i-1][j-wgt[i-1]]; //+dp[i-1][j]
                    //while(++j<=c) dp[i][j]=dp[i][j-1];
                    //break;
                }
            }
        }
    }
    for (int i=1; i<=n; i++){
        max_val=max(max_val,dp[i][c]);
    }
    return max_val;
}
*/
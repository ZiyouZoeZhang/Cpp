#include <iostream>
#include <string>
using namespace std;

int main(){
    int maxn=0,id=0;
    string chuan;
    cin>>chuan;
    int dp[1000];
    for(int i=0;i<chuan.size();i++){
        dp[i]=0;
        }
        for (int i = 1; i < chuan.size(); i++) {
            if (chuan[i] == ')') {
                if (chuan[i - 1] == '(') {//1.()   if i>=2 dp[i]=dp[i-2]+2 else dp[i]=0+2
                dp[i] = (i >= 2 ? dp[i - 2] : 0) + 2;
                } else if (i - dp[i - 1] > 0 && chuan[i - dp[i - 1] - 1] == '(') {//))
                dp[i] = dp[i - 1] + ((i - dp[i - 1]) >= 2 ? dp[i - dp[i - 1] - 2] : 0) + 2;
                }
            }
        }
        //i-dp[i-1]=2   dp[i-1]=i-1
        //  i-1   i       
        /*askudbasbasjgdajyg))*/
        for(int i=0;i<chuan.size();i++){
            if(maxn<dp[i]){
                maxn=dp[i];
                id=i;
                }
        }
        for(int i=maxn-1;i>=0;i--){
            cout<<chuan[id-i];
            }
            return 0;
}

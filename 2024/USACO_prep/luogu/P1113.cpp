//https://www.luogu.com.cn/problem/P1113
//不要想太多了！！Don't overthink the problems!!
#include<bits/stdc++.h>
#define f first
#define s second
#define INF 0x3f3f3f3f
using namespace std;

int N, ans[10005], maxans;

int main (){
    cin>>N;
    for (int i=1; i<=N; i++){
        int a, c, b;
        cin>>a>>c>>b;
        int temp = 0;
        while(b!=0){
            temp = max(ans[b], temp);
            cin>>b;
        }
        ans[i] = temp + c;
        maxans = max (maxans, ans[i]);
    }
    cout<<maxans<<endl;
    
    return 0;

}
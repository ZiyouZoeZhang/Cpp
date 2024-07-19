//https://codeforces.com/contest/1838/problem/B

#include <iostream>
using namespace std;
void pro();

int main(){
    int t;
    cin>>t;
    for (int i=0; i<t; ++i) pro();
    return 0;
}
void pro(){
    int p1, p2, pn, n;
    cin>>n;
    for (int i=1; i<=n; ++i){
        int pi;
        cin>>pi;
        if (pi==1) p1=i;
        if (pi==2) p2=i;
        if (pi==n) pn=i;
    }
    if ((p1<pn && pn<p2) || (p2<pn && pn<p1)) cout<<1<<' '<<1;
    else if (p1-1==p2 || p2-1==p1) {
        if (p1<pn) cout<<pn<<' '<<max(p1,p2);
        else cout<<pn<<' '<<min(p1,p2);
    } else {
        cout<<pn<<' '<<min(p1,p2)+1;
    }
    //记录1，2 和max的位置 （过一遍）
    //如果1挨着2，把离max近的和max调换位置
    //else把1和2中间的一个数和max调换位置
    //如果max在1和2中间，随便了。。。
    cout<<endl;
    return;
}

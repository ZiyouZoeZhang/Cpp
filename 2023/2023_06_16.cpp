//USACO 2022 December Contest, Silver
//Problem 1. Barn Tree
//http://www.usaco.org/index.php?page=viewproblem2&cpid=1254 

/*
Farmer John's farm has N barns (2≤N≤2⋅105) numbered 1…N. There are N−1 roads, 
where each road connects two barns and it is possible to get from any barn to 
any other barn via some sequence of roads. Currently, the j th barn has hj hay bales (1≤hj≤109).

To please his cows, Farmer John would like to move the hay such that each barn has
an equal number of bales. He can select any pair of barns connected by a road and 
order his farmhands to move any positive integer number of bales less than or equal 
to the number of bales currently at the first barn from the first barn to the second.

Please determine a sequence of orders Farmer John can issue to complete the task in the 
minimum possible number of orders. It is guaranteed that a sequence of orders exists.

*/


#include<iostream>
#include<vector>

using namespace std;

vector<int>G[10];
vector<int>a(10);
int main(){
    int aver, n;
    int sum=0;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i], sum += a[i];
    aver = sum / n;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    bool done = 1;
    while (done==1){
        done=0;
        for (int i=1; i<=n; i++){
            //如果有任何size=1，已满足aver的直接cut掉
            //优先解决所有孩子的问题。
            //如果多了，直接上交
            //如果少了，先从旁边吸，吸不到就collect全部需要吸的然后一并从上面吸。
            if(a[i]==aver && G[i].size()==1){
                done=1;
                remove(G[G[i][0]].begin(),G[G[i][0]].end(),i);
                G[i].clear();
            } else if(G[i].size()==1 && (a[i]>aver || (a[i]<aver && a[G[i][0]]>=aver-a[i])) ){
                done=1;
                a[G[i][0]]=a[G[i][0]]+a[i]-aver;
                a[i]=aver;
                remove(G[G[i][0]].begin(),G[G[i][0]].end(),i);
                G[i].clear();
            }
        }
        cout<<done<<endl;
    }
   return 0;
}
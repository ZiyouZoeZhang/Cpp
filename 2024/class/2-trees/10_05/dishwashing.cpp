//https://usaco.org/index.php?page=viewproblem2&cpid=922
//stack模拟
#include<bits/stdc++.h>
using namespace std;
int n,placed,base[100001];
stack<int> item[100001];

void setIO(string name = "") {
    ios_base::sync_with_stdio(0); cin.tie(0);
    if((int)(name).size()){
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout);
    }
}

int main(){
    //setIO("dishes");
    cin>>n;
    for(int i=1;i<=n;i++){
        int x; cin>>x;

        if(x<placed){
            cout<<i-1;
            return 0;
        }

        for(int j=x;j>0&&!base[j];j--)base[j]=x;
        while(!item[base[x]].empty()&&item[base[x]].top()<x){
            placed=item[base[x]].top();
            item[base[x]].pop();
        }
            item[base[x]].push(x);
    }
    cout<<n<<endl;
    return 0;
}

/*
核心思路 -》 因为要求取大值 -》用二分 -> see 10_19, dishwashing_sol2.cpp
直接用栈结构来做 -> this solution
*/
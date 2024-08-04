#include <bits/stdc++.h>
using namespace std;

int n,k,a,b,near[100001],ans;
vector<int> tree[100001];

void dfs1 (int i,int father){
    near[i]=0x7fffffff;
    if(tree[i].size()==1) near[i] = 0;

    for(int k=0;k<tree[i].size();k++){
        int now = tree[i][k];
        if(now != father){
            dfs1(now,i);
            near[i]=min(near[i],near[now]+1);
        }
    }
}

void dfs2 (int i,int father, int depth){
    if(depth>=near[i]){
        ans ++;
        return;
    }
    for(int k=0;k< tree[i].size();k++){
        int now=tree[i][k];
        if(now!=father) dfs2(now,i,depth+1);
    }
}

int main(){
    cin>>n>>k;
    for(int i=1;i<n;i++){
        cin>>a>>b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    dfs1(k,0);
    dfs2(k,0,0);
    cout<<ans;
    return 0;
}
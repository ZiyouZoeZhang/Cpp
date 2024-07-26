//https://usaco.org/index.php?page=viewproblem2&cpid=104

#include<bits/stdc++.h>
using namespace std;

int main (){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, K;
    cin>>N>>K;
    vector<int> v(N, 0);
    for (int i=0; i<K; i++){
        int a, b;
        cin>>a>>b;
        v[b-1]++;
        if(a-2>-1) v[a-2]--;
    }

    int s = 0;
    for (int i=N-1; i>=0; i--){
        s+=v[i];
        v[i]=s;
    }

    sort(v.begin(), v.end());
    cout<<v[N/2]<<endl;
    return 0;

}
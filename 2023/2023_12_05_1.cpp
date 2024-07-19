
//USACO 2020 December Contest, Silver
//Problem 1. Cowntagion
//http://www.usaco.org/index.php?page=viewproblem2&cpid=1062

#include<iostream>
#include <vector>
using namespace std;
long long N, C=0;
vector<vector<int> >f;
void cal(long long p, long long c);

int main(){
    cin>>N;
    f.resize(N);
    for (int i=0; i<N-1; i++){
        long long a, b;
        cin>>a>>b;
        f[a-1].push_back(b-1);
        f[b-1].push_back(a-1);
    }
    cal(-1,0);
    cout<<C<<endl;
}

void cal(long long p, long long c){//parent & current
    long long d=1;
    if (p==-1){
        while(d<=f[c].size()) d*=2, C++;
    }
    else {
        while (d<f[c].size()){ //different for 1; cal later
            d*=2;
            C++;
        }
    }
    for (long long i=0; i<f[c].size(); i++){
        if (f[c][i]!=p){
            C++;
            cal(c, f[c][i]);
        }
    }
    return;
}
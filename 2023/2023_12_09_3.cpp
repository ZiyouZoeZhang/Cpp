//USACO 2021 January Contest, Bronze
//Problem 3. Just Stalling
//http://www.usaco.org/index.php?page=viewproblem2&cpid=1085&lang=zh

#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int>cowh(n);
    vector<int>stallh(n);
    vector<int>a;
    for (int i=0; i<n; i++){
        cin>>cowh[i];
    }
    for (int i=0; i<n; i++){
        cin>>stallh[i];
    }
    for (int i=0; i<n; i++){
        int c=0;
        for (int j=0; j<n; j++){
            if(cowh[i]<=stallh[j]) c++;
        }
        a.push_back(c);
    }
    sort(a.begin(), a.end());
    long long ans=1;
    for (int i=0; i<n; i++){
        ans=ans*(a[i]-i);
    }
    cout<<ans<<endl;
}

/*
1 2 3 4
2 4 3 4

2 3 4 4
2 2 2 1
=8
*/
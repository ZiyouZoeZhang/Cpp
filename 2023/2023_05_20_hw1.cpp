//USACO 2023 January Contest, Silver
//Problem 3. Moo Route
//http://www.usaco.org/index.php?page=viewproblem2&cpid=1280 

#include <iostream>
#include <utility>
#include <vector>
#define CHECK if(travel[cur]==0 && cur==travel.size()-1) travel.pop_back(); if (travel.size()==0) return s;
#define PUSH_BACK if (i==1) s.push_back('R'); else s.push_back('L');
using namespace std;

string cal(int n, vector<int>travel);

int main() {
    freopen("11.in","r",stdin);
    ios::sync_with_stdio(0), cin.tie(0);
    int n, a;
    cin>>n;
    vector<int>travel;
    for (int i=0; i<n; ++i) cin>>a, travel.push_back(a);
    cout<<cal(n, travel);
    return 0;
}

string cal(int n, vector<int>travel) {
    string s="R";
    int cur=0, i=1;
    while(true){
        travel[cur]--;
        CHECK;
        //-------------------------------------------------------------------------------------
        while (((cur+i==-1) || cur+i==travel.size() || (i==-1 && travel[cur-1]==1 && cur!=travel.size())) && travel[cur]>0){
            travel[cur]-=1, i=-i;
            PUSH_BACK;
        }
        CHECK;
        PUSH_BACK;
        cur+=i;
    }
}
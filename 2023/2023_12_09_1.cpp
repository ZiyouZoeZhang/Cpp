//USACO 2021 January Contest, Bronze
//Problem 1. Uddered but not Herd
//http://www.usaco.org/index.php?page=viewproblem2&cpid=1083

#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

int main(){
    unordered_map<char, int>myMap;
    string a, b;
    cin>>a>>b;
    for (int i=0; i<26; i++){
        myMap.insert(make_pair(a[i],i));
    }
    int count=0, cur=26;
    for (int i=0; i<b.size(); i++){
        if(myMap.find(b[i])->second <= cur) {
            count++;
            cur=myMap.find(b[i])->second;
        }
        else cur=myMap.find(b[i])->second;
    }
    cout<<count<<endl;
}
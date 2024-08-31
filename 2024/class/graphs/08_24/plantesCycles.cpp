#include <bits/stdc++.h>
using namespace std;

vector<int> v, ans;

void Floyd(int x){

    vector<bool> vis;

    int a = v[x];
    int b = v[v[x]];

    while (a!=b){
        a = v[a];
        b = v[v[b]];
    } 

    //now where they meet
    a = x;
    while (a!=b){
        a = v[a];
        b = v[b];
    }
    int first = a; //where the cycle starts

    b = v[a]; 
    int length = 1; 
    while (a != b) { 
        b = v[b]; 
        length++;
    } //length = how long the cycle is
    
    a = first;
    b = v[first]; 
    while (a != b) { 
        ans[b] = length;
        b = v[b]; 
    }
    ans[b] = length;
}

void Check(int x){
    stack<int> s;
    s.push(x);

    while (ans[v[s.top()]] == 0){
        s.push(v[s.top()]);
    }
    int length = ans[v[s.top()]];
    while (!s.empty()){
        ans[s.top()] = ++length;
        s.pop();
    }
}

int main (){
    int n; cin>>n;
    v.resize(n);
    ans.resize(n, 0);
    for (int i=0; i<n; i++) {cin>>v[i]; v[i]--;}

    for (int i=0; i<n; i++){
        if (ans[i] == 0) Floyd(i);
        if (ans[i] == 0) Check(i);
        cout<<ans[i]<<" ";
    }
}
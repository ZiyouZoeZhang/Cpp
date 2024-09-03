//this doesn't work

#include <bits/stdc++.h>
using namespace std;

vector<int> v, ans;

void Floyd(int x){ //处理环的
    int a = v[x];
    int b = v[v[x]];

    while (a!=b){
        a = v[a];
        b = v[v[b]];
    } 
    a = x;
    while (a!=b){
        a = v[a];
        b = v[b];
    }

    int first = a; //where the cycle starts

    stack<int> s;

    b = v[a]; 
    int length = 1; 
    while (a != b) { 
        s.push(b);
        b = v[b]; 
        length++;
    } 
    s.push(b);

    while(!s.empty()){
        ans[s.top()] = length;
        s.pop();
    } 
    return;
}

void Check(int x){ //处理不是环的
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
    v.resize(n+5);
    ans.resize(n+5, 0);

    for (int i=0; i<n; i++) {cin>>v[i]; v[i]--;}
    cout<<endl;
    for (int i=0; i<n; i++){
        if (ans[i] == 0) Floyd(i);
        if (ans[i] == 0) Check(i);
        cout<<ans[i]<<" ";
    }
}
//https://www.luogu.com.cn/problem/P3612
//Secret Cow Code S
//wrote during class
#include <bits/stdc++.h>
#define FOR(i, a, b)  for(ll i = (a); i < (b); i++)
#define ll long long
#define pb push_back
using namespace std;
ll num;
string s;

void f(long long pos){
    if (pos<=s.size()){
        cout<<s[pos-1]<<endl;
        return;
    }

    long long i = s.size();
    while (i<pos){
        i *= 2; //总共长度
    } 
    if (pos == i/2 + 1){
        f(i/2); //如果不是正好选过来的那个pos
    } else{
        f(pos - i/2 -1); //如果正好是翻转过来的
    }
}

int main (){
    cin>>s>>num;
    int i = s.length();

    f(num);
    return 0;
}
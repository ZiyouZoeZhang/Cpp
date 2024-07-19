//https://codeforces.com/contest/1841/problem/B

#include <iostream>
using namespace std;
void process();

int main(){
    int t;
    cin>>t;
    for (int i=0; i<t; ++i) process();
}

void process(){
    //从小到大
    int q, begin, end;
    bool small=false;
    cin>>q>>begin;
    cout<<1;
    end=begin;
    for (int i=1; i<q; ++i){
        int qi;
        cin>>qi;
        if(small==false){
            if (qi<end && qi>begin) cout<<0;
            else {
                if(qi<end) small=true;
                end=qi, cout<<1;
            }
        } else {
            if (qi>=end && qi<=begin) end=qi, cout<<1;
            else cout<<0;
        }
    }
    cout<<endl;
}


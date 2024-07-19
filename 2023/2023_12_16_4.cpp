#include<iostream>
#include<vector>
using namespace std;
string s;
int main(){

}

vector<int> append(int a, int b){
    vector<int> v;
    if (s[a]!=s[b]) b--;
    for (int i=0; i<=b-a; i++){
        v.push_back((i*2)+(b-a)%2);
    } 
    return v;
}
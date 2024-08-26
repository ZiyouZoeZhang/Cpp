#include <bits/stdc++.h>
using namespace std;



int main (){
}

vector<int> topsort(){
    vector<int> states();
}

int Floyd(int x){

    vector<int> succ;


    int a = succ[x];
    int b = succ[succ[x]];

    while (a!=b){
        a = succ[a];
        b = succ[succ[b]];
    } 
    //now where they meet

    a = x;
    while (a!=b){
        a = succ[a];
        b = succ[b];
    }

    int first = a; //where the cycle starts

    b = succ[a]; 
    int length = 1; 
    while (a != b) { 
        b = succ[b]; 
        length++;
    } //length = how long the cycle is

    return 0;
}
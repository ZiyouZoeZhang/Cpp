/*
ID: zz415821
TASK: milk2
LANG: C++                 
*/

#include <vector>
#include <iostream>
#include <fstream>
//#include <bits/stdc++.h>
using namespace std;

int main(){
    ofstream fout ("milk2.out");
    ifstream fin ("milk2.in");

    int N, tS, tE;
    fin>>N;
    vector<bool>v(1000001,false);

    for (int i=0; i<N; i++){
        fin>>tS>>tE;
        for (int j=tS; j<tE; j++){
            v[j]=true;
        }
    }

    int mm=0,  nm=0; //max milking, max non milking
    int cmm=0, cnm=0;
    bool start=false;
    for (int i=0; i<v.size(); i++){
        if (v[i]==true) {//yes milked
            start=true;
            cmm++;
            nm=max(cnm, nm);
            cnm=0;
        } else {
            if (start) cnm++;
            mm=max(cmm, mm);
            cmm=0;
        }
    }

    fout<<mm<<" "<<nm<<endl;
    return 0;
}
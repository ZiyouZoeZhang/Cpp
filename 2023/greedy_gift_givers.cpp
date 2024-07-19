/*
ID: zz415821
TASK: gift1
LANG: C++                 
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#define f first
#define s second

using namespace std;

int main() {
    ofstream fout ("gift1.out");
    ifstream fin ("gift1.in");
    int np;
    fin >> np;
    vector<pair<string, long> > ppl;
    for(int i=0; i<np; ++i){
        string name;
        fin>>name;
        ppl.push_back(make_pair(name, 0));
    }
    for (int i=0; i<np; ++i){
        string p;
        long am, ng;
        fin>>p>>am>>ng;
        if (ng==0) continue;
        for (int z=0; z<np; ++z){
            if(ppl[z].f==p){
                ppl[z].s-=(am);
                ppl[z].s+=(am%ng);
                break;
            }
        }
        for(int j=0; j<ng; j++){
            string to;
            fin>>to;
            for (int z=0; z<np; ++z){
                if(ppl[z].f==to){
                    ppl[z].s+=((am-(am%ng))/ng);
                    break;
                }
            }
        }
    }
    for(int i=0; i<np; ++i) fout<<ppl[i].f<<' '<<ppl[i].s<<'\n';
    return 0;
}
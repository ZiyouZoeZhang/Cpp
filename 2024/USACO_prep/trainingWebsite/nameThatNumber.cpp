/*
ID: zz415821
TASK: namenum
LANG: C++                 
*/
#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <unordered_set>
using namespace std;

vector<vector<char>> v={{'2','A','B','C'},{'3','D','E', 'F'},{'4','G','H','I'},{'5','J','K','L'},{'6','M','N','O'},{'7','P','R','S'},{'8','T','U','V'},{'9','W','X','Y'}};
vector<int>perm;
vector<int>ind;
vector<string> names;
unordered_set<string> all_names;

void readFile(){
  string line;
  ifstream myfile ("dict.txt");
  if (myfile.is_open())
  {
    while ( getline (myfile,line) ) all_names.insert(line);
    myfile.close();
  }
}

int main () {
    readFile();

    ofstream fout ("namenum.out");
    ifstream fin ("namenum.in");

    string s;
    fin>>s;
    perm.resize(s.size(), 1);

    for (int i=0; i<s.size(); i++){
        ind.push_back(s[i]-50);
    }

    bool exit = false;

    while (!exit){
        string name;
        for (int i=0; i<s.size(); i++) name+=v[ind[i]][perm[i]];
        //find name
        if (all_names.find(name)!=all_names.end()) names.push_back(name);

        //permutation
        int cur = perm.size()-1;
        perm[perm.size()-1]++;
        while (perm[cur]>3){
            perm[cur]=1;
            if (cur==0) {
                exit=true;
                break;
            }
            cur=cur-1;
            perm[cur]++;
        }
    }
    
    for (int i=0; i<names.size(); i++) fout<<names[i]<<endl;
    if (names.size()==0)  fout<<"NONE"<<endl;
    return 0;
}
/*
ID: zz415821
TASK: beads
LANG: C++                 
*/

#include <vector>
#include <iostream>
#include <fstream>
using namespace std;
vector<pair<char, int>>necklace;
vector<bool>visited;

std::ofstream fout ("beads.out");
std::ifstream fin ("beads.in");

int check_left(int i, int sum, char cur){
    if (i<0) i=necklace.size()-1;
    if ((visited[i]) || (cur!='w' && necklace[i].first!='w' && necklace[i].first!=cur)) return sum;
    visited[i]=true;
    if (cur!='w') return check_left(i-1, sum+necklace[i].second, cur);
    return check_left(i-1, sum+necklace[i].second, necklace[i].first);
}

int check_right(int i, int sum, char cur){
    if (i>necklace.size()-1) i=0;
    if ((visited[i]) || (cur!='w' && necklace[i].first!='w' && necklace[i].first!=cur)) return sum;
    visited[i]=true;
    if (cur!='w') return check_right(i+1, sum+necklace[i].second, cur);
    return check_right(i+1, sum+necklace[i].second, necklace[i].first);
}

int main(){
    int N;
    string s;
    fin>>N>>s;

    //divide into vector
    char c=s[0];
    int n=1;
    for (int i=1; i<N; i++){
        if (s[i]==c) n++;
        else {
            necklace.push_back(make_pair(c, n));
            c=s[i];
            n=1;
        }
    }
    necklace.push_back(make_pair(c, n));

    visited.resize(necklace.size(), false);

    int m=0;
    for (int i=0; i<necklace.size(); i++){
        fill(visited.begin(),visited.end(), false);
        int sum = check_left(i-1,0,'w')+check_right(i,0,'w');
        //cout<<i<<"   "<<check_left(i-1,0,'w')<<"  "<<check_right(i,0,'w')<<"    "<<sum<<endl;
        m=max(sum, m);
    }
    fout<<m<<endl;
    return 0;
}
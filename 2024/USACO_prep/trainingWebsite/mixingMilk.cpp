#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;

bool comp(pair<int, int>a, pair<int, int>b){

}

int main (){
    int N, M, total=0;
    cin>>N>>M;
    vector<pair <int, int>> v;
    int total=0;
    while ( M-- > 0) {
        int p, m;
        cin>>p>>m;
        v.push_back(make_pair(p, m));
    }
    sort (v.begin(), v.end(), comp);

}
//USACO 2023 January Contest, Silver
//Problem 1. Find and Replace
//http://www.usaco.org/index.php?page=viewproblem2&cpid=1278

#include <iostream>
#include <map>
#include <set>
#include <stdio.h>
#include <deque>
#include <vector>
#define PRESENTinPAIRS(a) pairs.find(a) != pairs.end()
using namespace std;
bool check(deque<char> dq, map<char, vector<char> >rpairs);

int cal(){
    map<char, char>pairs;
    map<char, vector<char> >rpairs;
    pairs.clear();
    string s1, s2;
    cin>>s1>>s2;
    set<char> s1_set(s1.begin(), s1.end());
    set<char> s2_set(s2.begin(), s2.end());
    if (s1==s2) return 0;
    if (s1.size()!=s1.size() || (s1_set.size()==52 && s2_set.size()==52)) return -1;
    for (int i=0; i<s1.size(); i++){
        if (PRESENTinPAIRS(s1[i]) && pairs[s1[i]]!=s2[i]) return -1;
        pairs[s1[i]]=s2[i];
        if (find(rpairs[s2[i]].begin(), rpairs[s2[i]].end(), s1[i])==rpairs[s2[i]].end()) rpairs[s2[i]].push_back(s1[i]);
    }
    int sol=0;
    map<char, char>::iterator it;
    for (it = pairs.begin(); it!=pairs.end(); it++){
        deque<char> dq;
        dq.push_back(it->first);
        char temp=it->second;
        while ( PRESENTinPAIRS(pairs[temp]) && pairs[temp]!=temp){
            if (pairs[temp]==it->first ){
                if (check(dq, rpairs)==0) sol+=1;
                pairs[it->first]=' ';
                break;
            } else {
                dq.push_back(temp);
                temp=pairs[temp];
            }
        }
    }
    map<char, char>::iterator ti;
    for (ti = pairs.begin(); ti!=pairs.end(); ti++){
        if (ti->first!=ti->second && ti->second!='\0' ) sol+=1;
    }
    return sol;
}

bool check(deque<char> dq, map<char, vector<char> >rpairs){
    while (!dq.empty()){
        if (rpairs[dq.front()].size()>1) {
            for (int i=0; i<rpairs[dq.front()].size(); ++i){
                if (find(dq.begin(), dq.end(), rpairs[dq.front()][i])==dq.end()) return 1;
            }
        }
        dq.pop_front();
    }
    return 0;
}

int main(){
    freopen("13.in","r",stdin);
    int n;
    cin>>n;
    for (int i=0; i<n; ++i) cout<<cal()<<endl;
    return 0;
}
//USACO 2023 US Open Contest, Silver
//Problem 1. Milk Sum
// http://www.usaco.org/index.php?page=viewproblem2&cpid=1326

#include <iostream>
#include <array>
#include <vector>
#include <algorithm>
using namespace std;
int cal(long long old_place, long long new_num);
vector <long long> original;
vector <long long> ordered;
vector <long long> total;
long long everything = 0;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    long long totaln=0;
    long long n, number, actions; 
    total.push_back(0);
    cin>>n;
    for (long long i=0; i<n; i++){
        cin>>number;
        original.push_back(number);
        ordered.push_back(number);
    }
    sort(ordered.begin(), ordered.end());
    for(long long i=0; i<ordered.size(); i++){
        totaln+=ordered[i];
        total.push_back(totaln);
        everything+=((i+1)*ordered[i]);
    }
    cout<<"done"<<endl;
    cin>>actions;
    for (int i=0; i<actions; i++) {
        long long s, j;
        cin>>s>>j;
        cout<<cal(original[s-1],j)<<endl;
    }
}

int cal(long long old_num, long long new_num){
    long long old_place = ((lower_bound(ordered.begin(), ordered.end(), old_num)- ordered.begin()));
    if (new_num<old_num){
        long long new_place = (lower_bound(ordered.begin(), ordered.end(), new_num) -(ordered.begin()));
        return everything+(total[old_place]-total[new_place])-(old_num*(old_place+1))+(new_num*(new_place+1));
    } else {
        long long new_place = (upper_bound(ordered.begin(), ordered.end(), new_num)-(ordered.begin()))-1;
        return everything+(total[old_place+1]-total[new_place+1])-(old_num*(old_place+1))+(new_num*(new_place+1));
    }
}
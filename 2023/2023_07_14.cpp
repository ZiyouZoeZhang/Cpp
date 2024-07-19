#include <iostream>
#include <vector>
#define ll long long
using namespace std;
vector<pair<ll, ll> >grass;
vector<ll> cows;
vector<ll> ans;
ll G, C, N;

int main(){
    cin>>G>>C>>N;
    for (int i=0; i<G; ++i){
        ll pi, ti;
        cin>>pi>>ti;
        grass.push_back(make_pair(pi, ti));
    }
    for (int i=0; i<C; ++i){
        ll cow;
        cin>>cow;
        cows.push_back(cow);
    }
    //input read

    //第一个cow
    ll Gi, Ci; //no matter what, they keep track of where we are.
    //we will be processing the beginnig and end seperately
    //for the center part we will be going through the cows vector
    //pseudocode
    /*
    for things that are before the first cow - while Ki++<cow[0], sum them up and push_back to the ans vector
    loop through the cow vector as for(int i=1, i<cows.size(); ++i){
        keep track of the length, meaning float length = (cow[i]-cow[i-1]) / 2
        keep track of the entire sum, we will need it later - entire_sum;

    }
    
    
    
    */
}
//https://cses.fi/problemset/task/1653
#include <bits/stdc++.h>
#define FOR(i, a, b)  for(int i = (a); i < (b); i++)
#define ll long long
//#define f first
//#define s second
#define pb push_back
#define INF 0x3f3f3f3f;
using namespace std;

int N, X;
vector<int> v;
//vector<int> dp;//dp[subset] = how many times
vector<pair<int, int>> best;

int main(){
    cin>>N>>X;

    v.resize(N); 

    FOR(i, 0, N){
        cin>>v[i];
    }
    best.resize(1<<N);

    best[0] = {1, 0};

    for(int s = 1; s < (1<<N); s++){
        best[s] = {N+1, 0};

        FOR(p, 0, N){
            if(s&(1<<p)){
                auto option  = best[s^(1<<p)];
                if (option.second + v[p] <= X){
                    option.second += v[p];
                } else {
                    option.first ++;
                    option.second = v[p];
                }
                best[s] = min(best[s], option);
            }
            
        }
    }
    cout<<best[(1<<N)-1].first<<endl;

    //cout<<best[(1<<N)-1].first<<"  "<<best[N-1].second<<endl;

    //final goal rides 0...n-1

}

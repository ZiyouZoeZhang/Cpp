//USACO 2023 February Contest, Bronze
//Problem 3. Watching Mooloo
//http://www.usaco.org/index.php?page=viewproblem2&cpid=1301
#include<iostream>
#include<vector>
#define ll long long
using namespace std;

int main(){
    ll N, K, cost=0;
    cin>>N>>K;
    vector<ll>day(N);
    for (ll i=0; i<N; i++) cin>>day[i];
    cost+=K+1;
    ll lastday=day[0];
    for (ll i=1; i<N; i++){
        cost+=min(K+1, day[i]-day[i-1]);
        if ((K+1)<=day[i]-day[i-1]){
            lastday=day[i];
        }
    }
    cout<<cost;
}